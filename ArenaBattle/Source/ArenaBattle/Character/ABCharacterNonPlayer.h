// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "Engine/StreamableManager.h"		// �񵿱� ����
#include "ABCharacterNonPlayer.generated.h"

/**
 * 
 */
// Config ������ DefaultArenaBattle.ini�� ����ؼ� �ҷ����̰ڴٴ� �ǹ�
UCLASS(config=ArenaBattle)
class ARENABATTLE_API AABCharacterNonPlayer : public AABCharacterBase
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
};
