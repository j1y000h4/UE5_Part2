// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHUDWidget.h"
#include "Interface/ABCharacterHUDInterface.h"
#include "ABHpBarWidget.h"
#include "ABCharacterStatWidget.h"

// ������ ��쿡�� ����(ObjectInitializer)�� �ϳ� ����. ���� Ŭ������ �н����ֱ�
UABHUDWidget::UABHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

// ���� ������Ʈ
void UABHUDWidget::UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat)
{
	FABCharacterStat TotalStat = BaseStat + ModifierStat;
	//HpBar->SetMaxHp(TotalStat.MaxHp);
	HpBar->UpdateStat(BaseStat, ModifierStat);

	CharacterStat->UpdateStat(BaseStat, ModifierStat);
}

// HpBar ������Ʈ
void UABHUDWidget::UpdateHpBar(float NewCurrentHp)
{
	HpBar->UpdateHpBar(NewCurrentHp);
}

// ���� ������Ʈ�ȿ� �ִ� ���� �����͵��� HUD ���� ���� �ΰ��� ������ �����ϵ��� �Ͽ� ���� �����Ͱ� ������Ʈ�Ǹ� �ڵ����� �ݿ��ǵ���
// �������̽��� ���� ������ ����ϰ� �ִ� ĳ���Ϳ� ����� ������.
void UABHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	HpBar = Cast<UABHpBarWidget>(GetWidgetFromName(TEXT("WidgetHpBar")));
	ensure(HpBar);

	CharacterStat = Cast<UABCharacterStatWidget>(GetWidgetFromName(TEXT("WidgetCharacterStat")));
	ensure(CharacterStat);

	// Pawn ������. HUD�� ��� GetOwningPlayer �Լ��� ����ؼ� HUD�� �����ϴ� ��Ʈ�ѷ��� ������ �� �ְ�, GetOwningPlayerPawn�� ���� ��Ʈ�ѷ��� �����ϰ� �ִ� Pawn�� �ٷ� ������ �� �ִ�.
	// �ش� ������ �����ؼ� ������ �Ͽ��� �¾��϶�� ����� �����ָ� �ȴ�.
	IABCharacterHUDInterface* HUDPawn = Cast<IABCharacterHUDInterface>(GetOwningPlayerPawn());
	if (HUDPawn)
	{
		// �ڱ� �ڽ��� ����
		HUDPawn->SetupHUDWidget(this);
	}
}
