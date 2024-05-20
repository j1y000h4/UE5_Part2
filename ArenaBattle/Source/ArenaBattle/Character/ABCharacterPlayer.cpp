// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ABCharacterControlData.h"

AABCharacterPlayer::AABCharacterPlayer()		// ������
{
	// Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));		// ������Ʈ ����
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));		// ������Ʈ ����
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);			// ī�޶�Ͽ� ����(CameraBoom) / �����̶�� Ư���� �̸������ڸ� �����ϸ� ������ ���� ���� �ڵ����� �޶�ٰ� �ȴ�.
	FollowCamera->bUsePawnControlRotation = false;

	// Input
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionJumpRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Jump.IA_Jump'"));
	if (nullptr != InputActionJumpRef.Object)
	{
		JumpAction = InputActionJumpRef.Object;
	}

	// ChangeControl �׼ǿ� ���ؼ�
	static ConstructorHelpers::FObjectFinder<UInputAction> InputChangeActionControlRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ChangeControl.IA_ChangeControl'"));
	if (nullptr != InputChangeActionControlRef.Object)
	{
		ChangeControlAction = InputChangeActionControlRef.Object;
	}

	// ShoulderMove �׼ǿ� ���ؼ�
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionShoulderMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ShoulderMove.IA_ShoulderMove'"));
	if (nullptr != InputActionShoulderMoveRef.Object)
	{
		ShoulderMoveAction = InputActionShoulderMoveRef.Object;
	}
	// ShoulderLook �׼ǿ� ���ؼ�
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionShoulderLookRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ShoulderLook.IA_ShoulderLook'"));
	if (nullptr != InputActionShoulderLookRef.Object)
	{
		ShoulderLookAction = InputActionShoulderLookRef.Object;
	}

	// QuaterMove �׼ǿ� ���ؼ�
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionQuaterMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_QuaterMove.IA_QuaterMove'"));
	if (nullptr != InputActionQuaterMoveRef.Object)
	{
		QuaterMoveAction = InputActionQuaterMoveRef.Object;
	}

	// Attack �׼ǿ� ���ؼ�
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionAttackRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Attack.IA_Attack'"));
	if (nullptr != InputActionAttackRef.Object)
	{
		AttackAction = InputActionAttackRef.Object;
	}

	// ���� � ��Ʈ��Ÿ���� ������ �ִ����� ���� ������ ���� = ���ͺ�� �ʱ�ȭ
	CurrentCharacterControlType = ECharacterControlType::Quater;
}

void AABCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();

	SetChangeCharacterControl(CurrentCharacterControlType);
}

void AABCharacterPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);		// ���� EnhancedInputComponent�� ������� ������ ������ �߻��ϵ��� CastChecked �Լ��� ���

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	EnhancedInputComponent->BindAction(ChangeControlAction, ETriggerEvent::Completed, this, &AABCharacterPlayer::ChangeCharacterControl);		// �並 �ٲٴ� �׼�
	EnhancedInputComponent->BindAction(ShoulderMoveAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::ShoulderMove);
	EnhancedInputComponent->BindAction(ShoulderLookAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::ShoulderLook);
	EnhancedInputComponent->BindAction(QuaterMoveAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::QuaterMove);
	EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::Attack);		// �Է� Attack�׼��� �ߵ��Ǿ��� ��, Attack�Լ� ���ε�
}

// VŰ�� ������ ��Ʈ�ѷ��� �ٲٴ� ���� �����ϴ� �Լ�
void AABCharacterPlayer::ChangeCharacterControl()
{
	// ���ͺ��϶��� ������, ������϶��� ���ͺ��
	if (CurrentCharacterControlType == ECharacterControlType::Quater)
	{
		SetChangeCharacterControl(ECharacterControlType::Shoulder);
	}
	else if (CurrentCharacterControlType == ECharacterControlType::Shoulder)
	{
		SetChangeCharacterControl(ECharacterControlType::Quater);
	}
}

