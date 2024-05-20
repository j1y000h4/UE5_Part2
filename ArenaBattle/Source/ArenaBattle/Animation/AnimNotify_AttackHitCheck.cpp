// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
//#include "Character/ABCharacterBase.h"		// �ٸ� ������ ��������� �߰��ϴ� ���� �ᱹ �������� ����ٴ� ��
#include "Interface/ABAnimationAttackInterface.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	// �޽� ������Ʈ�� �ִٸ�
	if (MeshComp)
	{
		// �ش� Owner�� �������̽��� �����ߴ��� üũ�ϱ�
		IABAnimationAttackInterface* AttackPawn = Cast<IABAnimationAttackInterface>(MeshComp->GetOwner());

		if (AttackPawn)
		{
			AttackPawn->AttackHitCheck();
		}
	}
}
