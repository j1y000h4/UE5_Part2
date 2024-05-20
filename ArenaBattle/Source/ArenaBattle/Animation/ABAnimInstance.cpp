// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/ABAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UABAnimInstance::UABAnimInstance()
{
	MovingThreshould = 3.0f;
	JumpingThreshould = 100.0f;
}

// AnimInstance�� ó�� ������ �� �� �� ȣ��
void UABAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// ������Ʈ�� ���� ����Ʈ ���� �ʱ�ȭ
	Owner = Cast<ACharacter>(GetOwningActor());		// ����ȯ
	if (Owner)		// Null �� Ȯ��
	{
		Movement = Owner->GetCharacterMovement();		// Movement�� ���� ĳ���� �����Ʈ ��ü�� ���� ���� ���� �� �ִ�.
	}
}

// �����Ӹ��� ȣ��
void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// NativeInitializeAnimation()���� ������ ������ ���� ����
	if (Movement)
	{
		Velocity = Movement->Velocity;
		GroundSpeed = Velocity.Size2D();
		bIsIdle = GroundSpeed < MovingThreshould;
		bIsFalling = Movement->IsFalling();
		bIsJumping = bIsFalling & (Velocity.Z > JumpingThreshould);
	}
}
