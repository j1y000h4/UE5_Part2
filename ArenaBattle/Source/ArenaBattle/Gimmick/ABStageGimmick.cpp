// Fill out your copyright notice in the Description page of Project Settings.


#include "Gimmick/ABStageGimmick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Physics/ABCollision.h"

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

	// Trigger�� ���� ��, ���� ������ ��ġ�� ����, TriggerProfileName ����, Trigger�� Overlap�Ǿ����� �߻��� �Լ��� ���ε�
	StageTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("StageTrigger"));
	StageTrigger->SetBoxExtent(FVector(775.0f, 775.0f, 300.0f));
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
		// SetupAttachment()���� Ư���ϰ� ������ �����ϰ� �ִµ�, �������� ��ġ�� �����ϸ� ��¦�� �����ؼ� ���� ��ġ�� ��Ȯ�ϰ� ��ġ�� �� �ִ�.
		Gate->SetupAttachment(Stage, GateSocket);
		Gate->SetRelativeLocation(FVector(0.0f, -80.5f, 0.0f));
		Gate->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
		// TMap�� Gates�� �߰�
		Gates.Add(GateSocket, Gate);

		// ��ü�� ������ �� �ٸ� �̸��� �����;� �Ǳ� ������ GateSocket�� String���� ��ȯ �� Trigger��� ǥ�� �߰��ϱ�
		FName TriggerName = *GateSocket.ToString().Append(TEXT("Trigger"));
		UBoxComponent* GateTrigger = CreateDefaultSubobject<UBoxComponent>(TriggerName);
		GateTrigger->SetBoxExtent(FVector(100.0f, 100.0f, 300.0f));
		GateTrigger->SetupAttachment(Stage, GateSocket);
		GateTrigger->SetRelativeLocation(FVector(70.0f, 0.0f, 250.0f));
		GateTrigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
		GateTrigger->OnComponentBeginOverlap.AddDynamic(this, &AABStageGimmick::OnGateTriggerBeginOverlap);
		// �±� �߰�
		GateTrigger->ComponentTags.Add(GateSocket);

		GateTriggers.Add(GateTrigger);
	}

	// State Section
	// �����ڿ��� �ʱ�ȭ
	CurrentState = EStageState::READY;
	// ������ ���� ���� ����
	StateChangeActions.Add(EStageState::READY, FStageChangedDelegateWrapper(FOnStageChangedDelegate::CreateUObject(this, &AABStageGimmick::SetReady)));
	StateChangeActions.Add(EStageState::FIGHT, FStageChangedDelegateWrapper(FOnStageChangedDelegate::CreateUObject(this, &AABStageGimmick::SetFight)));
	StateChangeActions.Add(EStageState::REWARD, FStageChangedDelegateWrapper(FOnStageChangedDelegate::CreateUObject(this, &AABStageGimmick::SetChooseReward)));
	StateChangeActions.Add(EStageState::NEXT, FStageChangedDelegateWrapper(FOnStageChangedDelegate::CreateUObject(this, &AABStageGimmick::SetChooseNext)));
}

// �����Ϳ��� ���� �����ϸ� ����Ǵ� �Լ�
void AABStageGimmick::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	SetState(CurrentState);
}

void AABStageGimmick::OnStageTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AABStageGimmick::OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

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
	// ������ Switch������ �����ϱ⵵ ������, ���°� ���� �þ ���� ������ ������ ���δ�.
	// �׷��� ��������Ʈ ��̷� �Լ� �����͸� ����ؼ� �����ϴ� ����� �ִ�.

	// �ٲ� ���·� ������Ʈ
	CurrentState = InNewState;

	// InNewState��� ���°� �ڷᱸ�� �� �����ȿ� �ִٸ�~
	if (StateChangeActions.Contains(InNewState))
	{
		// �ش� ��������Ʈ�� ���ε��Ǿ� ������ �����ϵ���
		// �� ������ ���� ���� �Լ����� ȣ��ȴ�.
		StateChangeActions[CurrentState].StageDelegate.ExecuteIfBound();
	}
}

void AABStageGimmick::SetReady()
{
	// Player���� �浹�� ���� Trigger �ݸ��� Ȱ��ȭ
	StageTrigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
	// Gate�� Trigger �ݸ����� Ȱ��ȭ�� �ʿ䰡 ����.
	for (auto GateTrigger : GateTriggers)
	{
		GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	}

	CloseAllGates();
}

void AABStageGimmick::SetFight()
{
	// StageTrigger�� �ݸ����� Ȱ��ȭ�� �ʿ䰡 ����.
	StageTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	// Gate�� Trigger �ݸ����� Ȱ��ȭ�� �ʿ䰡 ����.
	for (auto GateTrigger : GateTriggers)
	{
		GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	}

	CloseAllGates();
}

void AABStageGimmick::SetChooseReward()
{
	// StageTrigger�� �ݸ����� Ȱ��ȭ�� �ʿ䰡 ����.
	StageTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	// Gate�� Trigger �ݸ����� Ȱ��ȭ�� �ʿ䰡 ����.
	for (auto GateTrigger : GateTriggers)
	{
		GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	}

	CloseAllGates();
}

void AABStageGimmick::SetChooseNext()
{
	// StageTrigger�� �ݸ����� Ȱ��ȭ�� �ʿ䰡 ����.
	StageTrigger->SetCollisionProfileName(TEXT("NoCollision"));
	// Gate�� Trigger �ݸ����� Ȱ��ȭ�� �ʿ䰡 ����.
	for (auto GateTrigger : GateTriggers)
	{
		GateTrigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
	}

	OpenAllGates();
}
