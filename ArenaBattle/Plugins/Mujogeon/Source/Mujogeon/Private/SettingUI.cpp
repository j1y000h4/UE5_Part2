// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingUI.h"
#include "Blueprint/UserWidget.h"
#include "Misc/App.h"
#include "ConfigManager.h"
#include "DebugManager.h"
#include "Components/Border.h"
#include "Components/CheckBox.h"
#include "Components/Spacer.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/ScrollBoxSlot.h"
#include "Components/EditableText.h"

// Sets default values
ASettingUI::ASettingUI()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASettingUI::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = GetWorld()->GetFirstPlayerController();
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Please Check PlayerController"));
	}

	// FString ProjectVersion;
	// if (GConfig->GetString(TEXT("/Script/EngineSettings.GeneralProjectSettings"), TEXT("ProjectVersion"), ProjectVersion, GGameIni))
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Project Version : %s"), *ProjectVersion);
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Project Version : Not Found"));
	// }
}

// Called every frame
void ASettingUI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerController || !Screen || !ConfigManager)
	{
		return;
	}

	if (PlayerController->IsInputKeyDown(EKeys::LeftShift))
	{
		if (PlayerController->WasInputKeyJustPressed(EKeys::S))
		{
			if (!ConfigManager)
			{
				UE_LOG(LogTemp, Warning, TEXT("Please Check ConfigManager"));
				return;
			}
			if (!Screen)
			{
				UE_LOG(LogTemp, Warning, TEXT("Please Check Screen Class"));
				return;
			}

			WidgetActivate();
		}
	}
}

void ASettingUI::Init(AConfigManager* Config)
{
	ConfigManager = Config;

	// 위젯 클래스 뷰포트에 추가
	Screen = CreateWidget<UUserWidget>(GetWorld(), ScreenClass);
	if (Screen)
	{
		TitleText = Cast<UTextBlock>(Screen->GetWidgetFromName(TEXT("Title")));
		ScrollBox = Cast<UScrollBox>(Screen->GetWidgetFromName(TEXT("ScrollBox")));
		SaveButton = Cast<UButton>(Screen->GetWidgetFromName(TEXT("SaveButton")));

		Screen->AddToViewport();
		Screen->SetVisibility(ESlateVisibility::Hidden);
		
		GenerateDynamicUI();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Please Check Screen Class"));
	}

	if (TitleText)
	{
		TitleText->SetText(FText::FromString(FApp::GetProjectName()));
	}

	if (SaveButton)
	{
		SaveButton->OnClicked.AddDynamic(this, &ASettingUI::SaveConfigData);
	}
}

