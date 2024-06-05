// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHpBarWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Interface/ABCharacterWidgetInterface.h"

UABHpBarWidget::UABHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxHp = -1.0f;
}

// NativeConstruct 함수가 호출될 때면 UI에 관련된 모든 기능들이 거의 초기화가 완료됐다고 보면 된다.
void UABHpBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 아까 PbHpBar라고 Canvas에 설정함
	HpProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PbHpBar")));
	ensure(HpProgressBar);

	// TextBlock
	HpStat = Cast<UTextBlock>(GetWidgetFromName(TEXT("TxtHpStat")));
	ensure(HpStat);

	IABCharacterWidgetInterface* CharacterWidget = Cast<IABCharacterWidgetInterface>(OwningActor);
	if (CharacterWidget)
	{
		CharacterWidget->SetupCharacterWidget(this);
	}
}

// Stat이 변경되면 HpBar와 변경된 Stat이 반영되도록
void UABHpBarWidget::UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat)
{
	MaxHp = (BaseStat + ModifierStat).MaxHp;

	if (HpProgressBar)
	{
		HpProgressBar->SetPercent(CurrentHp / MaxHp);
	}

	if (HpStat)
	{
		HpStat->SetText(FText::FromString(GetHpStatText()));
	}
}

// Stat이 변경되면 HpBar와 변경된 Stat이 반영되도록
void UABHpBarWidget::UpdateHpBar(float NewCurrentHp)
{
	CurrentHp = NewCurrentHp;

	ensure(MaxHp > 0.0f);
	if (HpProgressBar)
	{
		HpProgressBar->SetPercent(CurrentHp / MaxHp);
	}

	if (HpStat)
	{
		HpStat->SetText(FText::FromString(GetHpStatText()));
	}
}

// HpBar의 Text가 100/100 형태로 나올 수 있도록
FString UABHpBarWidget::GetHpStatText()
{
	return FString::Printf(TEXT("%.0f/%.0f"), CurrentHp, MaxHp);
}