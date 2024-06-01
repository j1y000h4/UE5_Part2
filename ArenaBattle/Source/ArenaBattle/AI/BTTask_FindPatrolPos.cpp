// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_FindPatrolPos.h"
#include "ABAI.h"
#include "AI/ABAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interface/ABCharacterAIInterface.h"

UBTTask_FindPatrolPos::UBTTask_FindPatrolPos()
{

}

// BTTaskNode�� �ִ� ExecuteTask �������̵�
EBTNodeResult::Type UBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	// BehaviorTree�� ������ ������Ʈ�� Owner�� GetAIOwner�� ������ �� �ִ�. �̴� AI ��Ʈ�ѷ��� ��ӹ��� Ŭ������ �ν��Ͻ��� �� ��
	// �̰��� � ���� ���� �ϰ� �ִٸ�, GetPawn�� ���ؼ� ������ �� �ִ�.
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
	{
		return EBTNodeResult::Failed;
	}
	
	// NavigationSystem ��������
	// GetNavigationSystem�� ���尪 �־��ֱ�. ControllingPawn�� ��ġ�� ���� ����
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem)
	{
		return EBTNodeResult::Failed;
	}

	// NPC�� ���ؼ� �ʿ��� �����͸� �޾ƿ��� ����
	IABCharacterAIInterface* AIPawn = Cast<IABCharacterAIInterface>(ControllingPawn);
	if (nullptr == AIPawn)
	{
		return EBTNodeResult::Failed;
	}

	// ������ �� ��������
	// Origin�� �������� HomePos���� ��������
	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(BBKEY_HOMEPOS);
	float PatrolRadius = AIPawn->GetAIPatrolRadius();
	FNavLocation NextPatrolPos;

	// NavigationSystem���� �����ϰ� Point ���� �������� �� (������ġ, �ݰ�, PointLocation�� �������� ����)
	// �����͵��� �ϵ� �ڵ��� �ƴ� NPC�κ��� �޾ƿ����� ���� (500.0f -> PatrolRadius)
	if (NavSystem->GetRandomPointInNavigableRadius(Origin, PatrolRadius, NextPatrolPos))
	{
		// �������� PatrolPos�� NextPatrolPos.Location������ �Ѱ��ֱ�
		// �׷��� ����
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(BBKEY_PATROLPOS, NextPatrolPos.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
