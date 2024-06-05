// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ABPlayerController.h"
#include "UI/ABHUDWidget.h"
#include "Kismet/GameplayStatics.h"
#include "ABSaveGame.h"

//DEFINE_LOG_CATEGORY(LogABPlayerController);

AABPlayerController::AABPlayerController()
{
	// Ŭ���� ������ �ҷ� ����
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

	// ������ ������ �����ϱ�
	/*if (!UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Player0"), 0))
	{
		UE_LOG(LogABPlayerController, Error, TEXT("Save Game Error!"));
	}

	K2_OnGameRetryCount(SaveGameInstance->RetryCount);*/
}

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();		// override�� ��� Super ���̱�

	FInputModeGameOnly GameOnlyInputMode;		// ����ü ����
	SetInputMode(GameOnlyInputMode);			// ����ü �ѱ�� (�������ڸ��� ��Ŀ���� �� ��Ʈ ������ ���� �ȴ�.)

	// BP���� �ۼ�
	//// ������ ���۵Ǹ� ������ ����
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