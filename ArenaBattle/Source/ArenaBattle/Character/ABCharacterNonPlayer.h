// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "Engine/StreamableManager.h"				// 비동기 위함
#include "Interface/ABCharacterAIInterface.h"		// AIInterface
#include "ABCharacterNonPlayer.generated.h"

/**
 * 
 */
// Config 폴더의 DefaultArenaBattle.ini를 사용해서 불러들이겠다는 의미
UCLASS(config=ArenaBattle)
class ARENABATTLE_API AABCharacterNonPlayer : public AABCharacterBase, public IABCharacterAIInterface
{
	GENERATED_BODY()
	
public:
	AABCharacterNonPlayer();

protected:
	virtual void PostInitializeComponents() override;

protected:
	void SetDead() override;

	// NPC Mesh 로딩이 완료되었을 때 신호를 받는 함수
	void NPCMeshLoadCompleted();

	// UPROPERTY에 config를 붙이게 되면 해당 config 파일로부터 데이터를 불러오겠다는 의미
	// 경로가 있기 때문에 FSoftObjectPath
	UPROPERTY(config)
	TArray<FSoftObjectPath> NPCMeshes;

	// 비동기 위한 FStreamableHandle
	TSharedPtr<FStreamableHandle> NPCMeshHandle;

// AI Section
protected:
	virtual float GetAIPatrolRadius() override;
	virtual float GetAIDetectRange() override;
	virtual float GetAIAttackRange() override;
	virtual float GetAITurnSpeed() override;

	//  Interface로부터 공격이 끝났다는걸 알려주기 위한 델리게이트
	virtual void SetAIAttackDelegate(const FAICharacterAttackFinished& InOnAttackFinished) override;
	// 공격하기 위한 함수
	virtual void AttackByAI() override;

	// 델리게이트를 담을 변수
	FAICharacterAttackFinished OnAttackFinished;

	// ABCharacterBase에 있는 콤보가 끝났을때 호출하는 함수 override
	virtual void NotifyComboActionEnd() override;
};
