// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ABHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABHpBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// UserWidget�� ��� �Ϲ����� �����ڸ� ��������
	UABHpBarWidget(const FObjectInitializer& ObjectInitializer);

protected:
	// �׳� UProgressBar�� �������� �Ǹ� Null���̴�, ������ �ʱ�ȭ�� �� HpProgressBar�� �����ͼ� �����͸� �������� ����� �߰�
	// UserWidget���� ����ϴ� �Լ���
	virtual void NativeConstruct() override;

public:
	FORCEINLINE void SetMaxHp(float NewMaxHp) { MaxHp = NewMaxHp; }
	void UpdateHpBar(float NewCurrentHp);

protected:
	UPROPERTY()
	TObjectPtr<class UProgressBar> HpProgressBar;		// Build Dependency���� UMG �߰��ϱ�

	UPROPERTY()
	float MaxHp;
};
