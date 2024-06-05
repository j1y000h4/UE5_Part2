// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "InputActionValue.h"		// FInputActionValue 구조체를 사용하기 위함
#include "Interface/ABCharacterHUDInterface.h"
#include "ABCharacterPlayer.generated.h"

UCLASS()
class ARENABATTLE_API AABCharacterPlayer : public AABCharacterBase, public IABCharacterHUDInterface
{
	GENERATED_BODY()
	
public:
	AABCharacterPlayer();

	

protected:
	virtual void BeginPlay() override;

	// Player가 죽었을때 동작하는 함수
	virtual void SetDead() override;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Character Control Section
protected:
	void ChangeCharacterControl();		// V키를 눌러서 컨트롤러를 바꾸는 것을 구현하는 함수
	void SetChangeCharacterControl(ECharacterControlType NewCharacterControlYype);		// 실제로 변경이 발생했을 때, 컨트롤에 관련된 모든 설정을 진행해주는 함수

	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData) override;


// Camera 셋팅 관련 컴포넌트 추가
protected:
	// Meta = private로 선언된 어떤 언리얼 오브젝트의 객체들을 블루프린트에서도 접근할 수 있도록 만들어 주는 특별한 지시자
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;		// SpringArm

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;		// 실제 카메라 컴포넌트

// 입력 셋팅
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ChangeControlAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ShoulderMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ShoulderLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> QuaterMoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> AttackAction;

	// Shoulder
	void ShoulderMove(const FInputActionValue& Value);
	void ShoulderLook(const FInputActionValue& Value);

	// Quater
	void QuaterMove(const FInputActionValue& Value);

	// 현재 어떤 뷰를 가지고 있는가에 대한 열거형 변수
	ECharacterControlType CurrentCharacterControlType;

	// Attack
	void Attack();

	// UI Section
protected:
	virtual void SetupHUDWidget(class UABHUDWidget* InHUDWidget) override;
};
