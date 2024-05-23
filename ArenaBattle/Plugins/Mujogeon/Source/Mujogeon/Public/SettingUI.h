// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Components/EditableText.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"

#include "CoreMinimal.h"
#include "ConfigManager.h"
#include "GameFramework/Actor.h"
#include "SettingUI.generated.h"

UCLASS()
class MUJOGEON_API ASettingUI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASettingUI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Init(AConfigManager* Config);
	UFUNCTION()
	void SaveConfigData();
	void GenerateDynamicUI();

	UFUNCTION(BlueprintCallable, Category = "SettingUI")
	void UpdateConfigData(FString JsonString);

	// DECLARE_EVENT(ASettingUI, SettingUISaveConfig)
	// SettingUISaveConfig OnSettingUISaveConfig;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSettingUISaveConfigBlueprint);
	UPROPERTY(BlueprintAssignable)
	FSettingUISaveConfigBlueprint OnSettingUISaveConfig;
	
	// nDisplay 용 델리게이트
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSettingUISaveConfig, FString, JsonString);
	UPROPERTY(BlueprintAssignable)
	FSettingUISaveConfig OnSettingUISaveConfig_nDisplay;

private:	
	UPROPERTY(EditAnywhere, Category = "SettingUI")	
	TSubclassOf<UUserWidget> ScreenClass;
	UPROPERTY() 
	UUserWidget* Screen;
	UPROPERTY()
	UTextBlock* TitleText;
	UPROPERTY()
	UScrollBox* ScrollBox;
	UPROPERTY()
	UButton* SaveButton;

	UPROPERTY()
	APlayerController *PlayerController;
	UPROPERTY()
	AConfigManager* ConfigManager;

	UPROPERTY()
	TArray<UEditableText*> EditableTextArray;
	UPROPERTY()
	TMap<FString, UCheckBox*> CheckBoxMap;
	
	bool IsActivated;
	void WidgetActivate();
	
	FString FormatFloatWithDynamicPrecision(FString Value, bool KeepOneDecimalIfZero = true);
};
