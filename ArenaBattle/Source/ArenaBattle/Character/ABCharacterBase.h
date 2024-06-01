// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/ABAnimationAttackInterface.h"
#include "Interface/ABCharacterWidgetInterface.h"
#include "Interface/ABCharacterItemInterface.h"
#include "ABCharacterBase.generated.h"

// 확인용 로그
DECLARE_LOG_CATEGORY_EXTERN(LogABCharacter, Log, All);

UENUM()
enum class ECharacterControlType : uint8
{
	Shoulder,
	Quater
};

// 아이템을 처리할 수 있게 델리게이트 선언
// 해당 델리게이트의 경우 다수를 배열로 관리하려고 한다. 이것 자체를 인자로 쓸 수가 없다.
// 이것을 배열로 관리하기위해서 쉬운 방법은 이것을 감싸는 구조체를 하나 만들어 주는것
DECLARE_DELEGATE_OneParam(FOnTakeItemDelegate, class UABItemData* /*InItemData*/);

USTRUCT(BlueprintType)
struct FTakeItemDelegateWrapper
{
	GENERATED_BODY()
	FTakeItemDelegateWrapper(){}		// 생성자
	FTakeItemDelegateWrapper(const FOnTakeItemDelegate& InItemDelegate) : ItemDelegate(InItemDelegate){}		// 인자를 받는 생성자
	
	FOnTakeItemDelegate ItemDelegate;
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter, public IABAnimationAttackInterface, public IABCharacterWidgetInterface, public IABCharacterItemInterface		// 인터페이스 상속
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABCharacterBase();		// 생성자

	// BeginPlay()가 시작되기 전에 Stat의 델리게이트를 등록해서 죽었을때 죽는 모션을 수행하도록 처리
	virtual void PostInitializeComponents() override;	

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
	virtual void NotifyComboActionEnd();		// 몽타주 없이 공격이 끝났는지를 파악하기 위한 함수
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
	TObjectPtr<class UABWidgetComponent> HpBar;

	// 인터페이스를 상속받았으니, 의무적으로 기능을 구현해야 함
	virtual void SetupCharacterWidget(class UABUserWidget* InUserWidget) override;

// Item Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Equipment, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USkeletalMeshComponent> Weapon;

	//FTakeItemDelegateWrapper를 관리해줄 수 있는 배열 선언 (TakeItemActions)
	UPROPERTY()
	TArray<FTakeItemDelegateWrapper> TakeItemActions;

	virtual void TakeItem(class UABItemData* InItemData) override;
	// TakeItemActions에 바인딩될 함수들
	virtual void DrinkPostion(class UABItemData* InItemData);
	virtual void EquipWeapon(class UABItemData* InItemData);
	virtual void ReadScroll(class UABItemData* InItemData);

	// Stat Section
public:
	int32 GetLevel();
	void SetLevel(int32 InNewLevel);
};
