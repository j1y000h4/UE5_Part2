// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterBase.h"
#include "Components/CapsuleComponent.h"					// 캡슐 컴포넌트
#include "GameFramework/CharacterMovementComponent.h"		// 무브먼트 컴포넌트
#include "ABCharacterControlData.h"
#include "Animation/AnimMontage.h"
#include "ABComboActionData.h"								// 에셋에 저장되어 있는 각 프레임 정보, 인덱스가 유효한지 검사를 위한
#include "Physics/ABCollision.h"							// 전처리기용 파일 인클루드
#include "Engine/DamageEvents.h"							// 데미지 종류를 위한
#include "CharacterStat/ABCharacterStatComponent.h"			// StatComponent 추가
#include "UI/ABWidgetComponent.h"							// WidgetComponent 추가 -> ABWidgetComponent로 변경
#include "UI/ABHpBarWidget.h"								// HpBar를 사용하기위해 헤더로 추가
#include "Item/ABWeaponItemData.h"

// 확인용 로그
DEFINE_LOG_CATEGORY(LogABCharacter);

// Sets default values
AABCharacterBase::AABCharacterBase()		// 생성자
{
	// Pawn 설정
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Capsule 설정
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->SetCollisionProfileName(CPROFILE_ABCAPSULE);		// Profile 수정

	// Movement 설정
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700.0f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Mesh 설정
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetCollisionProfileName(TEXT("NoCollision"));		// Profile 수정

	// 메쉬 지정
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'"));
	if (CharacterMeshRef.Object)
	{
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
	}

	// 애니메이션 지정
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassRef(TEXT("/Game/ArenaBattle/Animation/ABP_ABCharacter.ABP_ABCharacter_C"));
	if (AnimInstanceClassRef.Class)
	{
		GetMesh()->SetAnimInstanceClass(AnimInstanceClassRef.Class);
	}

	// TMap 자료구조를 생성자에서 완성 시키기
	static ConstructorHelpers::FObjectFinder<UABCharacterControlData> ShoulderDataRef(TEXT("/Script/ArenaBattle.ABCharacterControlData'/Game/ArenaBattle/CharacterControl/ABC_Shoulder.ABC_Shoulder'"));
	if (ShoulderDataRef.Object)
	{
		CharacterControlManager.Add(ECharacterControlType::Shoulder, ShoulderDataRef.Object);
	}

	static ConstructorHelpers::FObjectFinder<UABCharacterControlData> QuaterDataRef(TEXT("/Script/ArenaBattle.ABCharacterControlData'/Game/ArenaBattle/CharacterControl/ABC_Quater.ABC_Quater'"));
	if (QuaterDataRef.Object)
	{
		CharacterControlManager.Add(ECharacterControlType::Quater, QuaterDataRef.Object);
	}

	// 기본 에셋에 대한 기본값들 설정하기
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ComboActionMontageRef(TEXT("/Script/Engine.AnimMontage'/Game/ArenaBattle/Animation/AM_ComboAttack.AM_ComboAttack'"));
	if (ComboActionMontageRef.Object)
	{
		ComboActionMontage = ComboActionMontageRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UABComboActionData> ComboActionDataRef(TEXT("/Script/ArenaBattle.ABComboActionData'/Game/ArenaBattle/CharacterAction/ABA_ComboAttack.ABA_ComboAttack'"));
	if (ComboActionDataRef.Object)
	{
		ComboActionData = ComboActionDataRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> DeamMontageRef(TEXT("/Script/Engine.AnimMontage'/Game/ArenaBattle/Animation/AM_Dead.AM_Dead'"));
	if (DeamMontageRef.Object)
	{
		DeadMontage = DeamMontageRef.Object;
	}

	// Stat Component
	Stat = CreateDefaultSubobject<UABCharacterStatComponent>(TEXT("Stat"));

	// Widget Component
	// UWidgetComponent는 트랜스폼을 가지고 있는 컴포넌트라서 트랜스폼을 설정해줘야 한다.
	// UABWidgetComponent로 변경
	HpBar = CreateDefaultSubobject<UABWidgetComponent>(TEXT("Widget"));
	HpBar->SetupAttachment(GetMesh());
	HpBar->SetRelativeLocation(FVector(0.0f, 0.0f, 180.0f));

	static ConstructorHelpers::FClassFinder<UUserWidget> HpBarWidgetRef(TEXT("/Game/ArenaBattle/UI/WBP_HpBar.WBP_HpBar_C"));

	if (HpBarWidgetRef.Class)
	{
		HpBar->SetWidgetClass(HpBarWidgetRef.Class);
		HpBar->SetWidgetSpace(EWidgetSpace::Screen);		// 2D 스크린으로 공간 정의
		HpBar->SetDrawSize(FVector2D(150.0f, 15.0f));		// 캔버스의 작업공간의 크기 설정
		HpBar->SetCollisionEnabled(ECollisionEnabled::NoCollision);		// UI 충돌설정 해제
	}

	// Item Action
	// 인자를 받는 생성자에 즉석에서 생성해서 TakeItemActions 배열에 집어넣기 (열거형 순)
	TakeItemActions.Add(FTakeItemDelegateWrapper(FOnTakeItemDelegate::CreateUObject(this, &AABCharacterBase::EquipWeapon)));
	TakeItemActions.Add(FTakeItemDelegateWrapper(FOnTakeItemDelegate::CreateUObject(this, &AABCharacterBase::DrinkPostion)));
	TakeItemActions.Add(FTakeItemDelegateWrapper(FOnTakeItemDelegate::CreateUObject(this, &AABCharacterBase::ReadScroll)));

	// Weapon Component
	// Weapon을 만들어준뒤, 캐릭터의 Hand_rSocket이라는 조인트에 Attach해준다.
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), TEXT("hand_rSocket"));
}

void AABCharacterBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// Stat의 OnHpZero 델리게이트가 실행되면 SetDead 함수를 통해서 죽는 애니메이션이 재생될 수 있도록 설정
	Stat->OnHpZero.AddUObject(this, &AABCharacterBase::SetDead);
}

void AABCharacterBase::SetCharacterControlData(const UABCharacterControlData* CharacterControlData)
{
	// Pawn
	bUseControllerRotationYaw = CharacterControlData->bUseControllerRotationYaw;

	// CharacterMovement
	GetCharacterMovement()->bOrientRotationToMovement = CharacterControlData->bOrientRotationToMovement;
	GetCharacterMovement()->bUseControllerDesiredRotation = CharacterControlData->bUseControllerDesiredRotation;
	GetCharacterMovement()->RotationRate = CharacterControlData->RotationRate;
}

void AABCharacterBase::ProcessComboCommand()
{
	if (CurrentCombo == 0)
	{
		// 콤보가 시작되면 리턴
		ComboActionBegin();
		return;
	}

	// ComboTimerHandle가 유효한가? 실행중인가?
	if (!ComboTimerHandle.IsValid())
	{
		HasNextComboCommand = false;
	}
	else
	{
		HasNextComboCommand = true;
	}
}

// 콤보 시작
void AABCharacterBase::ComboActionBegin()
{
	// Combo Status
	CurrentCombo = 1;

	// Movement Setting
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);		// Move_None으로 설정하면 움직임이 없도록 설정할 수 있음

	// Animation Setting
	const float AttackSpeedRate = 1.0f;

	// 스켈레탈 메쉬의 GetAnimInstance 함수를 호출하여 AnimInstance에 대한 포인터 가져오기
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	AnimInstance->Montage_Play(ComboActionMontage, AttackSpeedRate);		// 몽타주 재생

	FOnMontageEnded EndDelegate;
	EndDelegate.BindUObject(this, &AABCharacterBase::ComboActionEnd);
	AnimInstance->Montage_SetEndDelegate(EndDelegate, ComboActionMontage);		// 바인딩된 함수 EndDelegate와 ComboActionMontage를 넘겨주어 바인딩 된 AABCharacterBase::ComboActionEnd 함수가 실행되도록

	// 콤보 타이머 무효화후, 콤보 타이머 시작
	ComboTimerHandle.Invalidate();
	SetComboCheckTimer();
}