void ASettingUI::SaveConfigData()
{
	if (!ConfigManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("Please check ConfigManager"));
		return;
	}

	UStruct* ConfigStruct = FConfigData::StaticStruct();	
	TFieldIterator<FProperty> It(ConfigStruct);

	for (int32 ArrayIndex = 0; It; ++It, ++ArrayIndex)
	{
		if (ArrayIndex >= EditableTextArray.Num())
		{
			break;
		}			
		
		if (!EditableTextArray.IsValidIndex(ArrayIndex))
		{
			UE_LOG(LogTemp, Error, TEXT("EditableTextArray Index out of range or is null, Index: %d, Size: %d"), ArrayIndex, EditableTextArray.Num());
			continue; // 잘못된 인덱스 또는 null 참조를 건너뜀
		}

		FProperty* Prop = *It;
		if (!Prop)
		{
			continue; // 유효하지 않은 프로퍼티 포인터를 건너뜀
		}
		void* ValuePtr = Prop->ContainerPtrToValuePtr<void>(&ConfigManager->ConfigData);
		if (!ValuePtr)
		{
			continue; // 유효하지 않은 값 포인터를 건너뜀
		}
		
		FString StringValue = EditableTextArray[ArrayIndex]->GetText().ToString();
		
		if (FStrProperty* StrProp = CastField<FStrProperty>(Prop))
		{
			StrProp->SetPropertyValue(ValuePtr, StringValue);
		}
		else if (FIntProperty* IntProp = CastField<FIntProperty>(Prop))
		{
			IntProp->SetPropertyValue(ValuePtr, FCString::Atoi(*StringValue));
		}
		else if (FFloatProperty* FloatProp = CastField<FFloatProperty>(Prop))
		{
			FloatProp->SetPropertyValue(ValuePtr, FCString::Atof(*StringValue));
		}
		else if (FBoolProperty* BoolProp = CastField<FBoolProperty>(Prop))
		{
			UCheckBox** CheckBoxPtr = CheckBoxMap.Find(BoolProp->GetName());
			if (CheckBoxPtr && *CheckBoxPtr)
			{
				bool bIsChecked = (*CheckBoxPtr)->IsChecked();
				BoolProp->SetPropertyValue(ValuePtr, bIsChecked);
			}
		}
		else if (FStructProperty* StructProp = CastField<FStructProperty>(Prop))
		{
			if (StructProp->Struct == TBaseStructure<FVector>::Get())
			{
				FVector VectorValue;
				if (VectorValue.InitFromString(StringValue))
				{
					StructProp->CopyCompleteValue(ValuePtr, &VectorValue);
				}
			}
			else if (StructProp->Struct == TBaseStructure<FVector2D>::Get())
			{
				FVector2D VectorValue;
				if (VectorValue.InitFromString(StringValue))
				{
					StructProp->CopyCompleteValue(ValuePtr, &VectorValue);
				}
			}
			else if (StructProp->Struct == TBaseStructure<FVector4>::Get())
			{
				FVector4 VectorValue;
				if (VectorValue.InitFromString(StringValue))
				{
					StructProp->CopyCompleteValue(ValuePtr, &VectorValue);
				}
			}
		}
	}

	const bool IsCompleted = ConfigManager->UpdateConfigData();

	if (ScrollBox && IsCompleted)
	{
		for (UEditableText* EditableText : EditableTextArray)
		{
			EditableText = nullptr;
		}
		EditableTextArray.Empty();

		for (auto& CheckBox : CheckBoxMap)
		{
			CheckBox.Value = nullptr;
		}
		
		CheckBoxMap.Empty();
		GenerateDynamicUI();

		OnSettingUISaveConfig.Broadcast();
		OnSettingUISaveConfig_nDisplay.Broadcast(ConfigManager->GetJsonString());

		UDebugManager::Instance()->AddLog("ConfigData Applied");
	}
}

void ASettingUI::WidgetActivate()
{
	IsActivated = !IsActivated;

	if (IsActivated)
	{
		PlayerController->SetInputMode(FInputModeGameAndUI());
		Screen->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		Screen->SetVisibility(ESlateVisibility::Hidden);
	}

	PlayerController->SetShowMouseCursor(IsActivated);

	FVector2D MousePosition;
	PlayerController->GetMousePosition(MousePosition.X, MousePosition.Y);
	PlayerController->SetMouseLocation(MousePosition.X + 1, MousePosition.Y + 1);
}

