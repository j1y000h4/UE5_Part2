// Fill out your copyright notice in the Description page of Project Settings.


#include "Toast.h"
#include "DebugManager.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "Fonts/FontMeasure.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SWindow.h"
#include "UObject/ConstructorHelpers.h"

UToast* UToast::Instance = nullptr;
UWorld* UToast::World = nullptr;

UToast::UToast()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> ToastWidgetClassFinder(TEXT("/Mujogeon/Toast/WBP_Toast"));
	if (ToastWidgetClassFinder.Succeeded())
	{
		ToastScreenClass = ToastWidgetClassFinder.Class;
	}
}

UToast::~UToast()
{
	if (Instance)
	{
		Instance->RemoveFromRoot();
		Instance = nullptr;
	}
	World = nullptr;
}

UToast* UToast::GetInstance()
{
	if (!Instance)
	{
		Instance = NewObject<UToast>();
		Instance->AddToRoot();
	}

	if (GEngine && GEngine->GameViewport)
	{
		World = GEngine->GameViewport->GetWorld();
	}
	
	return Instance;
}

void UToast::InitializeScreen()
{
	if (!Instance->ToastScreenClass || Instance->Screen) return;

	Instance->Screen = CreateWidget<UUserWidget>(World, Instance->ToastScreenClass);
	if (!Instance->Screen)
	{
		UDebugManager::Instance()->AddLog(FString::Printf(TEXT("%s Failed to create Screen"), *Instance->GetName()));
		return;
	}

	Instance->Screen->AddToViewport();
	Instance->Screen->SetVisibility(ESlateVisibility::Hidden);

	Instance->ToastImage = Cast<UImage>(Instance->Screen->GetWidgetFromName(TEXT("ToastImage")));
	Instance->ToastText = Cast<UTextBlock>(Instance->Screen->GetWidgetFromName(TEXT("ToastText")));
}

void UToast::Bake(const FString& Message)
{
	if (!Instance)
	{
		UDebugManager::Instance()->AddLog(FString::Printf(TEXT("%s Instance is null"), *Instance->GetName()));
		return;
	}

	if (!World)
	{
		UDebugManager::Instance()->AddLog(FString::Printf(TEXT("%s World is null"), *Instance->GetName()));
		return;
	}

	InitializeScreen();

	if (!Instance->Screen)
	{
		UDebugManager::Instance()->AddLog(FString::Printf(TEXT("%s Screen is not valid after creation attempt"), *Instance->GetName()));
		return;
	}

	Instance->Screen->SetVisibility(ESlateVisibility::Visible);

	if (Instance->ToastText)
	{
		Instance->ToastText->SetText(FText::FromString(Message));
	}

	if (Instance->ToastImage)
	{
		const FText Text = Instance->ToastText->GetText();
		const FSlateFontInfo FontInfo = Instance->ToastText->GetFont();
		const FVector2D TextSize = FSlateApplication::Get().GetRenderer()->GetFontMeasureService()->Measure(Text, FontInfo);

		constexpr float Padding = 50.0f;
		const float NewWidth = TextSize.X + Padding;

		if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Instance->ToastImage->Slot))
		{
			FVector2D NewSize = CanvasSlot->GetSize();
			NewSize.X = NewWidth;
			CanvasSlot->SetSize(NewSize);
		}
	}
	
	World->GetTimerManager().SetTimer(Instance->ShowTimerHandle, []() {
		if (Instance && Instance->Screen)
		{
			Instance->Screen->SetVisibility(ESlateVisibility::Hidden);
		}
	}, 3.0f, false);
}