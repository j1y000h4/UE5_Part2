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
	// Ȯ���� ���� InitWidget�� override�Ͽ� ���� �����ϱ�
	virtual void InitWidget() override;
};
