// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "InputActionValue.h"		// FInputActionValue ����ü�� ����ϱ� ����
#include "ABCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABCharacterPlayer : public AABCharacterBase
{
	GENERATED_BODY()
	
public:
	AABCharacterPlayer();

protected:
	virtual void BeginPlay() override;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Character Control Section
protected:
	void ChangeCharacterControl();		// VŰ�� ������ ��Ʈ�ѷ��� �ٲٴ� ���� �����ϴ� �Լ�
	void SetChangeCharacterControl(ECharacterControlType NewCharacterControlYype);		// ������ ������ �߻����� ��, ��Ʈ�ѿ� ���õ� ��� ������ �������ִ� �Լ�

	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData) override;


// Camera ���� ���� ������Ʈ �߰�
protected:
	// Meta = private�� ����� � �𸮾� ������Ʈ�� ��ü���� �������Ʈ������ ������ �� �ֵ��� ����� �ִ� Ư���� ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;		// SpringArm

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;		// ���� ī�޶� ������Ʈ

// �Է� ����
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

	// Attack
	void Attack();

	// ���� � �並 ������ �ִ°��� ���� ������ ����
	ECharacterControlType CurrentCharacterControlType;
};
