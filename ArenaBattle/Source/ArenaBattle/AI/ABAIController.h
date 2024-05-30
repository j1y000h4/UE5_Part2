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

	// AI를 구동시키기 위한
	void RunAI();

	// AI를 구동을 중지시키기 위한
	void StopAI();

protected:
	// Controller에서 제공하는 OnPossess 함수 오버라이드
	// 어떤 컨트롤러가 폰에 빙의해서 조종을 할 때 발생되는 이벤트함수
	virtual void OnPossess(APawn* InPawn) override;

private:

	// BlackboardData를 저장할 변수
	UPROPERTY()
	TObjectPtr<class UBlackboardData> BBAsset;

	// BehaviorTree를 저장할 변수
	UPROPERTY()
	TObjectPtr<class UBehaviorTree> BTAsset;
};
