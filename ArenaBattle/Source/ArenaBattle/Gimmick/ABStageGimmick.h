// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABStageGimmick.generated.h"

// 원래는 상태 변경 함수등을 Switch문으로 구성하기도 하지만, 상태가 점점 늘어날 수록 굉장히 복잡해 보인다.
// 그래서 델리게이트 어레이로 함수 포인터를 사용해서 구성하는 방법도 있다.

// 델리게이트 선언
// 델리게이트를 감싸는 Wrapper구조체 선언
DECLARE_DELEGATE(FOnStageChangedDelegate)
USTRUCT(BlueprintType)
struct FStageChangedDelegateWrapper
{
	GENERATED_BODY()
	FStageChangedDelegateWrapper() {}
	FStageChangedDelegateWrapper(const FOnStageChangedDelegate& InDelegate) : StageDelegate(InDelegate) {}
	FOnStageChangedDelegate StageDelegate;
};

UENUM(BlueprintType)
enum class EStageState : uint8
{
	READY = 0,
	FIGHT,
	REWARD,
	NEXT
};

UCLASS()
class ARENABATTLE_API AABStageGimmick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABStageGimmick();

	// CurrentStageNum 관련 Getter, Setter
public:
	FORCEINLINE int32 GetStageNum() const { return CurrentStageNum; }
	FORCEINLINE void SetStageNum(int32 NewStageNum) { CurrentStageNum = NewStageNum; }

protected:
	// 에디터에서 값을 변경하면 실행되는 함수
	virtual void OnConstruction(const FTransform& Transform) override;

// Stage Section
protected:
	UPROPERTY(VisibleAnywhere, Category = Stage, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> Stage;

	UPROPERTY(VisibleAnywhere, Category = Stage, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UBoxComponent> StageTrigger;

	UFUNCTION()
	void OnStageTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

// Gate Section
protected:
	UPROPERTY(VisibleAnywhere, Category = Gate, Meta = (AllowPrivateAccess = "true"))
	TMap<FName, TObjectPtr<class UStaticMeshComponent>> Gates;

	UPROPERTY(VisibleAnywhere, Category = Gate, Meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<class UBoxComponent>> GateTriggers;

	UFUNCTION()
	void OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Gate 모든 문 열기/닫기 함수
	void OpenAllGates();
	void CloseAllGates();


// State Section
protected:
	UPROPERTY(EditAnywhere, Category = Stage, Meta = (AllowPrivateAccess = "true"))
	EStageState CurrentState;

	// 상태 변경은 언제나 SetState 함수 호출을 통해서 이루어지도록 규칙 설정
	void SetState(EStageState InNewState);

	UPROPERTY()
	TMap<EStageState, FStageChangedDelegateWrapper> StateChangeActions;

	// 상태를 바인딩할 함수들
	// 이런식으로 상태를 변화시키는 함수들을 별도로 선언하면 스위치문을 사용하지않고 각각의 함수에서 로직 전개 가능
	void SetReady();
	void SetFight();
	void SetChooseReward();
	void SetChooseNext();

// Fight Section
protected:
	// TSubclassOf - 언리얼에서 제공하는 템플릿 클래스, 지정한 클래스로부터 상속받은 클래스 목록만 표시되도록 한정해서 지정할 수 있게 기능을 제공
	// 클래스 정보를 한정시켜주는 기능을 사용해서 보다 편리하게 스폰시킬 NPC를 지정할 수 있음
	UPROPERTY(EditAnywhere, Category = Fight, Meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AABCharacterNonPlayer> OpponentClass;

	// 스폰에 딜레이를 주기위한 변수
	UPROPERTY(EditAnywhere, Category = Fight, Meta = (AllowPrivateAccess = "true"))
	float OpponentSpawnTime;

	// NPC가 죽으면 다음 보상단계로 진행하기 위한 함수
	UFUNCTION()
	void OnOpponentDestroyed(AActor* DestoryedActor);

	FTimerHandle OpponentTimerHandle;

	void OnOpponentSpawn();

// Reward Section
protected:
	// AABItemBox에 상속받은 클래스들을 대상으로 한정시키기 위해 TSubclassOf 템플릿 클래스로 타입 지정
	UPROPERTY(VisibleAnywhere, Category = Reward, Meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AABItemBox> RewardBoxClass;

	// TWeakObjectPtr(약참조)
	// RewardBoxes의 경우 스폰된 상자를 관리하기 위해서 선언한 것. 이 스폰된 상자들은 사실상 작업하고 있는 스테이지 기믹 액터와는 무관하게 자기 스스로 동작하게 된다.
	// 그래서 외부의 영향 or 내부의 로직에 의해 스스로 소멸될 수도 있다. 이 경우 TObjectPtr(강참조)로 걸게 되면 언리얼은 메모리에서 소멸시키지 않을수도 있다.
	// 액터 소멸과 함께 메모리에서 소멸되야한다면 강참조가 맞지만, 이렇게 액터와 무관하게 동작해야되는 다른 액터들의 경우 가급적 약참조를 걸어 관리하는게 좋다.
	UPROPERTY(VisibleAnywhere, Category = Reward, Meta = (AllowPrivateAccess = "true"))
	TArray<TWeakObjectPtr<class AABItemBox>> RewardBoxes;

	// Key로 관리할 수 있도록 Map 사용
	TMap<FName, FVector> RewardBoxLocations;

	UFUNCTION()
	void OnRewardTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	void SpawnRewardBoxes();

// Stage Stat
protected:
	UPROPERTY(VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	int32 CurrentStageNum;
};
