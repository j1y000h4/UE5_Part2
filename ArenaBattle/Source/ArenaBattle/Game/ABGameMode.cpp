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

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerRef(TEXT("/Script/ArenaBattle.ABPlayerController"));		// 위와 동일하게 적용. 이 경우 기본으로 클래스 정보가 복제된 것이기 때문에 _C를 붙이지 않아도 된다.

	if (PlayerControllerRef.Class)
	{
		PlayerControllerClass = PlayerControllerRef.Class;		// 이 경우 에셋으로부터 직접 참조를 받기 때문에 헤더 파일의 의존성을 줄일 수 있다.
	}

	ClearScrore = 3;

	// CurrentScore의 경우 게임의 규모가 조금 더 커진다면 PlayerState같은 객체에 보관하는 것이 좋다.
	CurrentScore = 0;
	bIsCleared = false;
}

// 플레이어의 현재 점수가 변경되었을 때
void AABGameMode::OnPlayerScoreChanged(int32 NewPlayerScore)
{
	CurrentScore = NewPlayerScore;

	// 스코어가 변했을 때 신호를 날려주기 위한
	// 1인 플레이기 때문에 FirstPlayerController를 가져와도 된다.
	AABPlayerController* ABPlayerController = Cast<AABPlayerController>(GetWorld()->GetFirstPlayerController());
	if (ABPlayerController)
	{
		ABPlayerController->GameScoreChanged(CurrentScore);
	}

	// 게임을 클리어했을 때
	if (CurrentScore >= ClearScrore)
	{
		bIsCleared = true;

		if (ABPlayerController)
		{
			ABPlayerController->GameClear();
		}
	}
}

// 플레이어가 죽었을 때
void AABGameMode::OnPlayerDead()
{
	// 플레이어가 죽었을 때 관련된 UI를 날리는 이벤트를 PlayerController에게 알려주기 위한
	AABPlayerController* ABPlayerController = Cast<AABPlayerController>(GetWorld()->GetFirstPlayerController());
	if (ABPlayerController)
	{
		ABPlayerController->GameOver();
	}
}

// 현재 게임을 클리어 하였는가?
bool AABGameMode::IsGameCleared()
{
	return bIsCleared;
}
