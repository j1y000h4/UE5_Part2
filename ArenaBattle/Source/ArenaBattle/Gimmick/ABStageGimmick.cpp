// Fill out your copyright notice in the Description page of Project Settings.


#include "Gimmick/ABStageGimmick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Physics/ABCollision.h"
#include "Character/ABCharacterNonPlayer.h"
#include "Item/ABItemBox.h"

// Sets default values
AABStageGimmick::AABStageGimmick()
{
	// Stage Section
	Stage = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stage"));
	RootComponent = Stage;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StageMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Stages/SM_SQUARE.SM_SQUARE'"));
	if (StageMeshRef.Object)
	{
		Stage->SetStaticMesh(StageMeshRef.Object);
	}

	// Trigger를 만든 뒤, 영역 범위와 위치를 지정, TriggerProfileName 설정, Trigger와 Overlap되었을때 발생할 함수를 바인딩
	StageTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("StageTrigger"));
	StageTrigger->SetBoxExtent(FVector(775.0f, 775.0f, 300.0f));
	StageTrigger->SetupAttachment(Stage);
	StageTrigger->SetRelativeLocation(FVector(0.0f, 0.0f, 250.0f));
	StageTrigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
	StageTrigger->OnComponentBeginOverlap.AddDynamic(this, &AABStageGimmick::OnStageTriggerBeginOverlap);

	// Gate Section
	static FName GateSockets[] = { TEXT("+XGate"), TEXT("-XGate"), TEXT("+YGate"),TEXT("-YGate") };
	static ConstructorHelpers::FObjectFinder<UStaticMesh> GateMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Props/SM_GATE.SM_GATE'"));
	for (FName GateSocket : GateSockets)
	{
		UStaticMeshComponent* Gate = CreateDefaultSubobject<UStaticMeshComponent>(GateSocket);
		Gate->SetStaticMesh(GateMeshRef.Object);
		// SetupAttachment()에서 특이하게 소켓을 지정하고 있는데, 소켓으로 위치를 조정하면 살짝만 조정해서 문의 위치를 정확하게 배치할 수 있다.
		Gate->SetupAttachment(Stage, GateSocket);
		Gate->SetRelativeLocation(FVector(0.0f, -80.5f, 0.0f));
		Gate->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
		// TMap에 Gates를 추가
		Gates.Add(GateSocket, Gate);

		// 객체를 생성할 때 다른 이름을 가져와야 되기 때문에 GateSocket을 String으로 변환 후 Trigger라는 표현 추가하기
		FName TriggerName = *GateSocket.ToString().Append(TEXT("Trigger"));
		UBoxComponent* GateTrigger = CreateDefaultSubobject<UBoxComponent>(TriggerName);
		GateTrigger->SetBoxExtent(FVector(100.0f, 100.0f, 300.0f));
		GateTrigger->SetupAttachment(Stage, GateSocket);
		GateTrigger->SetRelativeLocation(FVector(70.0f, 0.0f, 250.0f));
		GateTrigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
		GateTrigger->OnComponentBeginOverlap.AddDynamic(this, &AABStageGimmick::OnGateTriggerBeginOverlap);
		// 태그 추가
		GateTrigger->ComponentTags.Add(GateSocket);

		GateTriggers.Add(GateTrigger);
	}

	// State Section
	// 생성자에서 초기화
	CurrentState = EStageState::READY;
	// 열거형 값에 따라 연동
	StateChangeActions.Add(EStageState::READY, FStageChangedDelegateWrapper(FOnStageChangedDelegate::CreateUObject(this, &AABStageGimmick::SetReady)));
	StateChangeActions.Add(EStageState::FIGHT, FStageChangedDelegateWrapper(FOnStageChangedDelegate::CreateUObject(this, &AABStageGimmick::SetFight)));
	StateChangeActions.Add(EStageState::REWARD, FStageChangedDelegateWrapper(FOnStageChangedDelegate::CreateUObject(this, &AABStageGimmick::SetChooseReward)));
	StateChangeActions.Add(EStageState::NEXT, FStageChangedDelegateWrapper(FOnStageChangedDelegate::CreateUObject(this, &AABStageGimmick::SetChooseNext)));

	// Fight Section
	OpponentSpawnTime = 2.0f;
	OpponentClass = AABCharacterNonPlayer::StaticClass();

	// Reward Section
	RewardBoxClass = AABItemBox::StaticClass();
	for (FName GateSocket : GateSockets)
	{
		FVector BoxLocation = Stage->GetSocketLocation(GateSocket) / 2;
		RewardBoxLocations.Add(GateSocket, BoxLocation);
	}
}

