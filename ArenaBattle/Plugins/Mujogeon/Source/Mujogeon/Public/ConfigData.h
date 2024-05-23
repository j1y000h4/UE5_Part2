#pragma once

#include "CoreMinimal.h"
#include "ConfigData.generated.h"

USTRUCT(BlueprintType)
struct FConfigData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Config")
	int32 SampleInt = 1027;
	UPROPERTY(BlueprintReadOnly, Category = "Config")
	float SampleFloat = 1.45f;
	UPROPERTY(BlueprintReadOnly, Category = "Config")
	bool SampleBool = false;
	UPROPERTY()
	FString SampleString = "Hello Setting UI";
	UPROPERTY()
	FVector2D SampleVector2D = FVector2D(1.1f, 2.2f);
	UPROPERTY()
	FVector SampleVector = FVector(1.1f, 2.2f, 3.3f);
	UPROPERTY()
	FVector4 SampleVector4 = FVector4(1.1f, 2.2f, 3.3f, 4.4f);
};
