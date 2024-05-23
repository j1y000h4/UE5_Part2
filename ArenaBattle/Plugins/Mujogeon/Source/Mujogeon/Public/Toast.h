// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Toast.generated.h"

UCLASS()
class MUJOGEON_API UToast : public UObject
{
	GENERATED_BODY()
public:
	UToast();
	virtual ~UToast() override;
	
	UFUNCTION(BlueprintCallable, Category = "Toast")
	static UToast* GetInstance();
	UFUNCTION(BlueprintCallable, Category = "Toast")
	static void Bake(const FString& Message);

private:
	static UToast* Instance;
	static UWorld* World;

	UPROPERTY()	
	TSubclassOf<UUserWidget> ToastScreenClass;
	UPROPERTY()
	UUserWidget* Screen;
	UPROPERTY()
	UImage* ToastImage;
	UPROPERTY()
	UTextBlock* ToastText;

	FTimerHandle ShowTimerHandle;

	static void InitializeScreen();
};