// ������ ������ �߻����� ��, ��Ʈ�ѿ� ���õ� ��� ������ �������ִ� �Լ�
void AABCharacterPlayer::SetChangeCharacterControl(ECharacterControlType NewCharacterControlType)
{
	// ����Ŭ������ ����� ��Ʈ�ѸŴ���(CharacterControlData)���� ��Ʈ�� ������ �ּ� ��������
	UABCharacterControlData* NewCharacterControl = CharacterControlManager[NewCharacterControlType];

	// check �Լ��� ���� ��¥ �ִ��� Ȯ��
	check(NewCharacterControl);

	// �⺻ �Ӽ� ȣ��
	SetCharacterControlData(NewCharacterControl);

	// ��ǲ ���� ���ؽ�Ʈ ��������ֱ�
	// �ݵ�� �����;��ϱ� ������ CastChecked �Լ� ���
	APlayerController* PlayerController = CastChecked<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		// �ٲ�ġ���� �� ������ �ִ� ��� ��ǲ ���� ���ؽ�Ʈ�� ��� ������ ������ ��ǲ ���� ���ؽ�Ʈ�� ����
		Subsystem->ClearAllMappings();
		UInputMappingContext* NewMappingContext = NewCharacterControl->InputMappingContext;
		if (NewMappingContext)
		{
			Subsystem->AddMappingContext(NewMappingContext, 0);
		}
	}

	// ���� ��Ʈ�� Ÿ���� ���ο� ��Ʈ�� ������ Ÿ������ ����
	CurrentCharacterControlType = NewCharacterControlType;
}

void AABCharacterPlayer::SetCharacterControlData(const UABCharacterControlData* CharacterControlData)
{
	Super::SetCharacterControlData(CharacterControlData);

	CameraBoom->TargetArmLength = CharacterControlData->TargetArmLength;
	CameraBoom->SetRelativeRotation(CharacterControlData->RelativeRotation);
	CameraBoom->bUsePawnControlRotation = CharacterControlData->bUsePawnControlRotation;
	CameraBoom->bInheritPitch = CharacterControlData->bInheritPitch;
	CameraBoom->bInheritYaw = CharacterControlData->bInheritYaw;
	CameraBoom->bInheritRoll = CharacterControlData->bInheritRoll;
	CameraBoom->bDoCollisionTest = CharacterControlData->bDoCollisionTest;
}

// Shoulder
void AABCharacterPlayer::ShoulderMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = Controller->GetControlRotation();		// ������Ʈ �� Rotation ���� �����ͼ�
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);		// ���� ����
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);			// ������ ����

	AddMovementInput(ForwardDirection, MovementVector.X);		// ĳ���͸� �̵���Ű���� ����
	AddMovementInput(RightDirection, MovementVector.Y);			// ĳ���͸� �̵���Ű���� ����
}

void AABCharacterPlayer::ShoulderLook(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);		// �Է°��� �޾Ƽ� Controller�� Control Rotation �Ӽ��� ������Ʈ�ϴµ� ���ȴ�.
	AddControllerPitchInput(LookAxisVector.Y);
}

// Quater
void AABCharacterPlayer::QuaterMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	float InputSizeSquared = MovementVector.SquaredLength();		// ���� MovementVector �ޱ�

	float MovementVectorSize = 1.0f;
	float MovementVectorSizeSquared = MovementVector.SquaredLength();

	// MovementVector ũ�Ⱑ 1�� �ǵ��� ����
	if (MovementVectorSizeSquared > 1.0f)
	{
		MovementVector.Normalize();
		MovementVectorSizeSquared = 1.0f;
	}
	else
	{
		MovementVectorSize = FMath::Sqrt(MovementVectorSizeSquared);
	}

	FVector MoveDirection = FVector(MovementVector.X, MovementVector.Y, 0.0f);
	// ���� ControlRotation�� ���� Forward ����(MoveDirection)���� ����ؼ� �������ָ�, �����Ʈ ������Ʈ���� ������ �ɼǿ� ���ؼ� ĳ���Ͱ� �ڵ����� �̵��ϴ� �������� ȸ���ϰ� �ȴ�.
	GetController()->SetControlRotation(FRotationMatrix::MakeFromX(MoveDirection).Rotator());
	AddMovementInput(MoveDirection, MovementVectorSize);
}

// Attack
void AABCharacterPlayer::Attack()
{
	ProcessComboCommand();
}
