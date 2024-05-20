// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
#include "ABGameMode.h"

AABGameMode::AABGameMode()
{
	//static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));		// Ŭ�������� ���ؼ��� Copy Reference�� ����� �����ּ��� ''�� ������ �ְ� ��θ� �Է����ְ�, Ŭ���� ������ ������ ���̱� ������ _C�� �ٿ� �ش�.

	//if (ThirdPersonClassRef.Class)
	//{
	//	DefaultPawnClass = ThirdPersonClassRef.Class;
	//}
	// DefaultPawnClass

	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/Engine.Blueprint'/Game/ArenaBattle/Blueprint/BP_ABCharacterPlayer.BP_ABCharacterPlayer_C'"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerRef(TEXT("/Script/ArenaBattle.ABPlayerController"));		// ���� �����ϰ� ����. �� ��� �⺻���� Ŭ���� ������ ������ ���̱� ������ _C�� ������ �ʾƵ� �ȴ�.

	if (PlayerControllerRef.Class)
	{
		PlayerControllerClass = PlayerControllerRef.Class;		// �� ��� �������κ��� ���� ������ �ޱ� ������ ��� ������ �������� ���� �� �ִ�.
	}
}