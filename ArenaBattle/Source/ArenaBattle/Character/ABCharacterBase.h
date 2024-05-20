// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/ABAnimationAttackInterface.h"
#include "ABCharacterBase.generated.h"

UENUM()
enum class ECharacterControlType : uint8
{
	Shoulder,
	Quater
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter, public IABAnimationAttackInterface		// 인터페이스 상속
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABCharacterBase();		// 생성자

protected:
	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData);		// Data세팅 함수

	UPROPERTY(EditAnywhere,Category = CharacterControl, Meta = (AllowPrivateAccess = "true"))
	TMap<ECharacterControlType, class UABCharacterControlData*> CharacterControlManager;

	// Combo Action Section
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Animation)
	TObjectPtr<class UAnimMontage> ComboActionMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UABComboActionData> ComboActionData;

	void ProcessComboCommand();

	void ComboActionBegin();		// 몽타주가 시작될 때 호출
	void ComboActionEnd(class UAnimMontage* TargetMontage, bool IsProperlyEnded);			// 몽타주가 모두 종료가 됐을 때 호출 / 몽타주에 설정된 델리게이트를 통해서 바로 호출될 수 있도록 파라미터 설정
	void SetComboCheckTimer();		// 타이머를 발동 시킴
	void ComboCheck();				// 타이머가 발동했을 때 입력이 들어왔는지 체크하는 함수

	int32 CurrentCombo = 0;		// 현재 몇번째 콤보가 시작되고 있는지 체크를 위한 (0 = 시작안함, 1이상 = 시작)
	FTimerHandle ComboTimerHandle;
	bool HasNextComboCommand;

// Attack Hit Section
protected:
	virtual void AttackHitCheck() override;
	// 언리얼 엔진 액터 설정/구현되어 있다. (TakeDamage)
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

// Dead Section
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAnimMontage> DeadMontage;

	// 죽는 상태를 설정하는 함수
	virtual void SetDead();

	// 죽는 애니메이션 몽타주를 재생하는 함수
	void PlayDeadAnimation();

	float DeadEventDelayTime = 5.0f;

// Stat Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UABCharacterStatComponent> Stat;

// UI Widget Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widget, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UWidgetComponent> HpBar;
};
