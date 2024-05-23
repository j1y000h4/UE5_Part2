// Fill out your copyright notice in the Description page of Project Settings.

#include "ConfigManager.h"
#include "ConfigData.h"
#include "DebugManager.h"
#include "DisplayCluster/Public/IDisplayCluster.h"
#include "HAL/PlatformFilemanager.h"
#include "JsonObjectConverter.h"
#include "Misc/FileHelper.h"
#include "SettingUI.h"
#include "Kismet/GameplayStatics.h"

FConfigData AConfigManager::ConfigData;

AConfigManager::AConfigManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AConfigManager::PostInitializeComponents()
{
    Super::PostInitializeComponents();

#if WITH_EDITOR
	JsonFilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir().Append(TEXT("Data/Config.json")));
#else
    if (IDisplayCluster::Get().GetOperationMode() == EDisplayClusterOperationMode::Cluster)
    {
        JsonFilePath = FPaths::Combine(FPlatformProcess::BaseDir(), TEXT("Data/Config.json"));
        JsonFilePath = FPaths::ConvertRelativePathToFull(JsonFilePath);
        
        UDebugManager::Instance()->AddLog("nDisplay is available.");
    }
    else
    {
        JsonFilePath = FPaths::ConvertRelativePathToFull(FPaths::RootDir().Append(TEXT("Data/Config.json")));
    }
#endif
    
    UDebugManager::Instance()->AddLog(JsonFilePath);

    if (IFileManager::Get().FileExists(*JsonFilePath))
    {
        ProcessExistingJsonFile();
    }
    else
    {
        CreateDefaultJsonFile();
    }
    
    SettingUI = Cast<ASettingUI>(UGameplayStatics::GetActorOfClass(GetWorld(), ASettingUI::StaticClass()));
    if (SettingUI)
    {
        SettingUI->Init(this);
    }
}

// Called every frame
void AConfigManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AConfigManager::ProcessExistingJsonFile()
{
    FString JsonString;

    if (LoadJsonFileToString(JsonFilePath, JsonString))
    {        
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            TArray<FProperty*> Properties = GetAllConfigProperties();
            bool bShouldUpdate = false;

            // JSON 파일에서 키의 개수 확인
            int32 JsonKeyCount = JsonObject->Values.Num();
            int32 StructPropertyCount = Properties.Num();

            if (JsonKeyCount != StructPropertyCount)
            {
                bShouldUpdate = true;  // 키의 개수가 다르면 업데이트 필요
            }

            for (FProperty* Property : Properties)
            {
                FString PropertyName = Property->GetNameCPP();
                TSharedPtr<FJsonValue> JsonValuePtr = JsonObject->TryGetField(PropertyName);

                if (!JsonValuePtr || !IsJsonValueTypeMatchesPropertyType(JsonValuePtr.Get(), Property))
                {
                    bShouldUpdate = true;
                    break;
                }
            }

            ConfigData = ParseJsonStringToStruct(JsonString);

            if (bShouldUpdate)
            {
                if (SaveStructToJsonFile(JsonFilePath, ConfigData))
                {
                    UDebugManager::Instance()->AddLog("Config data updated.");
                }
                else
                {
                    UDebugManager::Instance()->AddLog("Failed to save updated config data.");
                }
            }
        }
    }
    else
	{
        UDebugManager::Instance()->AddLog("Could not load JSON file.");
	}
}

void AConfigManager::CreateDefaultJsonFile()
{
    FConfigData DefaultData;
    if (SaveStructToJsonFile(JsonFilePath, DefaultData))
    {
        ConfigData = DefaultData;
        UDebugManager::Instance()->AddLog("Default ConfigData saved.");
    }
    else
    {
        UDebugManager::Instance()->AddLog("Failed to save default ConfigData.");
    }
}

