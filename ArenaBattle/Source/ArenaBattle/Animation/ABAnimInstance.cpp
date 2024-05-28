// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/ABAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UABAnimInstance::UABAnimInstance()
{
	MovingThreshould = 3.0f;
	JumpingThreshould = 100.0f;
}

// AnimInstance가 처음 생성될 때 한 번 호출
void UABAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// 오브젝트에 대한 포인트 값을 초기화
	Owner = Cast<ACharacter>(GetOwningActor());		// 형변환
	if (Owner)		// Null 값 확인
	{
		Movement = Owner->GetCharacterMovement();		// Movement를 통해 캐릭터 무브먼트 객체로 부터 값을 얻어올 수 있다.
	}
}

// 프레임마다 호출
void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// NativeInitializeAnimation()에서 가져온 값으로 로직 구성
	if (Movement)
	{
		Velocity = Movement->Velocity;
		GroundSpeed = Velocity.Size2D();
		bIsIdle = GroundSpeed < MovingThreshould;
		bIsFalling = Movement->IsFalling();
		bIsJumping = bIsFalling & (Velocity.Z > JumpingThreshould);
	}
}
