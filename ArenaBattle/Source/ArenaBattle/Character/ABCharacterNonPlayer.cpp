// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterNonPlayer.h"
#include "Engine/AssetManager.h"		// 에셋 매니저, 비동기 로드 위한

AABCharacterNonPlayer::AABCharacterNonPlayer()
{
	GetMesh()->SetHiddenInGame(true);
}

void AABCharacterNonPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// NPCMeshes가 제대로 들어왔는지 확인
	ensure(NPCMeshes.Num() > 0);
	int32 RandIndex = FMath::RandRange(0, NPCMeshes.Num() - 1);
	// 에셋 매니저를 사용해서 비동기 방식으로 AsyncLoad로 진행, 비동기가 끝나면 NPCMeshLoadCompleted 함수를 실행할 수 있도록 바인드
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

// 비동기가 끝나면 NPCMeshLoadCompleted 함수 실행
void AABCharacterNonPlayer::NPCMeshLoadCompleted()
{
	// 로딩이 완료된 후 Handle이 유효한가?
	if (NPCMeshHandle.IsValid())
	{
		//GetLoadedAsset를 사용해서 Mesh 가져오기
		USkeletalMesh* NPCMesh = Cast<USkeletalMesh>(NPCMeshHandle->GetLoadedAsset());
		if (NPCMesh)
		{
			GetMesh()->SetSkeletalMesh(NPCMesh);
			GetMesh()->SetHiddenInGame(false);
		}
	}

	// Handle은 사용 완료후 해지
	NPCMeshHandle->ReleaseHandle();
}