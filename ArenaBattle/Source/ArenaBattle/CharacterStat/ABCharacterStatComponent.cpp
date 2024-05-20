// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterStat/ABCharacterStatComponent.h"

// Sets default values for this component's properties
UABCharacterStatComponent::UABCharacterStatComponent()
{
	MaxHp = 200.0f;
	CurrentHp = MaxHp;
}


// Called when the game starts
void UABCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// CurrentHp�� ������ ���� SetHp �Լ��� ���ؼ� �����ϵ��� ����
	//CurrentHp = MaxHp;
	SetHp(MaxHp);
	
}

// ������ ���� ����
float UABCharacterStatComponent::ApplyDamage(float InDamage)
{
	const float PrevHp = CurrentHp;

	// �Ű� ������ ������ ���� ���� ������ Clamp�� ���� �ٽ� ����
	const float ActualDamage = FMath::Clamp<float>(InDamage, 0, InDamage);

	// CurrentHp ���� �ּڰ��� �ִ��� ���� �ʵ��� Calmp�� ����
	// CurrentHp�� ������ ���� SetHp �Լ��� ���ؼ� �����ϵ��� ����
	SetHp(PrevHp - ActualDamage);

	// ����Ҽ� ���������� ���� ���� ���
	if (CurrentHp <= KINDA_SMALL_NUMBER)
	{
		// �׾���. ��� ��������Ʈ ����/����
		OnHpZero.Broadcast();
	}

	return ActualDamage;
}

// CurrentHp�� ������ ���� SetHp �Լ��� ���ؼ� �����ϵ��� ����
void UABCharacterStatComponent::SetHp(float NewHp)
{
	CurrentHp = FMath::Clamp<float>(NewHp, 0.0f, MaxHp);

	// CurrentHp�� ����ƴٶ�� ��������Ʈ ����/����
	OnHpChanged.Broadcast(CurrentHp);
}
