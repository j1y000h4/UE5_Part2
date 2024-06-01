// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AABPlayerController();
	
protected:
	virtual void BeginPlay() override;

	// HUD Section
protected:
	// 클래스 정보 변수 선언, 위젯을 생성할 때 클래스 정보를 넘겨야한다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = HUD)
	TSubclassOf<class UABHUDWidget> ABHUDWidgetClass;

	// 생성한 위젯의 포인터를 담을 변수 선언
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HUD)
	TObjectPtr<class UABHUDWidget> ABHUDWidget;
};