TArray<FProperty*> AConfigManager::GetAllConfigProperties()
{
    TArray<FProperty*> ResultProperties;

    for (TFieldIterator<FProperty> PropIt(FConfigData::StaticStruct()); PropIt; ++PropIt)
    {
        FProperty* Property = *PropIt;
        ResultProperties.Add(Property);
    }

    return ResultProperties;
}

bool AConfigManager::ReadFromJsonFile(const FString& FilePath, TSharedPtr<FJsonObject>& JsonObject)
{
	FString JsonString;

    if (FFileHelper::LoadFileToString(JsonString, *FilePath))
    {
        TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);

        if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
        {
            return true;
        }
    }

    return false;
}

bool AConfigManager::WriteToJsonFile(const FString& FilePath, TSharedPtr<FJsonObject>& JsonObject)
{
    FString OutputString;
    TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
    if (FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter))
    {
        return FFileHelper::SaveStringToFile(OutputString, *FilePath);
    }

    return false;
}

bool AConfigManager::LoadJsonFileToString(const FString& FilePath, FString& OutJsonString)
{
    return FFileHelper::LoadFileToString(OutJsonString, *FilePath);
}

bool AConfigManager::SaveStructToJsonFile(const FString& FilePath, const FConfigData& Data)
{
    FString JsonString;
    if (FJsonObjectConverter::UStructToJsonObjectString(FConfigData::StaticStruct(), &Data, JsonString))
    {
        return FFileHelper::SaveStringToFile(JsonString, *FilePath);
    }
    return false;
}

bool AConfigManager::IsJsonValueTypeMatchesPropertyType(FJsonValue* JsonValue, FProperty* Property)
{
    switch (JsonValue->Type)
    {
    case EJson::String:
        return Property->IsA<FStrProperty>();
    case EJson::Number:
        return Property->IsA<FIntProperty>() || Property->IsA<FFloatProperty>();
    case EJson::Boolean:
        return Property->IsA<FBoolProperty>();
    case EJson::Object:
        return Property->IsA<FStructProperty>();
    case EJson::Array:
        return Property->IsA<FArrayProperty>();
    default:
        return false;
    }
}

bool AConfigManager::GetNumberOfTopLevelKeysInJson(const FString& JsonString, int32& OutKeyCount)
{
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

    if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
    {
        OutKeyCount = JsonObject->Values.Num();
        return true;
    }

    OutKeyCount = 0;
    return false;
}

int32 AConfigManager::GetNumberOfPropertiesInStruct(UScriptStruct* Struct)
{
    if (!Struct)
    {
        return 0;
    }

    int32 PropertyCount = 0;

    for (TFieldIterator<FProperty> PropIt(Struct); PropIt; ++PropIt)
    {
        ++PropertyCount;
    }

    return PropertyCount;
}

FConfigData AConfigManager::ParseJsonStringToStruct(const FString& JsonString)
{
    FConfigData ParsedData;
    
    if (FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &ParsedData))
    {
        return ParsedData;
    }
    else
    {
        return FConfigData();
    }
}

FString AConfigManager::GetJsonString()
{
    FString JsonString;
    if (FJsonObjectConverter::UStructToJsonObjectString(FConfigData::StaticStruct(), &ConfigData, JsonString))
    {
        return JsonString;
    }
    else
    {
        return FString();
    }
}

bool AConfigManager::UpdateConfigData()
{
    if (SaveStructToJsonFile(JsonFilePath, ConfigData))
    {
        UDebugManager::Instance()->AddLog("Config data updated.");
        return true;
    }
    else
    {
        UDebugManager::Instance()->AddLog("Failed to update ConfigData.");
        return false;
    }
}

bool AConfigManager::SetConfigData(const FString& JsonString)
{
    if (FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &ConfigData, 0, 0))
    {
        if (UpdateConfigData())
        {
            SettingUI->GenerateDynamicUI();
            return true;
        }
    }
    else
    {
        UDebugManager::Instance()->AddLog("Failed to set ConfigData.");
        return false;
    }
    return false;
}

FConfigData AConfigManager::GetConfigData()
{
    return ConfigData;
}