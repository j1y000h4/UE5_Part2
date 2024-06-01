// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameData/ABCharacterStat.h"
#include "ABCharacterStatComponent.generated.h"

// 델리게이트 선언
DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate);		// Hp가 0일때, 죽었다라는 시그널 델리게이트
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, float /*CurrentHp*/);		// 변경된 현재 Hp 값을 구독한 객체들에게 보내도록 인자 값을 설정


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
	// 델리게이트 변수 선언
	FOnHpZeroDelegate OnHpZero;
	FOnHpChangedDelegate OnHpChanged;

	// Stat Section
	// 레벨을 설정해주는 함수
	void SetLevelStat(int32 InNewLevel);
	// 레벨 Getter 함수
	FORCEINLINE float GetCurrentLevel() const { return CurrentLevel; }
	// 무기 .. 등을 획득했을때 ModifierStat을 변경해줄 수 있는 Setter 함수
	FORCEINLINE void SetModifierStat(const FABCharacterStat& InModifierStat) { ModifierStat = InModifierStat; }
	// 캐릭터의 전체 스텟값을 받아올 수 있도록
	FORCEINLINE FABCharacterStat GetTotalStat() const { return BaseStat + ModifierStat; }

	FORCEINLINE float GetCurrentHp() { return CurrentHp; }
	FORCEINLINE float GetAttackRadius() const { return AttackRadius; }
	float ApplyDamage(float InDamage);
		
protected:
	// 내부적으로 Hp값이 변동이 됐을때 실행할 함수
	// Hp가 변경이 되려면 반드시 이 함수를 통해 가지고 호출하도록 설정
	void SetHp(float NewHp);


	// 해당 네 가지 값들은 캐릭터가 초기화될 때마다 언제든지 바뀔 수 있다. 그렇기 때문에 언리얼 엔진을 저장할 때는 해당 정보가 저장되지 않도록 Transient 키워드를 추가하고, 에디터에서는 읽기 전용으로 설정
	// 디스크에 저장할 필요가 없는 휘발성 데이터의 경우 Transient 라는 키워드를 추가하여 디스크에 저장할때 불필요한 공간이 낭비되지 않도록 지정할 수 있음
	UPROPERTY(VisibleInstanceOnly, Category = Stat)
	float CurrentHp;

	// 캐릭터 스텟은 현재 레벨의 정보를 기반으로 해서 게임 싱글톤으로부터 스텟 정보를 제공받게 된다.
	UPROPERTY(Transient, VisibleInstanceOnly,Category = Stat)
	float CurrentLevel;

	UPROPERTY(VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	float AttackRadius;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FABCharacterStat BaseStat;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FABCharacterStat ModifierStat;
};
