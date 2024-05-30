// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/ABAIController.h"
#include "BehaviorTree/BehaviorTree.h"				// ������ �� �ൿ Ʈ���� ���õ� �����
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ABAI.h"

AABAIController::AABAIController()
{
	// �׻� �ش� ���µ��� ����� ���̱� ������ ���������� ConstructorHelpers�� ���ؼ� ������ �������ش�.
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

// AI�� �����ϱ� ����
void AABAIController::RunAI()
{
	// AIController���� �⺻���� ��������� �����ϰ� ���� (Blackboard)
	UBlackboardComponent* BlackboardPtr = Blackboard.Get();
	// ������ �ʱ�ȭ�� ���ÿ� ��ȿ���� üũ
	if (UseBlackboard(BBAsset, BlackboardPtr))
	{
		// HomePos�� �����Ҷ� �Ҵ��ϵ��� ����
		Blackboard->SetValueAsVector(BBKEY_HOMEPOS, GetPawn()->GetActorLocation());

		// BehaviorTree ���� �� Ȯ��
		bool RunResult = RunBehaviorTree(BTAsset);
		ensure(RunResult);
	}
}

// AI�� ������ �����ϱ� ����
void AABAIController::StopAI()
{
	UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);		// AIController ��� ���� (BrainComponent) = ���� �����ϰ� �ִ� BehaviorTreeComponent
	if (BTComponent)
	{
		BTComponent->StopTree();
	}
}

// ���� �������� ��
void AABAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunAI();
}
