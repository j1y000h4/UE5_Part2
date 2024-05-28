#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ABCharacterStat.generated.h"

USTRUCT(BlueprintType)
struct FABCharacterStat : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	FABCharacterStat() : MaxHp(0.0f), Attack(0.0f), AttackRange(0.0f), AttackSpeed(0.0f) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MaxHp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float Attack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MovementSpeed;

	// 연산자 재정의
	// 모든 멤버변수가 float이라고 가정이 되면, 구조체의 데이터는 float의 집합으로 구성됨
	// 이 크기만큼 개수를 확인하고 더해주면 새로운 연산자를 추가해도 덧셈 연산을 고칠 필요가 없다.
	FABCharacterStat operator+(const FABCharacterStat& Other) const
	{
		const float* const ThisPtr = reinterpret_cast<const float* const>(this);
		const float* const OtherPtr = reinterpret_cast<const float* const>(&Other);

		FABCharacterStat Result;
		float* ResultPtr = reinterpret_cast<float*>(&Result);
		int32 StatNum = sizeof(FABCharacterStat) / sizeof(float);
		for (int32 i = 0; i < StatNum; i++)
		{
			ResultPtr[i] = ThisPtr[i] + OtherPtr[i];
		}

		return Result;
	}
};