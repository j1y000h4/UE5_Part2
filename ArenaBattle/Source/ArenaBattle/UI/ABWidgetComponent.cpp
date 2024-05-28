// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABWidgetComponent.h"
#include "ABUserWidget.h"

void UABWidgetComponent::InitWidget()
{
	// InitWidget()이 실행이 된다는 것은 이미 CreateWidget()이 완료된 시점. Widget에 대한 인스턴스가 생성되어 있음
	Super::InitWidget();

	UABUserWidget* ABUserWidget = Cast<UABUserWidget>(GetWidget());

	if (ABUserWidget)
	{
		// 자신을 소유하고 있는 액터 정보를 얻어올 수 있음. OwningActor
		// ABUserWidget을 상속받는 UserWidget의 경우 여기서 초기화 된 OwningActor 값을 사용할 수 있게 된다.
		// ABHpBarWidget을 UUSerWidget이 아닌 ABUserWidget을 상속받도록 변경하기
		ABUserWidget->SetOwningActor(GetOwner());
	}
}
