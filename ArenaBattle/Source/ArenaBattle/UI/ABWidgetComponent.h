// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ABWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
protected:
	// 확장을 위해 InitWidget을 override하여 로직 구성하기
	virtual void InitWidget() override;
};
