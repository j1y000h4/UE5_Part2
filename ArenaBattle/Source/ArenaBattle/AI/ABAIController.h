// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ABAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AABAIController();

	// AI�� ������Ű�� ����
	void RunAI();

	// AI�� ������ ������Ű�� ����
	void StopAI();

protected:
	// Controller���� �����ϴ� OnPossess �Լ� �������̵�
	// � ��Ʈ�ѷ��� ���� �����ؼ� ������ �� �� �߻��Ǵ� �̺�Ʈ�Լ�
	virtual void OnPossess(APawn* InPawn) override;

private:

	// BlackboardData�� ������ ����
	UPROPERTY()
	TObjectPtr<class UBlackboardData> BBAsset;

	// BehaviorTree�� ������ ����
	UPROPERTY()
	TObjectPtr<class UBehaviorTree> BTAsset;
};
