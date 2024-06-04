// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameData/ABCharacterStat.h"
#include "ABHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UABHUDWidget(const FObjectInitializer& ObjectInitializer);

// 업데이트 하는 함수들
public:
	void UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat);
	void UpdateHpBar(float NewCurrentHp);

protected:
	virtual void NativeConstruct() override;

// 제작한 컨트롤 위젯 클래스 멤버변수 선언
protected:
	UPROPERTY()
	TObjectPtr<class UABHpBarWidget> HpBar;

	UPROPERTY()
	TObjectPtr<class UABCharacterStatWidget> CharacterStat;
};
