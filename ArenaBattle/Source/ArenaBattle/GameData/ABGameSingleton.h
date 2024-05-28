// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABCharacterStat.h"				// ĳ���� ���ȵ鿡 ���� ���̺��� ������ ���� ����
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
	// Get�Լ�, ���� ��ȿ�ϸ� ����, �ƴϸ� �׳� �⺻ �����ڸ� ���� �Ѱ��ֵ��� ����
	FORCEINLINE FABCharacterStat GetCharacterStat(int32 InLevel) const { return CharacterStatTable.IsValidIndex(InLevel) ? CharacterStatTable[InLevel - 1] : FABCharacterStat(); }

	UPROPERTY()
	// �� ��� ����?
	int32 CharacterMaxLevel;

private:
	TArray<FABCharacterStat> CharacterStatTable;		// ĳ���� ���ȵ鿡 ���� ���̺����� ���������� �����ؼ� �ʿ��� ���� ��ü�鿡�� �����ϱ� ���� Talbe Array
};