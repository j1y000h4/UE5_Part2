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
class ARENABATTLE_API AABCharacterBase : public ACharacter, public IABAnimationAttackInterface		// �������̽� ���
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABCharacterBase();		// ������

protected:
	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData);		// Data���� �Լ�

	UPROPERTY(EditAnywhere,Category = CharacterControl, Meta = (AllowPrivateAccess = "true"))
	TMap<ECharacterControlType, class UABCharacterControlData*> CharacterControlManager;

	// Combo Action Section
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Animation)
	TObjectPtr<class UAnimMontage> ComboActionMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UABComboActionData> ComboActionData;

	void ProcessComboCommand();

	void ComboActionBegin();		// ��Ÿ�ְ� ���۵� �� ȣ��
	void ComboActionEnd(class UAnimMontage* TargetMontage, bool IsProperlyEnded);			// ��Ÿ�ְ� ��� ���ᰡ ���� �� ȣ�� / ��Ÿ�ֿ� ������ ��������Ʈ�� ���ؼ� �ٷ� ȣ��� �� �ֵ��� �Ķ���� ����
	void SetComboCheckTimer();		// Ÿ�̸Ӹ� �ߵ� ��Ŵ
	void ComboCheck();				// Ÿ�̸Ӱ� �ߵ����� �� �Է��� ���Դ��� üũ�ϴ� �Լ�

	int32 CurrentCombo = 0;		// ���� ���° �޺��� ���۵ǰ� �ִ��� üũ�� ���� (0 = ���۾���, 1�̻� = ����)
	FTimerHandle ComboTimerHandle;
	bool HasNextComboCommand;

// Attack Hit Section
protected:
	virtual void AttackHitCheck() override;
	// �𸮾� ���� ���� ����/�����Ǿ� �ִ�. (TakeDamage)
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

// Dead Section
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAnimMontage> DeadMontage;

	// �״� ���¸� �����ϴ� �Լ�
	virtual void SetDead();

	// �״� �ִϸ��̼� ��Ÿ�ָ� ����ϴ� �Լ�
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
