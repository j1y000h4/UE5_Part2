// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogABPlayerController, Log, All);

UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AABPlayerController();

	// 모든 UI를 C++로 처리하기에는 한계가 있다. 블루프린트로 처리하기 위한
	// 블루프린트에서 어떤 이벤트를 발동시키는 것처럼 기능을 수행하기 위한 키워드 (BlueprintImplementableEvent)
	// UFUNCTION 매크로를 가지고 자동으로 이벤트를 감지 
	UFUNCTION(BlueprintImplementableEvent, Category = Game, Meta = (DisplayName = "OnScoreChangedCpp"))
	void K2_OnScoreChanged(int32 NewScore);
	UFUNCTION(BlueprintImplementableEvent, Category = Game, Meta = (DisplayName = "OnGameClearCpp"))
	void K2_OnGameClear();
	UFUNCTION(BlueprintImplementableEvent, Category = Game, Meta = (DisplayName = "OnGameOverCpp"))
	void K2_OnGameOver();
	UFUNCTION(BlueprintImplementableEvent, Category = Game, Meta = (DisplayName = "OnGameRetryCountCpp"))
	void K2_OnGameRetryCount(int32 NewRetryCount);

	// GameMode가 사용할 함수들
	void GameScoreChanged(int32 NewScore);
	void GameClear();
	void GameOver();
	
protected:
	virtual void BeginPlay() override;

	// HUD Section
protected:
	// 클래스 정보 변수 선언, 위젯을 생성할 때 클래스 정보를 넘겨야한다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = HUD)
	TSubclassOf<class UABHUDWidget> ABHUDWidgetClass;

	// 생성한 위젯의 포인터를 담을 변수 선언
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HUD)
	TObjectPtr<class UABHUDWidget> ABHUDWidget;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SaveGame)
	TObjectPtr<class UABSaveGame> SaveGameInstance;
};
