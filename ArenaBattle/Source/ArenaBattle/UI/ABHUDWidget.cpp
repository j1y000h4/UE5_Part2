// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHUDWidget.h"
#include "Interface/ABCharacterHUDInterface.h"
#include "ABHpBarWidget.h"
#include "ABCharacterStatWidget.h"

// 위젯의 경우에는 인자(ObjectInitializer)가 하나 들어간다. 상위 클래스에 패스해주기
UABHUDWidget::UABHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

// 스텟 업데이트
void UABHUDWidget::UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat)
{
	FABCharacterStat TotalStat = BaseStat + ModifierStat;
	//HpBar->SetMaxHp(TotalStat.MaxHp);
	HpBar->UpdateStat(BaseStat, ModifierStat);

	CharacterStat->UpdateStat(BaseStat, ModifierStat);
}

// HpBar 업데이트
void UABHUDWidget::UpdateHpBar(float NewCurrentHp)
{
	HpBar->UpdateHpBar(NewCurrentHp);
}

// 스탯 컴포넌트안에 있는 스탯 데이터들이 HUD 위젯 안의 두개의 위젯과 연동하도록 하여 스탯 데이터가 업데이트되면 자동으로 반영되도록
// 인터페이스를 통해 위젯을 사용하고 있는 캐릭터에 명령을 보낸다.
void UABHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	HpBar = Cast<UABHpBarWidget>(GetWidgetFromName(TEXT("WidgetHpBar")));
	ensure(HpBar);

	CharacterStat = Cast<UABCharacterStatWidget>(GetWidgetFromName(TEXT("WidgetCharacterStat")));
	ensure(CharacterStat);

	// Pawn 얻어오기. HUD의 경우 GetOwningPlayer 함수를 사용해서 HUD를 소유하는 컨트롤러를 가져올 수 있고, GetOwningPlayerPawn을 통해 컨트롤러가 빙의하고 있는 Pawn을 바로 가져올 수 있다.
	// 해당 위젯에 전달해서 폰으로 하여금 셋업하라고 명령을 내려주면 된다.
	IABCharacterHUDInterface* HUDPawn = Cast<IABCharacterHUDInterface>(GetOwningPlayerPawn());
	if (HUDPawn)
	{
		// 자기 자신을 전달
		HUDPawn->SetupHUDWidget(this);
	}
}
