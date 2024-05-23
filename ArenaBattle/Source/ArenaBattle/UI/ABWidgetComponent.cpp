// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABWidgetComponent.h"
#include "ABUserWidget.h"

void UABWidgetComponent::InitWidget()
{
	// InitWidget()�� ������ �ȴٴ� ���� �̹� CreateWidget()�� �Ϸ�� ����. Widget�� ���� �ν��Ͻ��� �����Ǿ� ����
	Super::InitWidget();

	UABUserWidget* ABUserWidget = Cast<UABUserWidget>(GetWidget());

	if (ABUserWidget)
	{
		// �ڽ��� �����ϰ� �ִ� ���� ������ ���� �� ����. OwningActor
		// ABUserWidget�� ��ӹ޴� UserWidget�� ��� ���⼭ �ʱ�ȭ �� OwningActor ���� ����� �� �ְ� �ȴ�.
		// ABHpBarWidget�� UUSerWidget�� �ƴ� ABUserWidget�� ��ӹ޵��� �����ϱ�
		ABUserWidget->SetOwningActor(GetOwner());
	}
}
