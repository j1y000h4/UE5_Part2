// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugViewer.h"
#include "DebugManager.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Fonts/SlateFontInfo.h"
#include "Async/Async.h"

// Sets default values
ADebugViewer::ADebugViewer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADebugViewer::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// 위젯 클래스 뷰포트에 추가
	LogScreen = CreateWidget<UUserWidget>(GetWorld(), LogScreenClass);
	if (LogScreen)
	{
		// 로그 이벤트 등록
		UDebugManager::Instance()->LogAddEventInstance.AddUObject(this, &ADebugViewer::LogAddEventHandler);
	
		ScrollBox = Cast<UScrollBox>(LogScreen->GetWidgetFromName(TEXT("ScrollBox")));

		LogScreen->AddToViewport();
		LogScreen->SetVisibility(ESlateVisibility::Hidden);
	}
}

// Called when the game starts or when spawned
void ADebugViewer::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = GetWorld()->GetFirstPlayerController();
	
	UDebugManager::Instance()->AddLog("Start DebugViewer");
}

void ADebugViewer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UDebugManager::Instance()->Shutdown();
}

// Called every frame
void ADebugViewer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerController == nullptr || LogScreen == nullptr) return;
	
	// 쉬프트+L 위젯 On/Off
	if (PlayerController->IsInputKeyDown(EKeys::LeftShift))
	{
		if (PlayerController->WasInputKeyJustPressed(EKeys::L))
		{
			LogWidgetActivate();
		}
	}

#if WITH_EDITOR
	if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustPressed(EKeys::A))
	{
		for (int i = 0; i < 200; i++)
		{
			UDebugManager::Instance()->AddLog((FString::Printf(TEXT("Log Test %d"), i)));
		}
	}
#endif
}

// 위젯 On/Off
void ADebugViewer::LogWidgetActivate()
{
	IsActivated = !IsActivated;

	if (IsActivated)
	{
		LogScreen->SetVisibility(ESlateVisibility::Visible);
		
		FlushLogBuffer(); // 버퍼에 있는 로그를 UI에 추가
		
		ScrollBox->ScrollToEnd();
		PlayerController->SetInputMode(FInputModeGameAndUI());
	}
	else
	{
		LogScreen->SetVisibility(ESlateVisibility::Hidden);
	}

	PlayerController->SetShowMouseCursor(IsActivated);

	FVector2D MousePosition;
	PlayerController->GetMousePosition(MousePosition.X, MousePosition.Y);
	PlayerController->SetMouseLocation(MousePosition.X + 1, MousePosition.Y + 1);
}

// 로그 추가
void ADebugViewer::LogAddEventHandler(FString Log)
{
	if (IsShowOutputLog)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Log);
	}

	// 로그 창이 활성화되어 있으면 즉시 UI에 로그 추가
	if (IsActivated)
	{
		AddLogAsync(Log);
	}
	else if (!IsActivated)
	{
		// 활성화되어 있지 않으면 버퍼에 추가
		AddLogToBuffer(Log);
	}

	// if (LogScreen && MyListView)
	// {
	// 	UUserWidget* LogItemWidget = CreateWidget<UUserWidget>(GetWorld(), LogItemWidgetClass);
	// 	if (LogItemWidget)
	// 	{
	// 		UTextBlock* TextBlock = Cast<UTextBlock>(LogItemWidget->GetWidgetFromName(TEXT("TextBlock")));
	// 		if (TextBlock)
	// 		{
	// 			TextBlock->SetText(FText::FromString(Log));
	// 			MyListView->AddItem(LogItemWidget);
	// 		}

			// FString FunctionName = TEXT("Update Text");
			// FText NewText = FText::FromString(TEXT("새로운 텍스트"));
			// UFunction* Function = LogItemWidget->FindFunction(FName(*FunctionName));
			// if (Function)
			// {
			// 	// 함수에 전달할 파라미터를 구성합니다.
			// 	struct FUpdateTextParameters
			// 	{
			// 		FText Text;
			// 	};
			//
			// 	FUpdateTextParameters Params;
			// 	Params.Text = FText::FromString(Log);
			//
			// 	// 함수를 호출합니다.
			// 	LogItemWidget->ProcessEvent(Function, &Params);
	 		// }
	// 	}		
	// }
	
	
	// if (LogScreen && ScrollBox)
	// {
	// 	UTextBlock* TextBlock = NewObject<UTextBlock>(ScrollBox);
	// 	if (TextBlock)
	// 	{
	// 		TextBlockArray.Add(TextBlock);
	// 		if (TextBlockArray.Num() > MaxLogCount)
	// 		{
	// 			UTextBlock *OldestTextBlock = TextBlockArray[0];
	// 			OldestTextBlock->RemoveFromParent();
	// 			TextBlockArray.RemoveAt(0);
	// 		}
	// 		
	// 		FString FontBrushPath = TEXT("/Game/FinePlugin/SettingUI/TWKEverett-Bold_Font.TWKEverett-Bold_Font");
	// 		UObject* FontObject = LoadObject<UObject>(nullptr, *FontBrushPath);
	// 		if (FontObject)
	// 		{
	// 			FSlateFontInfo FontInfo;
	// 			FontInfo.FontObject = FontObject;
	// 			FontInfo.Size = FontSize;
	// 			TextBlock->SetFont(FontInfo);
	// 		}
	// 		else
	// 		{
	// 			FSlateFontInfo fontInfo = FSlateFontInfo(FCoreStyle::GetDefaultFontStyle("Regular", FontSize));
	// 			TextBlock->SetFont(fontInfo);
	// 			TextBlock->SetJustification(ETextJustify::Left);
	// 		}			
	// 		TextBlock->SetText(FText::FromString(FDateTime::Now().ToString() + " > " + Log));
	// 		ScrollBox->AddChild(TextBlock);
	// 		CurrentLogIndex++;
	// 	}
	// }
}

