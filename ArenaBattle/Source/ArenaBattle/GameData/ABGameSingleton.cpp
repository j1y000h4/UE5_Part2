// Fill out your copyright notice in the Description page of Project Settings.


#include "GameData/ABGameSingleton.h"

DEFINE_LOG_CATEGORY(LogABGameSingleton);

// 엑셀 테이블에서 만든 로우 테이블 에셋을 접근해서 TArray로 변환, 저장시키기
UABGameSingleton::UABGameSingleton()
{
	// 만든 DataTable 주소를 가져온다.
	// DataTable은 맵 형태로 Key,Value 값으로 들어온다.
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableRef(TEXT("/Script/Engine.DataTable'/Game/ArenaBattle/GameData/ABCharacterStatTable.ABCharacterStatTable'"));
	if (nullptr != DataTableRef.Object)
	{
		// 갯수가 맞는지 체크
		const UDataTable* DataTable = DataTableRef.Object;
		check(DataTable->GetRowMap().Num() > 0);

		// Key값은 순차적으로 오기 때문에 Key값은 필요없고, Value값만 Array에 저장
		TArray<uint8*> ValueArray;
		DataTable->GetRowMap().GenerateValueArray(ValueArray);
		Algo::Transform(ValueArray, CharacterStatTable,
			[](uint8* Value)
			{
				return *reinterpret_cast<FABCharacterStat*>(Value);
			}
		);
	}

	// 배열의 갯수가 0보다 큰지 확인
	CharacterMaxLevel = CharacterStatTable.Num();
	ensure(CharacterMaxLevel > 0);
}

// Singleton Get() 함수
UABGameSingleton& UABGameSingleton::Get()
{
	// CastChecked로 강력하게 검사, GEngine에 있는 아까 적용한 GameSingleton을 가져오기
	UABGameSingleton* Singleton = CastChecked<UABGameSingleton>(GEngine->GameSingleton);
	if (Singleton)
	{
		return *Singleton;
	}
	// 혹시 몰라서 만약 Singleton이 null 값이라면 에러를 띄우도록 함
	// 코드의 흐름을 위해서 return값의 인스턴스를 생성하고 리턴함
	UE_LOG(LogABGameSingleton, Error, TEXT("Invalide Game Singleton"));
	return *NewObject<UABGameSingleton>();
}
