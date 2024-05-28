﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ABItemData.generated.h"

UENUM(BlueprintType)
enum class EItemType :uint8
{
	Weapon = 0,
	Potion,
	Scroll
};

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	// UPrimaryDataAsset 내부의 생성될 에셋의 아이디를 직접 지정해줄 수 있는 GetPrimaryAssetId() 함수를 오버라이드
	FPrimaryAssetId GetPrimaryAssetId() const override
	{
		// 두가지 정보를 바탕으로 유일한 식별자 아이디값을 만들어 낼 수 있다.
		return FPrimaryAssetId("ABItemData", GetFName());
	}
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Type)
	EItemType Type;
};
