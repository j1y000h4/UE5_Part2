// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ABCharacterStatComponent.generated.h"

// ��������Ʈ ����
DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate);		// Hp�� 0�϶�, �׾��ٶ�� �ñ׳� ��������Ʈ
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, float /*CurrentHp*/);		// ����� ���� Hp ���� ������ ��ü�鿡�� �������� ���� ���� ����


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARENABATTLE_API UABCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UABCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// ��������Ʈ ���� ����
	FOnHpZeroDelegate OnHpZero;
	FOnHpChangedDelegate OnHpChanged;

	FORCEINLINE float GetMaxHp() { return MaxHp; }
	FORCEINLINE float GetCurrentHp() { return CurrentHp; }
	float ApplyDamage(float InDamage);
		
protected:
	// ���������� Hp���� ������ ������ ������ �Լ�
	// Hp�� ������ �Ƿ��� �ݵ�� �� �Լ��� ���� ������ ȣ���ϵ��� ����
	void SetHp(float NewHp);

	// VisibleInstanceOnly = �ν��Ͻ����� hp���� �ٸ��� ������ �� ����
	UPROPERTY(VisibleInstanceOnly,Category = Stat)
	float MaxHp;

	// ��ũ�� ������ �ʿ䰡 ���� �ֹ߼� �������� ��� Transient ��� Ű���带 �߰��Ͽ� ��ũ�� �����Ҷ� ���ʿ��� ������ ������� �ʵ��� ������ �� ����
	UPROPERTY(VisibleInstanceOnly, Category = Stat)
	float CurrentHp;
};
