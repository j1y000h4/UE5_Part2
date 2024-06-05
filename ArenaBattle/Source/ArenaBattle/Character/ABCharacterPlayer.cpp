// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ABCharacterControlData.h"
#include "UI/ABHUDWidget.h"
#include "CharacterStat/ABCharacterStatComponent.h"
#include "Interface/ABGameInterface.h"
#include "GameFramework/GameModeBase.h"

AABCharacterPlayer::AABCharacterPlayer()		// 생성자
{
	// Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));		// 컴포넌트 생성
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));		// 컴포넌트 생성
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);			// 카메라암에 부착(CameraBoom) / 소켓이라는 특별한 이름지시자를 지정하면 스프링 암의 끝에 자동으로 달라붙게 된다.
	FollowCamera->bUsePawnControlRotation = false;

	// Input
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionJumpRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Jump.IA_Jump'"));
	if (nullptr != InputActionJumpRef.Object)
	{
		JumpAction = InputActionJumpRef.Object;
	}

	// ChangeControl 액션에 대해서
	static ConstructorHelpers::FObjectFinder<UInputAction> InputChangeActionControlRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ChangeControl.IA_ChangeControl'"));
	if (nullptr != InputChangeActionControlRef.Object)
	{
		ChangeControlAction = InputChangeActionControlRef.Object;
	}

	// ShoulderMove 액션에 대해서
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionShoulderMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ShoulderMove.IA_ShoulderMove'"));
	if (nullptr != InputActionShoulderMoveRef.Object)
	{
		ShoulderMoveAction = InputActionShoulderMoveRef.Object;
	}
	// ShoulderLook 액션에 대해서
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionShoulderLookRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ShoulderLook.IA_ShoulderLook'"));
	if (nullptr != InputActionShoulderLookRef.Object)
	{
		ShoulderLookAction = InputActionShoulderLookRef.Object;
	}

	// QuaterMove 액션에 대해서
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionQuaterMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_QuaterMove.IA_QuaterMove'"));
	if (nullptr != InputActionQuaterMoveRef.Object)
	{
		QuaterMoveAction = InputActionQuaterMoveRef.Object;
	}

	// Attack 액션에 대해서
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionAttackRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Attack.IA_Attack'"));
	if (nullptr != InputActionAttackRef.Object)
	{
		AttackAction = InputActionAttackRef.Object;
	}

	// 현재 어떤 컨트롤타입을 가지고 있는지에 대한 열거형 변수 = 쿼터뷰로 초기화
	CurrentCharacterControlType = ECharacterControlType::Quater;
}

void AABCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();

	// 입력을 켜주는 기능 추가
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		EnableInput(PlayerController);
	}

	SetChangeCharacterControl(CurrentCharacterControlType);
}

// 죽었을 때 (ABCharacterBase)
// 죽었으니 움직임 제한시켜주면서 죽는 애니메이션 재생 + 콜리전 기능 제한 등의 기능이 구현되어 있다.
void AABCharacterPlayer::SetDead()
{
	Super::SetDead();

	// + 입력을 끄는 기능 추가
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		DisableInput(PlayerController);

		// 플레이어가 죽으면 게임이 종료되도록 GameMode를 통해 전달하기
		IABGameInterface* ABGameMode = Cast<IABGameInterface>(GetWorld()->GetAuthGameMode());
		if (ABGameMode)
		{
			ABGameMode->OnPlayerDead();
		}
	}
}

void AABCharacterPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);		// 만약 EnhancedInputComponent를 사용하지 않으면 에러를 발생하도록 CastChecked 함수를 사용

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	EnhancedInputComponent->BindAction(ChangeControlAction, ETriggerEvent::Completed, this, &AABCharacterPlayer::ChangeCharacterControl);		// 뷰를 바꾸는 액션
	EnhancedInputComponent->BindAction(ShoulderMoveAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::ShoulderMove);
	EnhancedInputComponent->BindAction(ShoulderLookAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::ShoulderLook);
	EnhancedInputComponent->BindAction(QuaterMoveAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::QuaterMove);
	EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::Attack);		// 입력 Attack액션이 발동되었을 때, Attack함수 바인딩
}

