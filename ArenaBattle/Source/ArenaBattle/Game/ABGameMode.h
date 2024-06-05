// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interface/ABGameInterface.h"
#include "ABGameMode.generated.h"

UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase, public IABGameInterface
{
	GENERATED_BODY()
	
public:
	AABGameMode();

	virtual void OnPlayerScoreChanged(int32 NewPlayerScore) override;
	virtual void OnPlayerDead() override;
	virtual bool IsGameCleared() override;
	
	// 게임을 클리어하기 위한 조건을 위한 점수
	// 현재 진행되고 있는 게임의 점수
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = Game)
	int32 ClearScrore;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Game)
	int32 CurrentScore;

	// 게임을 클리어했는지 판단하기 위한 변수
	UPROPERTY(VisibleInstanceOnly,BlueprintReadOnly, Category = Game)
	uint8 bIsCleared : 1;
};
