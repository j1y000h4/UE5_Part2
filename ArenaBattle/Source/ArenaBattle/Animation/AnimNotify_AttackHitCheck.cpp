// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
//#include "Character/ABCharacterBase.h"		// 다른 폴더의 헤더파일을 추가하는 것은 결국 의존성이 생긴다는 것
#include "Interface/ABAnimationAttackInterface.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	// 메쉬 컴포넌트가 있다면
	if (MeshComp)
	{
		// 해당 Owner가 인터페이스를 구현했는지 체크하기
		IABAnimationAttackInterface* AttackPawn = Cast<IABAnimationAttackInterface>(MeshComp->GetOwner());

		if (AttackPawn)
		{
			AttackPawn->AttackHitCheck();
		}
	}
}
