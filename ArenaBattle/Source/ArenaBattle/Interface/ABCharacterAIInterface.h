// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ABCharacterAIInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UABCharacterAIInterface : public UInterface
{
	GENERATED_BODY()
};

// 공격이 끝났는지를 알려주기위한 델리게이트
DECLARE_DELEGATE(FAICharacterAttackFinished);

/**
 * 
 */
class ARENABATTLE_API IABCharacterAIInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// NPC가 의무적으로 가져야 될 기본적인 데이터들을 얻어올 수 있도록 함수들 선언
	virtual float GetAIPatrolRadius() = 0;
	virtual float GetAIDetectRange() = 0;
	virtual float GetAIAttackRange() = 0;
	virtual float GetAITurnSpeed() = 0;

	// 캐릭터(NPC)에게 넘겨주기 위한 델리게이트 함수
	virtual void SetAIAttackDelegate(const FAICharacterAttackFinished& InOnAttackFinished) = 0;

	// AI의 공격을 구현
	// 공격의 경우에는 바로 끝나는 액션이 아니다. 공격 시작 -> 몽타주 재생 -> 몽타주가 끝나야지만 공격이 끝났다라고 할 수 있다.
	virtual void AttackByAI() = 0;
};