// V키를 눌러서 컨트롤러를 바꾸는 것을 구현하는 함수
void AABCharacterPlayer::ChangeCharacterControl()
{
	// 쿼터뷰일때는 숄더뷰로, 숄더뷰일때는 쿼터뷰로
	if (CurrentCharacterControlType == ECharacterControlType::Quater)
	{
		SetChangeCharacterControl(ECharacterControlType::Shoulder);
	}
	else if (CurrentCharacterControlType == ECharacterControlType::Shoulder)
	{
		SetChangeCharacterControl(ECharacterControlType::Quater);
	}
}

// 실제로 변경이 발생했을 때, 컨트롤에 관련된 모든 설정을 진행해주는 함수
void AABCharacterPlayer::SetChangeCharacterControl(ECharacterControlType NewCharacterControlType)
{
	// 상위클래스에 선언된 컨트롤매니저(CharacterControlData)에서 컨트롤 데이터 애셋 가져오기
	UABCharacterControlData* NewCharacterControl = CharacterControlManager[NewCharacterControlType];

	// check 함수를 통해 진짜 있는지 확인
	check(NewCharacterControl);

	// 기본 속성 호출
	SetCharacterControlData(NewCharacterControl);

	// 인풋 매핑 컨텍스트 변경시켜주기
	// 반드시 가져와야하기 때문에 CastChecked 함수 사용
	APlayerController* PlayerController = CastChecked<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		// 바꿔치기할 때 기존에 있던 모든 인풋 매핑 컨텍스트를 모두 제거후 변경할 인풋 매핑 컨텍스트로 적용
		Subsystem->ClearAllMappings();
		UInputMappingContext* NewMappingContext = NewCharacterControl->InputMappingContext;
		if (NewMappingContext)
		{
			Subsystem->AddMappingContext(NewMappingContext, 0);
		}
	}

	// 현재 컨트롤 타입을 새로운 컨트롤 데이터 타입으로 변경
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

	const FRotator Rotation = Controller->GetControlRotation();		// 업데이트 된 Rotation 값을 가져와서
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);		// 전진 방향
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);			// 오른쪽 방향

	AddMovementInput(ForwardDirection, MovementVector.X);		// 캐릭터를 이동시키도록 구현
	AddMovementInput(RightDirection, MovementVector.Y);			// 캐릭터를 이동시키도록 구현
}

void AABCharacterPlayer::ShoulderLook(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);		// 입력값을 받아서 Controller의 Control Rotation 속성을 업데이트하는데 사용된다.
	AddControllerPitchInput(LookAxisVector.Y);
}

// Quater
void AABCharacterPlayer::QuaterMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	float InputSizeSquared = MovementVector.SquaredLength();		// 현재 MovementVector 받기

	float MovementVectorSize = 1.0f;
	float MovementVectorSizeSquared = MovementVector.SquaredLength();

	// MovementVector 크기가 1이 되도록 조정
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
	// 현재 ControlRotation을 지금 Forward 방향(MoveDirection)으로 사용해서 지정해주면, 무브먼트 컴포넌트에서 설정한 옵션에 의해서 캐릭터가 자동으로 이동하는 방향으로 회전하게 된다.
	GetController()->SetControlRotation(FRotationMatrix::MakeFromX(MoveDirection).Rotator());
	AddMovementInput(MoveDirection, MovementVectorSize);
}

// Attack
void AABCharacterPlayer::Attack()
{
	ProcessComboCommand();
}

// SetupHUDWidget
void AABCharacterPlayer::SetupHUDWidget(UABHUDWidget* InHUDWidget)
{
	if (InHUDWidget)
	{
		// Getter함수를 통해 업데이트
		InHUDWidget->UpdateStat(Stat->GetBaseStat(), Stat->GetModifierStat());
		InHUDWidget->UpdateHpBar(Stat->GetCurrentHp());

		// ABHUDWidget의 업데이트함수들을 바인드
		Stat->OnStatChanged.AddUObject(InHUDWidget, &UABHUDWidget::UpdateStat);
		Stat->OnHpChanged.AddUObject(InHUDWidget, &UABHUDWidget::UpdateHpBar);
	}
}
