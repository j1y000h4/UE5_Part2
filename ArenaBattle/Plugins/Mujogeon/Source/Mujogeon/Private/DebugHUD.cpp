// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugHUD.h"

#include "DebugManager.h"
#include "Engine/Canvas.h"

void ADebugHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UDebugManager::Instance()->LogAddEventInstance.AddUObject(this, &ADebugHUD::AddLogEventHandler);
}

void ADebugHUD::BeginPlay()
{
	Super::BeginPlay();

	DebugLogs.Empty();

	//LoadedFont = Cast<UFont>(StaticLoadObject(UFont::StaticClass(), nullptr, TEXT("/Mujogeon/SettingUI/Resource/TWKEverett-Bold_Font")));
	LoadedFont = Cast<UFont>(StaticLoadObject(UFont::StaticClass(), nullptr, TEXT("/Mujogeon/Debug/Roboto")));
}

void ADebugHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	DebugLogs.Empty();
	UDebugManager::Instance()->Shutdown();
}

void ADebugHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::LeftShift) && GetWorld()->GetFirstPlayerController()->WasInputKeyJustPressed(EKeys::L))
	{
		bIsOverlayActive = !bIsOverlayActive;
		if (bIsOverlayActive)
		{
			bNeedToUpdateScrollOffset = true;
		}
	}

#if WITH_EDITOR
	if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustPressed(EKeys::A))
	{
		for (int i = 0; i < 200; i++)
		{
			//AddLogEventHandler(FString::Printf(TEXT("Log Test %d"), i));
			if (i % 2 == 0)
				UDebugManager::Instance()->AddLog(FString::Printf(TEXT("Log Test aaaaaaa aaaaaaaaaaa aaaaaaaaaaaa aaaaaaaaa aaaaaaaaa aaaaaaaaa aaaaaaaaA %d"), i));
			else if (i % 3 == 0)
				UDebugManager::Instance()->AddLog(FString::Printf(TEXT("Log Test bbbbbbb bbbbbbbbbbb bbbbbbbbbb  %d"), i));
			else
				UDebugManager::Instance()->AddLog(FString::Printf(TEXT("Log Test %d"), i));
		}
	}
#endif
}

void ADebugHUD::DrawHUD()
{
	Super::DrawHUD();

	LoadedFont->LegacyFontSize = 12;
	
	const FVector2D ScreenSize = FVector2D(Canvas->SizeX, Canvas->SizeY);
	float LogLineHeight = LoadedFont->LegacyFontSize + 8; //18.0f;
	if (bIsOverlayActive)
	{
		int NumLogsVisible = FMath::CeilToInt(ScreenSize.Y / LogLineHeight);
		int FirstLogIndex = FMath::Max(0, FMath::FloorToInt(ScrollOffset / LogLineHeight));
		int LastLogIndex = FMath::Min(FirstLogIndex + NumLogsVisible, DebugLogs.Num());

		float Y = 0.0f;
		for (int i = FirstLogIndex; i < LastLogIndex; ++i)
		{
			FString Line = "";
			const FString& Message = DebugLogs[i];
			TArray<FString> Words;
			Message.ParseIntoArray(Words, TEXT(" "), true);

			for (const FString& Word : Words)
			{
				FString TestLine = Line.IsEmpty() ? Word : Line + " " + Word;
				float TestLineWidth, TestLineHeight;
				Canvas->TextSize(LoadedFont, TestLine, TestLineWidth, TestLineHeight);

				if (TestLineWidth <= ScreenSize.X - (ScreenSize.X * 0.1f))
				{
					Line = TestLine;
				}
				else
				{
					DrawText(Line, FLinearColor::White, 20.0f, Y, LoadedFont);
					Y += LogLineHeight; // 줄바꿈
					Line = Word; // 새 줄 시작
				}
			}

			if (!Line.IsEmpty())
			{
				DrawText(Line, FLinearColor::White, 20.0f, Y, LoadedFont);
				Y += LogLineHeight;
			}

			if (Y > ScreenSize.Y) break; // 화면을 벗어나면 그리기 중단
		}
		
		// 스크롤 오프셋 업데이트가 필요한 경우 처리합니다.
		int EmptySpaces = 3;
		float AvailableScreenHeight = ScreenSize.Y - (EmptySpaces * LogLineHeight);
		if (bNeedToUpdateScrollOffset)
		{
			ScrollOffset = FMath::Max(0.0f, DebugLogs.Num() * LogLineHeight - AvailableScreenHeight);
			bNeedToUpdateScrollOffset = false;
		}
		MaxScrollOffset = FMath::Max(DebugLogs.Num() * LogLineHeight - AvailableScreenHeight, 0.0f);
		
		// 스크롤바 배경 그리기
		FVector2D ScrollBarBackgroundPos = FVector2D(ScreenSize.X - 20, 0); // 스크롤바 위치
		FVector2D ScrollBarBackgroundSize = FVector2D(10, ScreenSize.Y); // 스크롤바 크기
		DrawRect(FLinearColor(0.2f, 0.2f, 0.2f, 1.f), ScrollBarBackgroundPos.X, ScrollBarBackgroundPos.Y, ScrollBarBackgroundSize.X, ScrollBarBackgroundSize.Y);

		// 스크롤바 핸들 그리기
		float ScrollFraction = ScrollOffset / MaxScrollOffset; // 스크롤 비율 계산
		FVector2D ScrollHandlePos = FVector2D(ScrollBarBackgroundPos.X, ScrollFraction * ScreenSize.Y); // 핸들 위치
		FVector2D ScrollHandleSize = FVector2D(10, 30); // 핸들 크기, 고정값이나 동적으로 계산할 수도 있음
		float MaxHandleTopPosition = ScreenSize.Y - ScrollHandleSize.Y; // 핸들의 최대 Y 위치
		ScrollHandlePos.Y = ScrollFraction * MaxHandleTopPosition; // 핸들 위치 조정
		DrawRect(FLinearColor::White, ScrollHandlePos.X, ScrollHandlePos.Y, ScrollHandleSize.X, ScrollHandleSize.Y);
	}
}

void ADebugHUD::AddLogEventHandler(FString Log)
{
	DebugLogs.Add("[" + FString::FromInt(DebugLogs.Num()) + "] " + FDateTime::Now().ToString() + " > " + Log);
	
	if (DebugLogs.Num() > 50000)
	{
		DebugLogs.RemoveAt(0);
	}
}

void ADebugHUD::HandleMouseWheelScroll(float ScrollDirection)
{
	const float ScrollAmount = 50.0f;

	if (ScrollDirection > 0.0f)
	{
		ScrollOffset -= ScrollAmount;
	}
	else if (ScrollDirection < 0.0f)
	{
		ScrollOffset += ScrollAmount;
	}

	// ScrollOffset이 0과 MaxScrollOffset 사이의 값이 되도록 조정
	//ScrollOffset = FMath::Clamp(ScrollOffset, 0.0f, MaxScrollOffset);
}

void ADebugHUD::SetHUDActive(bool bActive)
{
	bIsOverlayActive = bActive;
}