// 콤보 끝
void AABCharacterBase::ComboActionEnd(UAnimMontage* TargetMontage, bool IsProperlyEnded)
{
	// Assertion 함수를 사용해서 몽타주가 끝날땐 CurrentCombo가 절때 0이 될 수 없으니, 검증 + 0이 나오면 에러
	ensure(CurrentCombo != 0);
	CurrentCombo = 0;
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);			// 다시 움직임 가능하게 변경
}

// 콤보 타이머를 발동시키는 함수
void AABCharacterBase::SetComboCheckTimer()
{
	int32 ComboIndex = CurrentCombo - 1;
	ensure(ComboActionData->EffectiveFrameCount.IsValidIndex(ComboIndex));

	// 콤보가 가능한 타이밍의 시간 정의 로직
	const float AttackSpeedRate = 1.0f;
	float ComboEffectiveTime = (ComboActionData->EffectiveFrameCount[ComboIndex] / ComboActionData->FrameRate) / AttackSpeedRate;

	if (ComboEffectiveTime > 0.0f)
	{
		GetWorld()->GetTimerManager().SetTimer(ComboTimerHandle, this, &AABCharacterBase::ComboCheck, ComboEffectiveTime, false);
	}
}

// 타이머가 발동했을 때 입력이 들어왔는지 체크하는 함수
void AABCharacterBase::ComboCheck()
{
	// 타이머 초기화
	ComboTimerHandle.Invalidate();
	// 입력이 들어왔다면
	if (HasNextComboCommand)
	{
		// AnimInstance 가져오기
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

		CurrentCombo = FMath::Clamp(CurrentCombo + 1, 1, ComboActionData->MaxComboCount);

		// 재생할 세션 이름 정의후 해당 애니메이션 몽타주로 점프
		FName NextSection = *FString::Printf(TEXT("%s%d"), *ComboActionData->MontageSectionPrefix, CurrentCombo);
		AnimInstance->Montage_JumpToSection(NextSection, ComboActionMontage);

		// 다시 콤보 발동
		SetComboCheckTimer();
		HasNextComboCommand = false;
	}
}

// 트레이스 채널을 체크해 물체가 서로 충돌되는 지를 검사하는 로직
void AABCharacterBase::AttackHitCheck()
{
	FHitResult OutHitResult;

	// 1. 콜리전을 분석할때 어떤 태그 정보로 분석할 때 식별자 정보로 사용이 되는 인자.
	// 2. 복잡한 형태의 콜리전을 대상으로 감지할 것인가
	// 3. 무시할 인자들
	FCollisionQueryParams Params(SCENE_QUERY_STAT(Attack), false, this);

	const float AttackRange = 40.0f;
	const float AttackRadius = 50.0f;
	const float AttackDamage = 30.0f;
	const FVector Start = GetActorLocation() + GetActorForwardVector() * GetCapsuleComponent()->GetScaledCapsuleRadius();
	const FVector End = Start + GetActorForwardVector() * AttackRange;

	// SweepSingleByChannel과 같은 함수는 월드가 제공하는 서비스이기 때문에 GetWorld를 통해 포인터를 가져와준다.
	bool HitDetected = GetWorld()->SweepSingleByChannel(OutHitResult, Start, End, FQuat::Identity, CCHANNEL_ABACTION, FCollisionShape::MakeSphere(AttackRadius), Params);

	// 충돌판정이 난다면 데미지 전달해주기
	if (HitDetected)
	{
		// #include "Engine/DamageEvents.h"
		FDamageEvent DamageEvent;
		OutHitResult.GetActor()->TakeDamage(AttackDamage, DamageEvent, GetController(), this);
	}

#if ENABLE_DRAW_DEBUG

	FVector CapsuleOrigin = Start + (End - Start) * 0.5f;
	float CapsuleHalfHeight = AttackRange * 0.5f;

	// 충돌했으면 Green / 충돌하지않았으면 Red
	FColor DrawColor = HitDetected ? FColor::Green : FColor::Red;

	// FRotationMatrix ~ : 시선 방향으로 눕히기
	DrawDebugCapsule(GetWorld(), CapsuleOrigin, CapsuleHalfHeight, AttackRadius, FRotationMatrix::MakeFromZ(GetActorForwardVector()).ToQuat(), DrawColor, false, 5.0f);

#endif
}

