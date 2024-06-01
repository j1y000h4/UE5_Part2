// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "Engine/StreamableManager.h"				// �񵿱� ����
#include "Interface/ABCharacterAIInterface.h"		// AIInterface
#include "ABCharacterNonPlayer.generated.h"

/**
 * 
 */
// Config ������ DefaultArenaBattle.ini�� ����ؼ� �ҷ����̰ڴٴ� �ǹ�
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

	// NPC Mesh �ε��� �Ϸ�Ǿ��� �� ��ȣ�� �޴� �Լ�
	void NPCMeshLoadCompleted();

	// UPROPERTY�� config�� ���̰� �Ǹ� �ش� config ���Ϸκ��� �����͸� �ҷ����ڴٴ� �ǹ�
	// ��ΰ� �ֱ� ������ FSoftObjectPath
	UPROPERTY(config)
	TArray<FSoftObjectPath> NPCMeshes;

	// �񵿱� ���� FStreamableHandle
	TSharedPtr<FStreamableHandle> NPCMeshHandle;

// AI Section
protected:
	virtual float GetAIPatrolRadius() override;
	virtual float GetAIDetectRange() override;
	virtual float GetAIAttackRange() override;
	virtual float GetAITurnSpeed() override;

	//  Interface�κ��� ������ �����ٴ°� �˷��ֱ� ���� ��������Ʈ
	virtual void SetAIAttackDelegate(const FAICharacterAttackFinished& InOnAttackFinished) override;
	// �����ϱ� ���� �Լ�
	virtual void AttackByAI() override;

	// ��������Ʈ�� ���� ����
	FAICharacterAttackFinished OnAttackFinished;

	// ABCharacterBase�� �ִ� �޺��� �������� ȣ���ϴ� �Լ� override
	virtual void NotifyComboActionEnd() override;
};
