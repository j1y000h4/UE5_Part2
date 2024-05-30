// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/ABAIController.h"
#include "BehaviorTree/BehaviorTree.h"				// 블랙보드 및 행동 트리에 관련된 헤더들
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ABAI.h"

AABAIController::AABAIController()
{
	// 항상 해당 에셋들을 사용할 것이기 때문에 고정적으로 ConstructorHelpers를 통해서 에셋을 지정해준다.
	// Copy Reference
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBAssetRef(TEXT("/Script/AIModule.BlackboardData'/Game/ArenaBattle/AI/BB_ABCharacter.BB_ABCharacter'"));
	if (nullptr != BBAssetRef.Object)
	{
		BBAsset = BBAssetRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTAssetRef(TEXT("/Script/AIModule.BehaviorTree'/Game/ArenaBattle/AI/BT_ABCharacter.BT_ABCharacter'"));
	if (nullptr != BTAssetRef.Object)
	{
		BTAsset = BTAssetRef.Object;
	}
}

// AI를 구동하기 위한
void AABAIController::RunAI()
{
	// AIController에서 기본으로 멤버변수로 제공하고 있음 (Blackboard)
	UBlackboardComponent* BlackboardPtr = Blackboard.Get();
	// 블랙보드 초기화와 동시에 유효한지 체크
	if (UseBlackboard(BBAsset, BlackboardPtr))
	{
		// HomePos를 시작할때 할당하도록 선언
		Blackboard->SetValueAsVector(BBKEY_HOMEPOS, GetPawn()->GetActorLocation());

		// BehaviorTree 구동 및 확인
		bool RunResult = RunBehaviorTree(BTAsset);
		ensure(RunResult);
	}
}

// AI의 구동을 중지하기 위한
void AABAIController::StopAI()
{
	UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);		// AIController 멤버 변수 (BrainComponent) = 지금 동작하고 있는 BehaviorTreeComponent
	if (BTComponent)
	{
		BTComponent->StopTree();
	}
}

// 폰에 빙의했을 때
void AABAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunAI();
}