// 에디터에서 값을 변경하면 실행되는 함수
void AABStageGimmick::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	SetState(CurrentState);
}

// 중앙에 위치한 스테이지 트리거가 발동된다면
void AABStageGimmick::OnStageTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	SetState(EStageState::FIGHT);
}

// 게이트의 트리거가 발동된다면
void AABStageGimmick::OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 태그를 단 컴포넌트에는 태그가 하나 설정되어 있을 것이다. check함수를 통해서 강력하게 검사
	check(OverlappedComponent->ComponentTags.Num() == 1);
	// 태그 가져와서 왼쪽의 2글자 Split
	FName ComponentTag = OverlappedComponent->ComponentTags[0];
	FName SocketName = FName(*ComponentTag.ToString().Left(2));
	// check 함수를 통해서 다시 체크
	check(Stage->DoesSocketExist(SocketName));

	// 해당 위치를 소켓 이름을 통해서 얻어내기
	FVector NewLocation = Stage->GetSocketLocation(SocketName);

	// 해당 위치를 가져왔지만, 그 자리에 자신을 제외한 무언가 있는지 확인하기 위함
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(SCENE_QUERY_STAT(GateTrigger), false, this);

	// OverlapMultiByObjectType()을 통해 해당 위치에 무언가가 배치되어 있는지 검사
	// MakeSphere()를 통해 원을 그린뒤, AllStaticObjects 타입에 대해서 자신을 제외한 상태에서 검사하였을 때
	bool bResult = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,
		NewLocation,
		FQuat::Identity,
		FCollisionObjectQueryParams::InitType::AllStaticObjects,
		FCollisionShape::MakeSphere(775.0f),
		CollisionQueryParam
	);

	// 아무것도 없다고 판정되었을 때
	if (!bResult)
	{
		GetWorld()->SpawnActor<AABStageGimmick>(NewLocation, FRotator::ZeroRotator);
	}
}

void AABStageGimmick::OpenAllGates()
{
	for (auto Gate : Gates)
	{
		(Gate.Value)->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	}
}

void AABStageGimmick::CloseAllGates()
{
	for (auto Gate : Gates)
	{
		(Gate.Value)->SetRelativeRotation(FRotator::ZeroRotator);
	}
}

void AABStageGimmick::SetState(EStageState InNewState)
{
	// 원래는 Switch문으로 구성하기도 하지만, 상태가 점점 늘어날 수록 굉장히 복잡해 보인다.
	// 그래서 델리게이트 어레이로 함수 포인터를 사용해서 구성하는 방법도 있다.

	// 바뀐 상태로 업데이트
	CurrentState = InNewState;

	// InNewState라는 상태가 자료구조 맵 구조안에 있다면~
	if (StateChangeActions.Contains(InNewState))
	{
		// 해당 델리게이트가 바인딩되어 있으면 실행하도록
		// 각 열거형 값에 따라 함수들이 호출된다.
		StateChangeActions[CurrentState].StageDelegate.ExecuteIfBound();
	}
}

void AABStageGimmick::SetReady()
{
	// Player와의 충돌을 위한 Trigger 콜리전 활성화
	StageTrigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
	// Gate는 Trigger 콜리전이 활성화될 필요가 없다.
	for (auto GateTrigger : GateTriggers)
	{
		GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	}

	OpenAllGates();
}

