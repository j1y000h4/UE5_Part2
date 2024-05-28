// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/ABItemBox.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Physics/ABCollision.h"
#include "Interface/ABCharacterItemInterface.h"
#include "Engine/AssetManager.h"		// 에셋 매니저 헤더 추가
#include "ABItemData.h"

// Sets default values
AABItemBox::AABItemBox()
{
	// 액터 구성
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Effect"));

	// 루트 컴포넌트 설정
	RootComponent = Trigger;
	Mesh->SetupAttachment(Trigger);
	Effect->SetupAttachment(Trigger);

	// 트리거의 콜리전 설정
	Trigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));

	// 오버랩되면 발생시킬 함수 바인딩
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AABItemBox::OnOverlapBegin);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BoxMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Props/SM_Env_Breakables_Box1.SM_Env_Breakables_Box1'"));
	if (BoxMeshRef.Object)
	{
		Mesh->SetStaticMesh(BoxMeshRef.Object);
	}
	Mesh->SetRelativeLocation(FVector(0.0f, -3.5f, -30.0f));
	Mesh->SetCollisionProfileName(TEXT("NoCollision"));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> EffectRef(TEXT("/Script/Engine.ParticleSystem'/Game/ArenaBattle/Effect/P_TreasureChest_Open_Mesh.P_TreasureChest_Open_Mesh'"));
	if (EffectRef.Object)
	{
		Effect->SetTemplate(EffectRef.Object);
		Effect->bAutoActivate = false;
	}
}

// ItemBox가 초기화가 된 이후
void AABItemBox::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// 이 에셋 매니저의 경우 엔진이 초기화될 때 언제나 로딩을 보장해준다라고 보면 된다.
	UAssetManager& Manager = UAssetManager::Get();

	// Manager의 GetPrimaryAssetIdList()함수에 태그 정보를 넘겨주면 지정한 폴더 내에 있는 모든 에셋에 대해서 태그 아이디를 가지고 있는 에셋들의 목록을 배열로 반환해준다.
	TArray<FPrimaryAssetId> Assets;
	Manager.GetPrimaryAssetIdList(TEXT("ABItemData"), Assets);

	// 잘 동작하는가?
	ensure(0 < Assets.Num());

	// 약참조 후, RandomInex를 통해 랜덤하게 AssetData를 지정
	int32 RandomIndex = FMath::RandRange(0, Assets.Num() - 1);
	FSoftObjectPtr AssetPtr(Manager.GetPrimaryAssetPath(Assets[RandomIndex]));
	if (AssetPtr.IsPending())
	{
		AssetPtr.LoadSynchronous();
	}

	Item = Cast<UABItemData>(AssetPtr.Get());
	ensure(Item);
}

// 바인딩 된 함수 설정 및 로직 구성
// 아이템 획득했을 때
void AABItemBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
	// 아이템에 꽝이 존재할 경우
	if (nullptr == Item)
	{
		Destroy();
		return;
	}

	// Item이 있다면 TakeItem에 인자로 넘겨주기
	IABCharacterItemInterface* OverlappingPawn = Cast<IABCharacterItemInterface>(OtherActor);
	if (OverlappingPawn)
	{
		OverlappingPawn->TakeItem(Item);
	}

	Effect->Activate(true);
	Mesh->SetHiddenInGame(true);
	SetActorEnableCollision(false);

	// 이펙트가 끝날때 발생하는 델리게이트에 끝날때 Destroy를 해주는 함수를 바인딩해준다.
	Effect->OnSystemFinished.AddDynamic(this, &AABItemBox::OnEffectFinished);
}

void AABItemBox::OnEffectFinished(UParticleSystemComponent* ParticleSystem)
{
	Destroy();
}

