// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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

	FORCEINLINE float GetMaxHp() { return MaxHp; }
	FORCEINLINE float GetCurrentHp() { return CurrentHp; }
	float ApplyDamage(float InDamage);
		
protected:
	// 내부적으로 Hp값이 변동이 됐을때 실행할 함수
	// Hp가 변경이 되려면 반드시 이 함수를 통해 가지고 호출하도록 설정
	void SetHp(float NewHp);

	// VisibleInstanceOnly = 인스턴스마다 hp값을 다르게 설정할 수 있음
	UPROPERTY(VisibleInstanceOnly,Category = Stat)
	float MaxHp;

	// 디스크에 저장할 필요가 없는 휘발성 데이터의 경우 Transient 라는 키워드를 추가하여 디스크에 저장할때 불필요한 공간이 낭비되지 않도록 지정할 수 있음
	UPROPERTY(VisibleInstanceOnly, Category = Stat)
	float CurrentHp;
};
