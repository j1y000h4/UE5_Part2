// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugViewer.generated.h"

UCLASS()
class MUJOGEON_API ADebugViewer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADebugViewer();

protected:
	// Called when the game starts or when spawned
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "DebugViewer")	
	TSubclassOf<UUserWidget> LogScreenClass;
	UPROPERTY(EditAnywhere, Category = "DebugViewer")
	int32 FontSize = 20;
	UPROPERTY(EditAnywhere, Category = "DebugViewer")
	int32 MaxLogCount = 100;
	UPROPERTY(EditAnywhere, Category = "DebugViewer")
	bool IsShowOutputLog = true;

	UPROPERTY()
	UUserWidget* LogScreen;
	UPROPERTY()
	UScrollBox* ScrollBox;

	UPROPERTY()
	TArray<UTextBlock*> TextBlockArray;
	UPROPERTY()
	APlayerController *PlayerController;

	int32 CurrentLogIndex;
	bool IsActivated;

	TArray<FString> LogBuffer; // 로그 버퍼
	FTimerHandle LogFlushTimer; // 로그 업데이트 타이머
	float LogFlushInterval = 0.5f; // 로그를 업데이트하는 간격 (초)
	
	void LogWidgetActivate();
	void LogAddEventHandler(FString Log);
	void AddLogAsync(FString Log);

	void AddLogToBuffer(const FString& Log);
	void FlushLogBuffer();
};
