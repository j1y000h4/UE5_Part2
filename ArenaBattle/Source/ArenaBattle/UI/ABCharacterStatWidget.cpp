// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABCharacterStatWidget.h"
#include "Components/TextBlock.h"		// TextBlock ����

void UABCharacterStatWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// FABCharacterStat ����ü�� �ִ� �Ӽ� ������ ��� �о ��Ī�Ǵ� ������ �ؽ�Ʈ ��Ͽ� �����͸� ����������
	// ����ü ������ StaticStruct()�� ��������
	for (TFieldIterator<FNumericProperty> PropIt(FABCharacterStat::StaticStruct()); PropIt; ++PropIt)
	{
		// �Ӽ��� Ű��
		const FName PropKey(PropIt->GetName());
		// Base�� �� ���� FString���� �ռ�
		const FName TextBaseControlName = *FString::Printf(TEXT("Txt%sBase"), *PropIt->GetName());
		// Modifier�� �� ���� FString���� �ռ�
		const FName TextModifierControlName = *FString::Printf(TEXT("Txt%sModifier"), *PropIt->GetName());

		// �̸��� ���� TextBlock�� �����͸� �ҷ��´�.
		// �̸� ������ TMap�ڷ� ���� ���̺� �־� �����ϵ��� �Ѵ�.
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

// ���� ������Ʈ
void UABCharacterStatWidget::UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat)
{
	// ����ü ��ȸ
	for (TFieldIterator<FNumericProperty> PropIt(FABCharacterStat::StaticStruct()); PropIt; ++PropIt)
	{
		// Ű�� ��������
		const FName PropKey(PropIt->GetName());

		// �־��� ����ü �����Ϳ��� ���� ������Ƽ�� ���� �����ͼ� BaseData�� ModifierData�� �����Ѵ�.
		float BaseData = 0.0f;
		PropIt->GetValue_InContainer((const void*)&BaseStat, &BaseData);
		float ModifierData = 0.0f;
		PropIt->GetValue_InContainer((const void*)&ModifierStat, &ModifierData);

		// PropKey�� ���� UTextBlock �����͸� ã�´�. ���� ã�Ҵٸ� BaseData������ ������Ʈ �����ش�.
		UTextBlock** BaseTextBlockPtr = BaseLookup.Find(PropKey);
		if (BaseTextBlockPtr)
		{
			// BaseData�� ���ڿ��� ��ȯ�ϰ��̸� FText�� ��ȯ�ؼ� �־��ش�.
			(*BaseTextBlockPtr)->SetText(FText::FromString(FString::SanitizeFloat(BaseData)));
		}

		UTextBlock** ModifierTextBlockPtr = ModifierLookup.Find(PropKey);
		if (ModifierTextBlockPtr)
		{
			(*ModifierTextBlockPtr)->SetText(FText::FromString(FString::SanitizeFloat(ModifierData)));
		}
	}
}
