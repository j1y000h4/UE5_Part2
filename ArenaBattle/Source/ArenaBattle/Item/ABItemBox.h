// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABItemBox.generated.h"

UCLASS()
class ARENABATTLE_API AABItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABItemBox();

	FORCEINLINE class UBoxComponent* GetTrigger() { return Trigger; }

protected:
	// ItemBox의 액터 세팅이 마무리되는 시점에 랜덤하게 보상을 넣을 수 있도록 PostInitializeComponents()함수를 사용
	virtual void PostInitializeComponents() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = Box)
	TObjectPtr<class UBoxComponent> Trigger;

	UPROPERTY(VisibleAnywhere, Category = Box)
	TObjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, Category = Effect)
	TObjectPtr<class UParticleSystemComponent> Effect;

	// 부모 클래스형을 지정했기 때문에 Weapon, Potion, Scroll 중 하나가 여기에 대응된다.
	UPROPERTY(EditAnywhere, Category = Item)
	TObjectPtr<class UABItemData> Item;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult);

	UFUNCTION()
	void OnEffectFinished(class UParticleSystemComponent* ParticleSystem);
};
