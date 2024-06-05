// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
//#include "ABGameMode.h"
#include "Player/ABPlayerController.h"

AABGameMode::AABGameMode()
{
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

	ClearScrore = 3;

	// CurrentScore�� ��� ������ �Ը� ���� �� Ŀ���ٸ� PlayerState���� ��ü�� �����ϴ� ���� ����.
	CurrentScore = 0;
	bIsCleared = false;
}

// �÷��̾��� ���� ������ ����Ǿ��� ��
void AABGameMode::OnPlayerScoreChanged(int32 NewPlayerScore)
{
	CurrentScore = NewPlayerScore;

	// ���ھ ������ �� ��ȣ�� �����ֱ� ����
	// 1�� �÷��̱� ������ FirstPlayerController�� �����͵� �ȴ�.
	AABPlayerController* ABPlayerController = Cast<AABPlayerController>(GetWorld()->GetFirstPlayerController());
	if (ABPlayerController)
	{
		ABPlayerController->GameScoreChanged(CurrentScore);
	}

	// ������ Ŭ�������� ��
	if (CurrentScore >= ClearScrore)
	{
		bIsCleared = true;

		if (ABPlayerController)
		{
			ABPlayerController->GameClear();
		}
	}
}

// �÷��̾ �׾��� ��
void AABGameMode::OnPlayerDead()
{
	// �÷��̾ �׾��� �� ���õ� UI�� ������ �̺�Ʈ�� PlayerController���� �˷��ֱ� ����
	AABPlayerController* ABPlayerController = Cast<AABPlayerController>(GetWorld()->GetFirstPlayerController());
	if (ABPlayerController)
	{
		ABPlayerController->GameOver();
	}
}

// ���� ������ Ŭ���� �Ͽ��°�?
bool AABGameMode::IsGameCleared()
{
	return bIsCleared;
}
