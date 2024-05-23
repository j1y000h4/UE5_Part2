// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DebugHUD.generated.h"

/**
 * 
 */
UCLASS()
class MUJOGEON_API ADebugHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	virtual void Tick(float DeltaTime) override;
	virtual void DrawHUD() override;

	TArray<FString> DebugLogs;
	
	UPROPERTY(BlueprintReadWrite, Category = "Debug")
	bool bIsOverlayActive = false;

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void HandleMouseWheelScroll(float ScrollDirection);

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void SetHUDActive(bool bActive);

private:
	float ScrollOffset = 0.0f;
	float MaxScrollOffset = 0.0f;
	
	bool bNeedToUpdateScrollOffset = false;

	UPROPERTY()
	UFont* LoadedFont;
	
	void AddLogEventHandler(FString Log);
};
