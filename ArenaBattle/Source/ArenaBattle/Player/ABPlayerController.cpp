// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ABPlayerController.h"
#include "UI/ABHUDWidget.h"
#include "Kismet/GameplayStatics.h"
#include "ABSaveGame.h"

//DEFINE_LOG_CATEGORY(LogABPlayerController);

AABPlayerController::AABPlayerController()
{
	// 클래스 정보를 불러 저장
	/*static ConstructorHelpers::FClassFinder<UABHUDWidget> ABHUDWidgetRef(TEXT("/Game/ArenaBattle/UI/WBP_ABHUD.WBP_ABHUD_C"));
	if (ABHUDWidgetRef.Class)
	{
		ABHUDWidgetClass = ABHUDWidgetRef.Class;
	}*/
}

void AABPlayerController::GameScoreChanged(int32 NewScore)
{
	//K2_OnScoreChanged(NewScore);
}

void AABPlayerController::GameClear()
{
	//K2_OnGameClear();
}

void AABPlayerController::GameOver()
{
	//K2_OnGameOver();

	// 게임이 끝나면 저장하기
	/*if (!UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Player0"), 0))
	{
		UE_LOG(LogABPlayerController, Error, TEXT("Save Game Error!"));
	}

	K2_OnGameRetryCount(SaveGameInstance->RetryCount);*/
}

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();		// override의 경우 Super 붙이기

	FInputModeGameOnly GameOnlyInputMode;		// 구조체 선언
	SetInputMode(GameOnlyInputMode);			// 구조체 넘기기 (시작하자마자 포커스가 뷰 포트 안으로 들어가게 된다.)

	// BP에서 작성
	//// 게임이 시작되면 위젯을 생성
	//ABHUDWidget = CreateWidget<UABHUDWidget>(this, ABHUDWidgetClass);
	//if (ABHUDWidget)
	//{
	//	ABHUDWidget->AddToViewport();
	//}

	/*SaveGameInstance = Cast<UABSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Player0"), 0));
	if (SaveGameInstance)
	{
		SaveGameInstance->RetryCount++;
	}
	else
	{
		SaveGameInstance = NewObject<UABSaveGame>();
	}

	K2_OnGameRetryCount(SaveGameInstance->RetryCount);*/
}