void ASettingUI::GenerateDynamicUI()
{	
	if (ConfigManager)
	{
		ScrollBox->ClearChildren();
		TArray<FProperty*> Properties = ConfigManager->GetAllConfigProperties();

		for (const FProperty* Property : Properties)
		{
			UBorder* Border = NewObject<UBorder>(this);
			Border->SetBrushColor(FLinearColor(0.1f, 0.1f, 0.1f, 0.3f)); // 배경색 설정
			Border->SetDesiredSizeScale(FVector2D(0, 1.8f)); // 크기 설정
			ScrollBox->AddChild(Border);

			// Border의 슬롯을 UScrollBoxSlot으로 캐스팅하여 마진 설정
			UScrollBoxSlot* ScrollBoxSlot = Cast<UScrollBoxSlot>(Border->Slot);
			if (ScrollBoxSlot)
			{
				ScrollBoxSlot->SetPadding(FMargin(0.0f, 5.f, 5.0f, 5.f));
			}

			// 새로운 HorizontalBox를 생성
			UHorizontalBox* NewHorizontalBox = NewObject<UHorizontalBox>(this);
			Border->SetContent(NewHorizontalBox);

			// 프로퍼티 이름을 위한 TextBlock 생성 및 설정
			UTextBlock* PropertyNameText = NewObject<UTextBlock>(this);
			PropertyNameText->SetText(FText::FromString(Property->GetName()));
			UHorizontalBoxSlot* PropertyNameSlot = NewHorizontalBox->AddChildToHorizontalBox(PropertyNameText);
			if (PropertyNameSlot)
			{
				PropertyNameSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
				PropertyNameSlot->SetPadding(FMargin(20.0f, 0.0f, 0.0f, 0.0f));
			}

			UEditableText* PropertyValueText = NewObject<UEditableText>(this);
			if (const FBoolProperty* BoolProperty = CastField<FBoolProperty>(Property))
			{
				bool bIsChecked = BoolProperty->GetPropertyValue_InContainer(&ConfigManager->ConfigData);

				PropertyValueText->SetText(bIsChecked ? FText::FromString(TEXT("true")) : FText::FromString(TEXT("false")));
				UHorizontalBoxSlot* PropertyValueSlot = NewHorizontalBox->AddChildToHorizontalBox(PropertyValueText);
				if (PropertyValueSlot)
				{
					PropertyValueSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
					PropertyValueSlot->SetPadding(FMargin(0.0f, 0.0f, 10.0f, 0.0f));
					PropertyValueText->SetVisibility(ESlateVisibility::Hidden);
				}
				EditableTextArray.Add(PropertyValueText);
				
				// 체크 박스 설정
				UCheckBox* PropertyCheckBox = NewObject<UCheckBox>(this);
 				PropertyCheckBox->SetIsChecked(bIsChecked);
				PropertyCheckBox->SetRenderScale(FVector2D(1.8f, 1.8f));

				UHorizontalBoxSlot* CheckBoxSlot = NewHorizontalBox->AddChildToHorizontalBox(PropertyCheckBox);
				if (CheckBoxSlot)
				{
					CheckBoxSlot->SetPadding(FMargin(0.0f, 0.0f, 10.0f, 0.0f));
					CheckBoxSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Right);
					CheckBoxSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
					CheckBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
				}
				CheckBoxMap.Add(Property->GetName(), PropertyCheckBox);
			}
			else
			{
				FString PropertyValue;
				Property->ExportText_InContainer(0, PropertyValue, &ConfigManager->ConfigData, &ConfigManager->ConfigData, this, PPF_None);

				if (CastField<FFloatProperty>(Property))
				{
					PropertyValue = FormatFloatWithDynamicPrecision(PropertyValue);
				}
				else if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property))
				{
					if (StructProperty->Struct == TBaseStructure<FVector2D>::Get())
					{
						FVector2D VectorValue;
						VectorValue.InitFromString(PropertyValue);
					
						TArray<FString> Parsed;
						PropertyValue.ParseIntoArray(Parsed, TEXT(","), true);
						if (Parsed.Num() > 0)
						{
							FString FormattedX = FormatFloatWithDynamicPrecision(Parsed[0]);
							FString FormattedY = FormatFloatWithDynamicPrecision(Parsed[1]);

							PropertyValue = FString::Printf(TEXT("(%s, %s)"), *FormattedX, *FormattedY);
						}
					}
					else if (StructProperty->Struct == TBaseStructure<FVector>::Get())
					{
						FVector VectorValue;
						VectorValue.InitFromString(PropertyValue);
						
						TArray<FString> Parsed;
						PropertyValue.ParseIntoArray(Parsed, TEXT(","), true);
						if (Parsed.Num() > 0)
						{
							FString FormattedX = FormatFloatWithDynamicPrecision(Parsed[0]);
							FString FormattedY = FormatFloatWithDynamicPrecision(Parsed[1]);
							FString FormattedZ = FormatFloatWithDynamicPrecision(Parsed[2]);

							PropertyValue = FString::Printf(TEXT("(%s, %s, %s)"), *FormattedX, *FormattedY, *FormattedZ);
						}
					}
					else if (StructProperty->Struct == TBaseStructure<FVector4>::Get())
					{
						FVector4 VectorValue;
						VectorValue.InitFromString(PropertyValue);

						TArray<FString> Parsed;
						PropertyValue.ParseIntoArray(Parsed, TEXT(","), true);
						if (Parsed.Num() > 0)
						{
							FString FormattedX = FormatFloatWithDynamicPrecision(Parsed[0]);
							FString FormattedY = FormatFloatWithDynamicPrecision(Parsed[1]);
							FString FormattedZ = FormatFloatWithDynamicPrecision(Parsed[2]);
							FString FormattedW = FormatFloatWithDynamicPrecision(Parsed[3]);

							PropertyValue = FString::Printf(TEXT("(%s, %s, %s, %s)"), *FormattedX, *FormattedY, *FormattedZ, *FormattedW);
						}
					}
				}

				PropertyValueText->SetText(FText::FromString(PropertyValue));
				UHorizontalBoxSlot* PropertyValueSlot = NewHorizontalBox->AddChildToHorizontalBox(PropertyValueText);
				if (PropertyValueSlot)
				{
					PropertyValueSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
					PropertyValueSlot->SetPadding(FMargin(0.0f, 0.0f, 10.0f, 0.0f));
				}

				EditableTextArray.Add(PropertyValueText);
				
				UHorizontalBoxSlot* EditableTextSlot = Cast<UHorizontalBoxSlot>(PropertyValueText->Slot);
				if (EditableTextSlot)
				{
					EditableTextSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Right);
					EditableTextSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
				}
			}
			
			FString FontBrushPath = TEXT("/Mujogeon/SettingUI/Resource/TWKEverett-Bold_Font");
			UObject *FontObject = LoadObject<UObject>(nullptr, *FontBrushPath);
			if (FontObject)
			{
				FSlateFontInfo FontInfo;
				FontInfo.FontObject = FontObject;
				FontInfo.Size = 15;
				PropertyNameText->SetFont(FontInfo);
				PropertyValueText->SetFont(FontInfo);
			}			
			else
			{
				FSlateFontInfo FontInfo = FSlateFontInfo(FCoreStyle::GetDefaultFontStyle("Regular", 20));
				PropertyNameText->SetFont(FontInfo);
				PropertyValueText->SetFont(FontInfo);
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Please check ConfigManager"));
	}
}

