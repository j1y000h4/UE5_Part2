// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ABItemData.h"
#include "ABWeaponItemData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABWeaponItemData : public UABItemData
{
	GENERATED_BODY()
	
public:
	// UPrimaryDataAsset ������ ������ ������ ���̵� ���� �������� �� �ִ� GetPrimaryAssetId() �Լ��� �������̵�
	FPrimaryAssetId GetPrimaryAssetId() const override
	{
		// �ΰ��� ������ �������� ������ �ĺ��� ���̵��� ����� �� �� �ִ�.
		return FPrimaryAssetId("ABItemData", GetFName());
	}
	
public:
	UPROPERTY(EditAnywhere, Category = Weapon)
	TSoftObjectPtr<USkeletalMesh> WeaponMesh;
};
