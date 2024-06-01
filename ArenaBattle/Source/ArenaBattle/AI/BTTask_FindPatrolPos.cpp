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

// BTTaskNode에 있는 ExecuteTask 오버라이드
EBTNodeResult::Type UBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	// BehaviorTree를 소유한 컴포넌트의 Owner를 GetAIOwner로 가져올 수 있다. 이는 AI 컨트롤러를 상속받은 클래스의 인스턴스가 될 것
	// 이것이 어떤 폰을 빙의 하고 있다면, GetPawn을 통해서 가져올 수 있다.
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
	{
		return EBTNodeResult::Failed;
	}
	
	// NavigationSystem 가져오기
	// GetNavigationSystem에 월드값 넣어주기. ControllingPawn이 위치한 곳의 월드
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem)
	{
		return EBTNodeResult::Failed;
	}

	// NPC를 통해서 필요한 데이터를 받아오기 위함
	IABCharacterAIInterface* AIPawn = Cast<IABCharacterAIInterface>(ControllingPawn);
	if (nullptr == AIPawn)
	{
		return EBTNodeResult::Failed;
	}

	// 블랙보드 값 가져오기
	// Origin은 블랙보드의 HomePos값을 가져오기
	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(BBKEY_HOMEPOS);
	float PatrolRadius = AIPawn->GetAIPatrolRadius();
	FNavLocation NextPatrolPos;

	// NavigationSystem에서 랜덤하게 Point 값을 가져오는 것 (시작위치, 반경, PointLocation을 저장해줄 변수)
	// 데이터들을 하드 코딩이 아닌 NPC로부터 받아오도록 변경 (500.0f -> PatrolRadius)
	if (NavSystem->GetRandomPointInNavigableRadius(Origin, PatrolRadius, NextPatrolPos))
	{
		// 블랙보드의 PatrolPos를 NextPatrolPos.Location값으로 넘겨주기
		// 그러면 성공
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(BBKEY_PATROLPOS, NextPatrolPos.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
