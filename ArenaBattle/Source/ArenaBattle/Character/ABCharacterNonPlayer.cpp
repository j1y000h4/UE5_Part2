// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterNonPlayer.h"
#include "Engine/AssetManager.h"		// ���� �Ŵ���, �񵿱� �ε� ����
#include "AI/ABAIController.h"
#include "CharacterStat/ABCharacterStatComponent.h"

AABCharacterNonPlayer::AABCharacterNonPlayer()
{
	GetMesh()->SetHiddenInGame(true);

	// AIControllerClass�� ��� ���� AABAIController Ŭ������ ����
	AIControllerClass = AABAIController::StaticClass();

	// ��ġ�� NPC�� �ƴϸ� SpawnActor�� ���ؼ� ������Ų NPC �� ���� ��� �� ABAIController�� ���ؼ� �����޵��� ����
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void AABCharacterNonPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// NPCMeshes�� ����� ���Դ��� Ȯ��
	ensure(NPCMeshes.Num() > 0);
	int32 RandIndex = FMath::RandRange(0, NPCMeshes.Num() - 1);
	// ���� �Ŵ����� ����ؼ� �񵿱� ������� AsyncLoad�� ����, �񵿱Ⱑ ������ NPCMeshLoadCompleted �Լ��� ������ �� �ֵ��� ���ε�
	NPCMeshHandle = UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(NPCMeshes[RandIndex], FStreamableDelegate::CreateUObject(this, &AABCharacterNonPlayer::NPCMeshLoadCompleted));
}

void AABCharacterNonPlayer::SetDead()
{
	Super::SetDead();

	FTimerHandle DeadTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda(
		[&]()
		{
			Destroy();
		}
	), DeadEventDelayTime, false);
}

// �񵿱Ⱑ ������ NPCMeshLoadCompleted �Լ� ����
void AABCharacterNonPlayer::NPCMeshLoadCompleted()
{
	// �ε��� �Ϸ�� �� Handle�� ��ȿ�Ѱ�?
	if (NPCMeshHandle.IsValid())
	{
		//GetLoadedAsset�� ����ؼ� Mesh ��������
		USkeletalMesh* NPCMesh = Cast<USkeletalMesh>(NPCMeshHandle->GetLoadedAsset());
		if (NPCMesh)
		{
			GetMesh()->SetSkeletalMesh(NPCMesh);
			GetMesh()->SetHiddenInGame(false);
		}
	}

	// Handle�� ��� �Ϸ��� ����
	NPCMeshHandle->ReleaseHandle();
}

// ABCharacterAIInterface �κ�
float AABCharacterNonPlayer::GetAIPatrolRadius()
{
	return 800.0f;
}

float AABCharacterNonPlayer::GetAIDetectRange()
{
	return 400.0f;
}

float AABCharacterNonPlayer::GetAIAttackRange()
{
	return Stat->GetTotalStat().AttackRange + Stat->GetAttackRadius() * 2;
}

float AABCharacterNonPlayer::GetAITurnSpeed()
{
	return 2.0f;
}

void AABCharacterNonPlayer::SetAIAttackDelegate(const FAICharacterAttackFinished& InOnAttackFinished)
{
	OnAttackFinished = InOnAttackFinished;
}

void AABCharacterNonPlayer::AttackByAI()
{
	ProcessComboCommand();
}

// �޺� ������ �������� �ش� �Լ��� ȣ���
void AABCharacterNonPlayer::NotifyComboActionEnd()
{
	Super::NotifyComboActionEnd();

	// �޺� ������ ������ �� OnAttackFinished �Լ� ����
	OnAttackFinished.ExecuteIfBound();
}
