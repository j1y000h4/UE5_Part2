// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterNonPlayer.h"
#include "Engine/AssetManager.h"		// ���� �Ŵ���, �񵿱� �ε� ����

AABCharacterNonPlayer::AABCharacterNonPlayer()
{
	GetMesh()->SetHiddenInGame(true);
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