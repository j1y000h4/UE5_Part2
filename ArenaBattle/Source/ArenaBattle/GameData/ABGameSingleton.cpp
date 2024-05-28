// Fill out your copyright notice in the Description page of Project Settings.


#include "GameData/ABGameSingleton.h"

DEFINE_LOG_CATEGORY(LogABGameSingleton);

// ���� ���̺��� ���� �ο� ���̺� ������ �����ؼ� TArray�� ��ȯ, �����Ű��
UABGameSingleton::UABGameSingleton()
{
	// ���� DataTable �ּҸ� �����´�.
	// DataTable�� �� ���·� Key,Value ������ ���´�.
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableRef(TEXT("/Script/Engine.DataTable'/Game/ArenaBattle/GameData/ABCharacterStatTable.ABCharacterStatTable'"));
	if (nullptr != DataTableRef.Object)
	{
		// ������ �´��� üũ
		const UDataTable* DataTable = DataTableRef.Object;
		check(DataTable->GetRowMap().Num() > 0);

		// Key���� ���������� ���� ������ Key���� �ʿ����, Value���� Array�� ����
		TArray<uint8*> ValueArray;
		DataTable->GetRowMap().GenerateValueArray(ValueArray);
		Algo::Transform(ValueArray, CharacterStatTable,
			[](uint8* Value)
			{
				return *reinterpret_cast<FABCharacterStat*>(Value);
			}
		);
	}

	// �迭�� ������ 0���� ū�� Ȯ��
	CharacterMaxLevel = CharacterStatTable.Num();
	ensure(CharacterMaxLevel > 0);
}

// Singleton Get() �Լ�
UABGameSingleton& UABGameSingleton::Get()
{
	// CastChecked�� �����ϰ� �˻�, GEngine�� �ִ� �Ʊ� ������ GameSingleton�� ��������
	UABGameSingleton* Singleton = CastChecked<UABGameSingleton>(GEngine->GameSingleton);
	if (Singleton)
	{
		return *Singleton;
	}
	// Ȥ�� ���� ���� Singleton�� null ���̶�� ������ ��쵵�� ��
	// �ڵ��� �帧�� ���ؼ� return���� �ν��Ͻ��� �����ϰ� ������
	UE_LOG(LogABGameSingleton, Error, TEXT("Invalide Game Singleton"));
	return *NewObject<UABGameSingleton>();
}
