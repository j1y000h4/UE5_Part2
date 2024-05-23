// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugManager.h"
#include "Fonts/SlateFontInfo.h"

UDebugManager* UDebugManager::SingletonInstance = nullptr;
UDebugManager* UDebugManager::Instance()
{
	if (!SingletonInstance)
	{
		SingletonInstance = NewObject<UDebugManager>();
		SingletonInstance->AddToRoot();

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Create DebugManager instance"));
		UE_LOG(LogTemp, Warning, TEXT("Create DebugManager instance"));
	}

	return SingletonInstance;
}

void UDebugManager::Shutdown()
{
	if (SingletonInstance)
	{
		LogAddEventInstance.Clear();
		SingletonInstance->RemoveFromRoot();
		SingletonInstance = nullptr;

		UE_LOG(LogTemp, Warning, TEXT("%s > Remove DebugManager instance"), *GetName());
	}
}

void UDebugManager::AddLog(FString NewLogEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("%s > %s"), *GetName(), *NewLogEntry);
	LogAddEventInstance.Broadcast(NewLogEntry);
}

void UDebugManager::AddLog(int32 NewLogEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("%s > %i"), *GetName(), NewLogEntry);
	LogAddEventInstance.Broadcast(FString::FromInt(NewLogEntry));
}

void UDebugManager::AddLog(float NewLogEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("%s > %f"), *GetName(), NewLogEntry);
	LogAddEventInstance.Broadcast(FString::SanitizeFloat(NewLogEntry));
}

