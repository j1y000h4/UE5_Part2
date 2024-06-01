// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterStat/ABCharacterStatComponent.h"
#include "GameData/ABGameSingleton.h"

// Sets default values for this component's properties
UABCharacterStatComponent::UABCharacterStatComponent()
{
	// 기본값
	CurrentLevel = 1;
	AttackRadius = 50.0f;
}


// Called when the game starts
void UABCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();
	
	SetLevelStat(CurrentLevel);
	SetHp(BaseStat.MaxHp);
}

// 주어진 레벨에서 스텟 값을 변경하도록 설정
void UABCharacterStatComponent::SetLevelStat(int32 InNewLevel)
{
	// GameSingleton에서 데이터를 가져오기
	CurrentLevel = FMath::Clamp(InNewLevel, 1, UABGameSingleton::Get().CharacterMaxLevel);
	BaseStat = UABGameSingleton::Get().GetCharacterStat(CurrentLevel);
	check(BaseStat.MaxHp > 0.0f);
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
	CurrentHp = FMath::Clamp<float>(NewHp, 0.0f, BaseStat.MaxHp);

	// CurrentHp가 변경됐다라는 델리게이트 실행/전파
	OnHpChanged.Broadcast(CurrentHp);
}