void ASettingUI::UpdateConfigData(FString JsonString)
{	
	if (ConfigManager->SetConfigData(JsonString))
	{
		//GenerateDynamicUI();
		UDebugManager::Instance()->AddLog("Received ConfigData");
	}
	else
	{
		UDebugManager::Instance()->AddLog("Failed to receive ConfigData");
	}
}

FString ASettingUI::FormatFloatWithDynamicPrecision(FString Value, bool KeepOneDecimalIfZero)
{
	if (Value.Contains(TEXT("("))) Value = Value.Replace(TEXT("("), TEXT(""));
	if (Value.Contains(TEXT(")"))) Value = Value.Replace(TEXT(")"), TEXT(""));
	 	
	// 소수점이 있는지 확인하고, 있다면 끝에서부터 0을 제거
	if (Value.Contains(TEXT(".")))
	{
		// 소수점 이하의 끝에 있는 0을 제거
		while (Value.EndsWith(TEXT("0")))
		{
			Value.RemoveAt(Value.Len() - 1, 1, false);
		}

		// 소수점 이하의 모든 값이 0이었던 경우, 소수 첫째 자리 0을 유지
		if (Value.EndsWith(TEXT(".")))
		{
			if (KeepOneDecimalIfZero)
			{
				Value += TEXT("0"); // 소수점 뒤에 0 추가
			}
			else
			{
				Value.RemoveAt(Value.Len() - 1, 1, false); // 소수점 제거
			}
		}
	}

	return Value;
}
