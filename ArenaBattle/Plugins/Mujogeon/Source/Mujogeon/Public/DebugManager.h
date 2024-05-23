// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DebugManager.generated.h"

/**
 * 
 */
UCLASS()
class MUJOGEON_API UDebugManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Debug")
	static UDebugManager* Instance();

	DECLARE_EVENT_OneParam(UDebugManager, LogAddEvent, FString)
	LogAddEvent LogAddEventInstance;

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void AddLog(FString NewLogEntry);
	void AddLog(int32 NewLogEntry);
	void AddLog(float NewLogEntry);
	void Shutdown();

private:
	static UDebugManager* SingletonInstance;
};
