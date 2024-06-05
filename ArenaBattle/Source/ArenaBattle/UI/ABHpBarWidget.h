// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABUserWidget.h"
#include "GameData/ABCharacterStat.h"
#include "ABHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABHpBarWidget : public UABUserWidget
{
	GENERATED_BODY()
	
public:
	// UserWidget의 경우 일반적인 생성자를 쓰지않음
	UABHpBarWidget(const FObjectInitializer& ObjectInitializer);

protected:
	// 그냥 UProgressBar를 가져오게 되면 Null값이니, 위젯이 초기화될 때 HpProgressBar를 가져와서 포인터를 가져오는 기능을 추가
	// UserWidget에서 사용하는 함수임
	virtual void NativeConstruct() override;

public:
	//FORCEINLINE void SetMaxHp(float NewMaxHp) { MaxHp = NewMaxHp; }
	void UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat);
	void UpdateHpBar(float NewCurrentHp);

	// 100/100 형태로 텍스트가 바로 만들어질 수 있도록 하는 함수
	FString GetHpStatText();

protected:
	UPROPERTY()
	TObjectPtr<class UProgressBar> HpProgressBar;		// Build Dependency에서 UMG 추가하기

	UPROPERTY()
	TObjectPtr<class UTextBlock> HpStat;

	UPROPERTY()
	float CurrentHp;

	UPROPERTY()
	float MaxHp;
};
