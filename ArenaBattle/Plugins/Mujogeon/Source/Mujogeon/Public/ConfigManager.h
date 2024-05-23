// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Dom/JsonObject.h"
#include "CoreMinimal.h"
#include "ConfigData.h"
#include "GameFramework/Actor.h"
#include "ConfigManager.generated.h"

class ASettingUI;

// USTRUCT(BlueprintType)
// struct FConfigData
// {
// 	GENERATED_USTRUCT_BODY()
//
// 	UPROPERTY(BlueprintReadOnly, Category = "Config")
// 	int32 SampleInt = 1027;
// 	UPROPERTY(BlueprintReadOnly, Category = "Config")
// 	float SampleFloat = 1.45f;
// 	UPROPERTY(BlueprintReadOnly, Category = "Config")
// 	bool SampleBool = false;
// 	UPROPERTY()
// 	FString SampleString = "Hello Setting UI";
// 	UPROPERTY()
// 	FVector2D SampleVector2D = FVector2D(1.1f, 2.2f);
// 	UPROPERTY()
// 	FVector SampleVector = FVector(1.1f, 2.2f, 3.3f);
// 	UPROPERTY()
// 	FVector4 SampleVector4 = FVector4(1.1f, 2.2f, 3.3f, 4.4f);
// };

UCLASS()
class MUJOGEON_API AConfigManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConfigManager();

protected:
	// Called when the game starts or when spawned
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	static FConfigData ConfigData;
	UFUNCTION(BlueprintCallable, Category = "Config")
	static FConfigData GetConfigData();

	TArray<FProperty*> GetAllConfigProperties();

	bool ReadFromJsonFile(const FString& FilePath, TSharedPtr<FJsonObject>& JsonObject);
	bool WriteToJsonFile(const FString& FilePath, TSharedPtr<FJsonObject>& JsonObject);

	bool UpdateConfigData();
	bool SetConfigData(const FString& JsonString);
	
	FString GetJsonString();

	UPROPERTY()
	ASettingUI* SettingUI;

private:
	FString JsonFilePath;
	
	void ProcessExistingJsonFile();
	void CreateDefaultJsonFile();

	bool LoadJsonFileToString(const FString& FilePath, FString& OutJsonString);
	bool SaveStructToJsonFile(const FString& FilePath, const FConfigData& Data);
	bool IsJsonValueTypeMatchesPropertyType(FJsonValue* JsonValue, FProperty* Property);
	bool GetNumberOfTopLevelKeysInJson(const FString& JsonString, int32& OutKeyCount);
	
	int32 GetNumberOfPropertiesInStruct(UScriptStruct* Struct);
	FConfigData ParseJsonStringToStruct(const FString& JsonString);
};
