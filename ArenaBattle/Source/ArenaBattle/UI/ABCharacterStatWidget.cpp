// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABCharacterStatWidget.h"
#include "Components/TextBlock.h"		// TextBlock 접근

void UABCharacterStatWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// FABCharacterStat 구조체에 있는 속성 값들을 모두 읽어서 매칭되는 위젯의 텍스트 블록에 포인터를 가져오도록
	// 구조체 정보는 StaticStruct()로 가져오기
	for (TFieldIterator<FNumericProperty> PropIt(FABCharacterStat::StaticStruct()); PropIt; ++PropIt)
	{
		// 속성의 키값
		const FName PropKey(PropIt->GetName());
		// Base에 들어갈 값을 FString으로 합성
		const FName TextBaseControlName = *FString::Printf(TEXT("Txt%sBase"), *PropIt->GetName());
		// Modifier에 들어갈 값을 FString으로 합성
		const FName TextModifierControlName = *FString::Printf(TEXT("Txt%sModifier"), *PropIt->GetName());

		// 이름을 통해 TextBlock의 포인터를 불러온다.
		// 이를 각각의 TMap자료 구조 테이블에 넣어 관리하도록 한다.
		UTextBlock* BaseTextBlock = Cast<UTextBlock>(GetWidgetFromName(TextBaseControlName));
		if (BaseTextBlock)
		{
			BaseLookup.Add(PropKey, BaseTextBlock); 
		}

		UTextBlock* ModifierTextBlock = Cast<UTextBlock>(GetWidgetFromName(TextModifierControlName));
		if (ModifierTextBlock)
		{
			ModifierLookup.Add(PropKey, ModifierTextBlock);
		}
	}
}

// 스텟 업데이트
void UABCharacterStatWidget::UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat)
{
	// 구조체 순회
	for (TFieldIterator<FNumericProperty> PropIt(FABCharacterStat::StaticStruct()); PropIt; ++PropIt)
	{
		// 키값 가져오기
		const FName PropKey(PropIt->GetName());

		// 주어진 구조체 포인터에서 현재 프로퍼티의 값을 가져와서 BaseData와 ModifierData에 저장한다.
		float BaseData = 0.0f;
		PropIt->GetValue_InContainer((const void*)&BaseStat, &BaseData);
		float ModifierData = 0.0f;
		PropIt->GetValue_InContainer((const void*)&ModifierStat, &ModifierData);

		// PropKey를 통해 UTextBlock 포인터를 찾는다. 만약 찾았다면 BaseData값으로 업데이트 시켜준다.
		UTextBlock** BaseTextBlockPtr = BaseLookup.Find(PropKey);
		if (BaseTextBlockPtr)
		{
			// BaseData를 문자열로 변환하고이를 FText로 변환해서 넣어준다.
			(*BaseTextBlockPtr)->SetText(FText::FromString(FString::SanitizeFloat(BaseData)));
		}

		UTextBlock** ModifierTextBlockPtr = ModifierLookup.Find(PropKey);
		if (ModifierTextBlockPtr)
		{
			(*ModifierTextBlockPtr)->SetText(FText::FromString(FString::SanitizeFloat(ModifierData)));
		}
	}
}