void ADebugViewer::AddLogAsync(FString Log)
{
	// 'this' 포인터의 유효성을 검사하기 위해 WeakObjectPtr 사용
	TWeakObjectPtr<ADebugViewer> WeakThis(this);

	// 비동기 작업 정의
	Async(EAsyncExecution::ThreadPool, [WeakThis, Log]()
	{
		// 백그라운드 스레드에서 실행할 로그 처리 로직

		// 메인 스레드로 결과 전달
		Async(EAsyncExecution::TaskGraphMainThread, [WeakThis, Log]()
		{
			// 'this' 포인터의 유효성 검사
			if (!WeakThis.IsValid()) return;

			ADebugViewer* StrongThis = WeakThis.Get();
			if (StrongThis->LogScreen && StrongThis->ScrollBox)
			{
				UTextBlock* TextBlock = NewObject<UTextBlock>(StrongThis->ScrollBox);
				if (TextBlock)
				{
					StrongThis->TextBlockArray.Add(TextBlock);
					if (StrongThis->TextBlockArray.Num() > StrongThis->MaxLogCount)
					{
						UTextBlock* OldestTextBlock = StrongThis->TextBlockArray[0];
						OldestTextBlock->RemoveFromParent();
						StrongThis->TextBlockArray.RemoveAt(0);
					}

					//기본 폰트 설정
					FSlateFontInfo FontInfo = FSlateFontInfo(FCoreStyle::GetDefaultFontStyle("Regular", StrongThis->FontSize));
					TextBlock->SetFont(FontInfo);
					TextBlock->SetJustification(ETextJustify::Left);
					TextBlock->SetText(FText::FromString(FDateTime::Now().ToString() + " > " + Log));
					StrongThis->ScrollBox->AddChild(TextBlock);
				}
			}
		});
	});
}

void ADebugViewer::AddLogToBuffer(const FString& Log)
{
	LogBuffer.Add(Log);

	// 버퍼 크기가 최대값을 초과하면 가장 오래된 로그부터 제거
	while (LogBuffer.Num() > MaxLogCount)
	{
		LogBuffer.RemoveAt(0);
	}
}

void ADebugViewer::FlushLogBuffer()
{
	// UI가 활성화되어 있고, 사용자에게 가시적일 때만 로그를 UI에 추가
	if (IsActivated && LogScreen->IsVisible())
	{
		for (const FString& Log : LogBuffer)
		{
			AddLogAsync(Log); // 비동기 로그 추가 함수를 사용하여 로그 처리
		}

		LogBuffer.Empty(); // UI에 로그를 추가한 후 버퍼 비우기
	}
}

