// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHpBarWidget.h"
#include "Components/ProgressBar.h"

UABHpBarWidget::UABHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxHp = -1.0f;
}

// NativeConstruct �Լ��� ȣ��� ���� UI�� ���õ� ��� ��ɵ��� ���� �ʱ�ȭ�� �Ϸ�ƴٰ� ���� �ȴ�.
void UABHpBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// �Ʊ� PbHpBar��� Canvas�� ������
	HpProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PbHpBar")));
	ensure(HpProgressBar);
}

void UABHpBarWidget::UpdateHpBar(float NewCurrentHp)
{
	ensure(MaxHp > 0.0f);
	if (HpProgressBar)
	{
		HpProgressBar->SetPercent(NewCurrentHp / MaxHp);
	}
}
