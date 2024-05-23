// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/ABAnimationAttackInterface.h"
#include "Interface/ABCharacterWidgetInterface.h"
#include "Interface/ABCharacterItemInterface.h"
#include "ABCharacterBase.generated.h"

// Ȯ�ο� �α�
DECLARE_LOG_CATEGORY_EXTERN(LogABCharacter, Log, All);

UENUM()
enum class ECharacterControlType : uint8
{
	Shoulder,
	Quater
};

// �������� ó���� �� �ְ� ��������Ʈ ����
// �ش� ��������Ʈ�� ��� �ټ��� �迭�� �����Ϸ��� �Ѵ�. �̰� ��ü�� ���ڷ� �� ���� ����.
// �̰��� �迭�� �����ϱ����ؼ� ���� ����� �̰��� ���δ� ����ü�� �ϳ� ����� �ִ°�
DECLARE_DELEGATE_OneParam(FOnTakeItemDelegate, class UABItemData* /*InItemData*/);

USTRUCT(BlueprintType)
struct FTakeItemDelegateWrapper
{
	GENERATED_BODY()
	FTakeItemDelegateWrapper(){}		// ������
	FTakeItemDelegateWrapper(const FOnTakeItemDelegate& InItemDelegate) : ItemDelegate(InItemDelegate){}		// ���ڸ� �޴� ������
	
	FOnTakeItemDelegate ItemDelegate;
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter, public IABAnimationAttackInterface, public IABCharacterWidgetInterface, public IABCharacterItemInterface		// �������̽� ���
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABCharacterBase();		// ������

	// BeginPlay()�� ���۵Ǳ� ���� Stat�� ��������Ʈ�� ����ؼ� �׾����� �״� ����� �����ϵ��� ó��
	virtual void PostInitializeComponents() override;	

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
	TObjectPtr<class UABWidgetComponent> HpBar;

	// �������̽��� ��ӹ޾�����, �ǹ������� ����� �����ؾ� ��
	virtual void SetupCharacterWidget(class UABUserWidget* InUserWidget) override;

// Item Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Equipment, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USkeletalMeshComponent> Weapon;

	//FTakeItemDelegateWrapper�� �������� �� �ִ� �迭 ���� (TakeItemActions)
	UPROPERTY()
	TArray<FTakeItemDelegateWrapper> TakeItemActions;

	virtual void TakeItem(class UABItemData* InItemData) override;
	// TakeItemActions�� ���ε��� �Լ���
	virtual void DrinkPostion(class UABItemData* InItemData);
	virtual void EquipWeapon(class UABItemData* InItemData);
	virtual void ReadScroll(class UABItemData* InItemData);
};
