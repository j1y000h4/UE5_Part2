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

	// AIController가 가진 Pawn을 획득
	APawn* ControllingPawn = Cast<APawn>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ControllingPawn)
	{
		return EBTNodeResult::Failed;
	}

	// Interface를 통해 공격 명령
	IABCharacterAIInterface* AIPawn = Cast<IABCharacterAIInterface>(ControllingPawn);
	if (nullptr == AIPawn)
	{
		return EBTNodeResult::Failed;
	}

	// 공격이 시작하기 전 델리게이트를 바인딩해준다.
	FAICharacterAttackFinished OnAttackFinished;
	OnAttackFinished.BindLambda(
		[&]()
		{
			// 람다식을 통해 Task가 끝나면 Succeeded를 해준다.
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}
	);
	// 델리게이트 바인딩
	AIPawn->SetAIAttackDelegate(OnAttackFinished);

	// 공격의 경우에는 바로 끝나는 액션이 아니다. 공격 시작 -> 몽타주 재생 -> 몽타주가 끝나야지만 공격이 끝났다라고 할 수 있다.
	// AttackByAI를 통해 공격을 시작해주고 Result는 Inprogress로 설정해준 다음, 공격이 끝난 이후에 Succeded 값으로 반환해주면 된다.
	AIPawn->AttackByAI();
	return EBTNodeResult::InProgress;
}
