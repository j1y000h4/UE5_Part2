// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ABPlayerController.h"

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();		// override�� ��� Super ���̱�

	FInputModeGameOnly GameOnlyInputMode;		// ����ü ����
	SetInputMode(GameOnlyInputMode);			// ����ü �ѱ�� (�������ڸ��� ��Ŀ���� �� ��Ʈ ������ ���� �ȴ�.)
}
