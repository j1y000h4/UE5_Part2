// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ABPlayerController.h"
#include "UI/ABHUDWidget.h"

AABPlayerController::AABPlayerController()
{
	// Ŭ���� ������ �ҷ� ����
	static ConstructorHelpers::FClassFinder<UABHUDWidget> ABHUDWidgetRef(TEXT("/Game/ArenaBattle/UI/WBP_ABHUD.WBP_ABHUD_C"));
	if (ABHUDWidgetRef.Class)
	{
		ABHUDWidgetClass = ABHUDWidgetRef.Class;
	}
}

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();		// override�� ��� Super ���̱�

	FInputModeGameOnly GameOnlyInputMode;		// ����ü ����
	SetInputMode(GameOnlyInputMode);			// ����ü �ѱ�� (�������ڸ��� ��Ŀ���� �� ��Ʈ ������ ���� �ȴ�.)

	// ������ ���۵Ǹ� ������ ����
	ABHUDWidget = CreateWidget<UABHUDWidget>(this, ABHUDWidgetClass);
	if (ABHUDWidget)
	{
		ABHUDWidget->AddToViewport();
	}
}