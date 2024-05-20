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

	// CurrentHp를 변경할 때는 SetHp 함수를 통해서 변경하도록 설정
	//CurrentHp = MaxHp;
	SetHp(MaxHp);
	
}

// 데미지 적용 로직
float UABCharacterStatComponent::ApplyDamage(float InDamage)
{
	const float PrevHp = CurrentHp;

	// 매개 변수가 음수가 들어올 수도 있으니 Clamp를 통해 다시 정의
	const float ActualDamage = FMath::Clamp<float>(InDamage, 0, InDamage);

	// CurrentHp 또한 최솟값과 최댓값을 넘지 않도록 Calmp로 정의
	// CurrentHp를 변경할 때는 SetHp 함수를 통해서 변경하도록 설정
	SetHp(PrevHp - ActualDamage);

	// 허용할수 없을정도로 작은 값일 경우
	if (CurrentHp <= KINDA_SMALL_NUMBER)
	{
		// 죽었다. 라는 델리게이트 실행/전파
		OnHpZero.Broadcast();
	}

	return ActualDamage;
}

// CurrentHp를 변경할 때는 SetHp 함수를 통해서 변경하도록 설정
void UABCharacterStatComponent::SetHp(float NewHp)
{
	CurrentHp = FMath::Clamp<float>(NewHp, 0.0f, MaxHp);

	// CurrentHp가 변경됐다라는 델리게이트 실행/전파
	OnHpChanged.Broadcast(CurrentHp);
}
