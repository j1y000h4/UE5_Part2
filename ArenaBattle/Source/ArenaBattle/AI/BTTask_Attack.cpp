// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_Attack.h"
#include "AIController.h"
#include "Interface/ABCharacterAIInterface.h"

UBTTask_Attack::UBTTask_Attack()
{

}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	// AIController�� ���� Pawn�� ȹ��
	APawn* ControllingPawn = Cast<APawn>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ControllingPawn)
	{
		return EBTNodeResult::Failed;
	}

	// Interface�� ���� ���� ���
	IABCharacterAIInterface* AIPawn = Cast<IABCharacterAIInterface>(ControllingPawn);
	if (nullptr == AIPawn)
	{
		return EBTNodeResult::Failed;
	}

	// ������ �����ϱ� �� ��������Ʈ�� ���ε����ش�.
	FAICharacterAttackFinished OnAttackFinished;
	OnAttackFinished.BindLambda(
		[&]()
		{
			// ���ٽ��� ���� Task�� ������ Succeeded�� ���ش�.
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}
	);
	// ��������Ʈ ���ε�
	AIPawn->SetAIAttackDelegate(OnAttackFinished);

	// ������ ��쿡�� �ٷ� ������ �׼��� �ƴϴ�. ���� ���� -> ��Ÿ�� ��� -> ��Ÿ�ְ� ���������� ������ �����ٶ�� �� �� �ִ�.
	// AttackByAI�� ���� ������ �������ְ� Result�� Inprogress�� �������� ����, ������ ���� ���Ŀ� Succeded ������ ��ȯ���ָ� �ȴ�.
	AIPawn->AttackByAI();
	return EBTNodeResult::InProgress;
}