void AABStageGimmick::SetFight()
{
	// StageTrigger는 콜리전이 활성화될 필요가 없다.
	StageTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	// Gate는 Trigger 콜리전이 활성화될 필요가 없다.
	for (auto GateTrigger : GateTriggers)
	{
		GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	}

	CloseAllGates();

	// 문이 모두 닫히고 나면~
	GetWorld()->GetTimerManager().SetTimer(OpponentTimerHandle, this, &AABStageGimmick::OnOpponentSpawn, OpponentSpawnTime, false);
}

void AABStageGimmick::SetChooseReward()
{
	// StageTrigger는 콜리전이 활성화될 필요가 없다.
	StageTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	// Gate는 Trigger 콜리전이 활성화될 필요가 없다.
	for (auto GateTrigger : GateTriggers)
	{
		GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	}

	CloseAllGates();
	SpawnRewardBoxes();
}

void AABStageGimmick::SetChooseNext()
{
	// StageTrigger는 콜리전이 활성화될 필요가 없다.
	StageTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	// Gate는 Trigger 콜리전이 활성화될 필요가 없다.
	for (auto GateTrigger : GateTriggers)
	{
		GateTrigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
	}

	OpenAllGates();
}

// NPC가 죽었을 때
void AABStageGimmick::OnOpponentDestroyed(AActor* DestoryedActor)
{
	SetState(EStageState::REWARD);
}

// NPC 소환
void AABStageGimmick::OnOpponentSpawn()
{
	const FVector SpawnLocation = GetActorLocation() + FVector::UpVector * 88.0f;
	// OpponentClass를 TSubclassOf로 한정시켰기 때문에 캐릭터에 있는 ABCharacterNonPlayer를 상속받은 캐릭터에 한정해서만 액터를 스폰시키게 된다.
	AActor* OpponentActor = GetWorld()->SpawnActor(OpponentClass, &SpawnLocation, &FRotator::ZeroRotator);
	AABCharacterNonPlayer* ABOpponentCharacter = Cast<AABCharacterNonPlayer>(OpponentActor);

	// 캐스팅이 정상적으로 된다면, OnDestroyed 델리게이트에 함수를 바인드
	if (ABOpponentCharacter)
	{
		ABOpponentCharacter->OnDestroyed.AddDynamic(this, &AABStageGimmick::OnOpponentDestroyed);
	}
}

// Reward와 충돌했을 때
// 상자를 획득했을 때 실행됨
void AABStageGimmick::OnRewardTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 약참조 된 RewardBoxes 순회
	for (const auto& RewardBox : RewardBoxes)
	{
		// IsValid()함수를 통해 진짜 존재하는지 검사
		if (RewardBox.IsValid())
		{
			// 살아있다면 Get()함수를 통해 포인터 얻어오기
			AABItemBox* ValidItemBox = RewardBox.Get();
			AActor* OverlappedBox = OverlappedComponent->GetOwner();

			// 플레이어가 획득한 상자는 남기고 나머지는 다 Desroty()
			if (OverlappedBox != ValidItemBox)
			{
				ValidItemBox->Destroy();
			}
		}
	}
	
	SetState(EStageState::NEXT);
}

// 상자 스폰 로직
void AABStageGimmick::SpawnRewardBoxes()
{
	for (const auto& RewardBoxLocation : RewardBoxLocations)
	{
		// RewardBox를 스폰해준다. Location, Actor, Casting, Overlap시 발동시킬 함수 추가, 약참조 RewardBoxes에 추가
		FVector WorldSpawnLocation = GetActorLocation() + RewardBoxLocation.Value + FVector(0.0f, 0.0f, 30.0f);
		AActor* ItemActor = GetWorld()->SpawnActor(RewardBoxClass, &WorldSpawnLocation, &FRotator::ZeroRotator);
		AABItemBox* RewardBoxActor = Cast<AABItemBox>(ItemActor);
		if (RewardBoxActor)
		{
			RewardBoxActor->Tags.Add(RewardBoxLocation.Key);
			RewardBoxActor->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &AABStageGimmick::OnRewardTriggerBeginOverlap);
			RewardBoxes.Add(RewardBoxActor);
		}
	}
}
