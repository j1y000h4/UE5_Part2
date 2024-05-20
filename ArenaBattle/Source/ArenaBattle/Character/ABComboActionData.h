// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ABComboActionData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABComboActionData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UABComboActionData();

	// 몽타주 섹션 이름
	UPROPERTY(EditAnywhere,Category = Name)
	FString MontageSectionPrefix;

	// 총 몇개의 콤보가 있는가
	UPROPERTY(EditAnywhere, Category = Name)
	uint8 MaxComboCount;

	// 프레임 기준 재생 속도
	UPROPERTY(EditAnywhere, Category = Name)
	float FrameRate;

	// 입력이 사전에 입력됐는지 감지하는 프레임들
	UPROPERTY(EditAnywhere, Category = ComboData)
	TArray<float> EffectiveFrameCount;
};