// 데미지를 주는 로직을 가진 함수
float AABCharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// EventInstigator - 나에게 피해를 입힌 가해자
	// DamageCauser - 피해를 입힌 가해자가 사용한 무기라던지 아니면 가해자가 빙의한 폰, 액터 정보들
	// 만약 피해를 받는 나에게 방어력이 설정되어 있다면, 여기서 들어온 데미지를 경감시켜서 최종값으로 리턴하면 된다.
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	//SetDead();
	Stat->ApplyDamage(DamageAmount);

	return DamageAmount;
}

// 죽은 상태를 설정하는 함수
void AABCharacterBase::SetDead()
{
	// 죽었으니 움직임 제한시켜주면서 죽는 애니메이션 재생 + 콜리전 기능 제한
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	PlayDeadAnimation();
	SetActorEnableCollision(false);

	HpBar->SetHiddenInGame(true);
}

// 죽는 애니메이션 몽타주를 재생하는 함수
void AABCharacterBase::PlayDeadAnimation()
{
	// AnimInstance 가져오기 + 모든 애니메이션 몽타주 중지 시키고 죽는 애니메이션 재생하기
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	AnimInstance->StopAllMontages(0.0f);;
	AnimInstance->Montage_Play(DeadMontage, 1.0f);
}

void AABCharacterBase::SetupCharacterWidget(UABUserWidget* InUserWidget)
{
	UABHpBarWidget* HpBarWidget = Cast<UABHpBarWidget>(InUserWidget);
	if (HpBarWidget)
	{
		// 위젯을 업데이트
		HpBarWidget->SetMaxHp(Stat->GetMaxHp());
		HpBarWidget->UpdateHpBar(Stat->GetCurrentHp());

		// 앞으로 Stat의 CurrentHp 값이 변경될 때마다 이 UpdateHpBar 함수가 호출되도록 Stat의 델리게이트에 해당 인스턴스의 멤버함수를 등록하도록 -> 두 컴포넌트간의 느슨한 결합
		Stat->OnHpChanged.AddUObject(HpBarWidget, &UABHpBarWidget::UpdateHpBar);
	}
}

// 아이템데이터를 인터페이스로부터 받았을때
void AABCharacterBase::TakeItem(UABItemData* InItemData)
{
	if (InItemData)
	{
		// Type을 가져오기 위해 #inlcude "Item/ABWeaponItemData"
		// ExecuteIfBound를 통해 해당 아이템 넘겨주기
		TakeItemActions[(uint8)InItemData->Type].ItemDelegate.ExecuteIfBound(InItemData);
	}
}

void AABCharacterBase::DrinkPostion(UABItemData* InItemData)
{
	//UE_LOG(LogABCharacter, Log, TEXT("Drink Potion"));
}

void AABCharacterBase::EquipWeapon(UABItemData* InItemData)
{
	//UE_LOG(LogABCharacter, Log, TEXT("Equip Weapon"));

	// ABItemData인 InItemData를 ABWeaponItemData로 캐스팅해준뒤, 올바른 캐스팅이라면 Weapon의 스켈레탈 메쉬를 WeaponItemData의 WeaponMesh로 변경해준다.
	UABWeaponItemData* WeaponItemData = Cast<UABWeaponItemData>(InItemData);
	if (WeaponItemData)
	{
		// 아직 로딩이 되지 않았다면
		if (WeaponItemData->WeaponMesh.IsPending())
		{
			// LoadSynchronous()를 통해 로딩
			WeaponItemData->WeaponMesh.LoadSynchronous();
		}
		//Weapon->SetSkeletalMesh(WeaponItemData->WeaponMesh);
		Weapon->SetSkeletalMesh(WeaponItemData->WeaponMesh.Get());
	}
}

void AABCharacterBase::ReadScroll(UABItemData* InItemData)
{
	//UE_LOG(LogABCharacter, Log, TEXT("Read Scroll"));
}

