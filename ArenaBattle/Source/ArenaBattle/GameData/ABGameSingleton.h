// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABCharacterStat.h"				// 캐릭터 스탯들에 대한 테이블을 가지고 오기 위함
#include "ABGameSingleton.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogABGameSingleton, Error, All);

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameSingleton : public UObject
{
	GENERATED_BODY()
	
public:
	UABGameSingleton();
	static UABGameSingleton& Get();

// Character Stat Data Section
public:
	// Get함수, 값이 유효하면 전자, 아니면 그냥 기본 생성자를 만들어서 넘겨주도록 선언
	FORCEINLINE FABCharacterStat GetCharacterStat(int32 InLevel) const { return CharacterStatTable.IsValidIndex(InLevel) ? CharacterStatTable[InLevel - 1] : FABCharacterStat(); }

	UPROPERTY()
	// 총 몇개의 레벨?
	int32 CharacterMaxLevel;

private:
	TArray<FABCharacterStat> CharacterStatTable;		// 캐릭터 스탯들에 대한 테이블들을 내부적으로 보관해서 필요한 게임 객체들에게 제공하기 위한 Talbe Array
};
