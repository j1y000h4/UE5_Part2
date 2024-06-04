// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ABItemData.h"
#include "ABPotionItemData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABPotionItemData : public UABItemData
{
	GENERATED_BODY()
	
public:
	UABPotionItemData();

	// UPrimaryDataAsset ������ ������ ������ ���̵� ���� �������� �� �ִ� GetPrimaryAssetId() �Լ��� �������̵�
	FPrimaryAssetId GetPrimaryAssetId() const override
	{
		// �ΰ��� ������ �������� ������ �ĺ��� ���̵��� ����� �� �� �ִ�.
		return FPrimaryAssetId("ABItemData", GetFName());
	}

public:
	UPROPERTY(EditAnywhere, Category = Hp)
	float HealAmount;
};
