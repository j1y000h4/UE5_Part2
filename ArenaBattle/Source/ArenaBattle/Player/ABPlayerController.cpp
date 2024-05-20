// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ABPlayerController.h"

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();		// override의 경우 Super 붙이기

	FInputModeGameOnly GameOnlyInputMode;		// 구조체 선언
	SetInputMode(GameOnlyInputMode);			// 구조체 넘기기 (시작하자마자 포커스가 뷰 포트 안으로 들어가게 된다.)
}
