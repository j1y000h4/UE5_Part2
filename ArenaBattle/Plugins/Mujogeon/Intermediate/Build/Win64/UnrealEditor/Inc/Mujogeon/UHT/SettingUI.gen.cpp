// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mujogeon/Public/SettingUI.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSettingUI() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	MUJOGEON_API UClass* Z_Construct_UClass_AConfigManager_NoRegister();
	MUJOGEON_API UClass* Z_Construct_UClass_ASettingUI();
	MUJOGEON_API UClass* Z_Construct_UClass_ASettingUI_NoRegister();
	MUJOGEON_API UFunction* Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature();
	MUJOGEON_API UFunction* Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UCheckBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UEditableText_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UScrollBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Mujogeon();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// DECLARE_EVENT(ASettingUI, SettingUISaveConfig)\n// SettingUISaveConfig OnSettingUISaveConfig;\n" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
		{ "ToolTip", "DECLARE_EVENT(ASettingUI, SettingUISaveConfig)\nSettingUISaveConfig OnSettingUISaveConfig;" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASettingUI, nullptr, "SettingUISaveConfigBlueprint__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics
	{
		struct SettingUI_eventSettingUISaveConfig_Parms
		{
			FString JsonString;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_JsonString;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::NewProp_JsonString = { "JsonString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SettingUI_eventSettingUISaveConfig_Parms, JsonString), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::NewProp_JsonString,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// nDisplay \xec\x9a\xa9 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\n" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
		{ "ToolTip", "nDisplay \xec\x9a\xa9 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASettingUI, nullptr, "SettingUISaveConfig__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::SettingUI_eventSettingUISaveConfig_Parms), Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASettingUI::execUpdateConfigData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_JsonString);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateConfigData(Z_Param_JsonString);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASettingUI::execSaveConfigData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SaveConfigData();
		P_NATIVE_END;
	}
	void ASettingUI::StaticRegisterNativesASettingUI()
	{
		UClass* Class = ASettingUI::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SaveConfigData", &ASettingUI::execSaveConfigData },
			{ "UpdateConfigData", &ASettingUI::execUpdateConfigData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASettingUI_SaveConfigData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASettingUI_SaveConfigData_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASettingUI_SaveConfigData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASettingUI, nullptr, "SaveConfigData", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASettingUI_SaveConfigData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASettingUI_SaveConfigData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASettingUI_SaveConfigData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASettingUI_SaveConfigData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics
	{
		struct SettingUI_eventUpdateConfigData_Parms
		{
			FString JsonString;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_JsonString;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::NewProp_JsonString = { "JsonString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SettingUI_eventUpdateConfigData_Parms, JsonString), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::NewProp_JsonString,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::Function_MetaDataParams[] = {
		{ "Category", "SettingUI" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASettingUI, nullptr, "UpdateConfigData", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::SettingUI_eventUpdateConfigData_Parms), Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASettingUI_UpdateConfigData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASettingUI_UpdateConfigData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASettingUI);
	UClass* Z_Construct_UClass_ASettingUI_NoRegister()
	{
		return ASettingUI::StaticClass();
	}
	struct Z_Construct_UClass_ASettingUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSettingUISaveConfig_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSettingUISaveConfig;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSettingUISaveConfig_nDisplay_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSettingUISaveConfig_nDisplay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ScreenClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Screen_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Screen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TitleText_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleText;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScrollBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScrollBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SaveButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveButton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerController_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ConfigManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ConfigManager;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EditableTextArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EditableTextArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_EditableTextArray;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CheckBoxMap_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_CheckBoxMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CheckBoxMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_CheckBoxMap;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASettingUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Mujogeon,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASettingUI_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASettingUI_SaveConfigData, "SaveConfigData" }, // 414040722
		{ &Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature, "SettingUISaveConfig__DelegateSignature" }, // 3228870444
		{ &Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature, "SettingUISaveConfigBlueprint__DelegateSignature" }, // 2821451096
		{ &Z_Construct_UFunction_ASettingUI_UpdateConfigData, "UpdateConfigData" }, // 1406588954
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SettingUI.h" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig_MetaData[] = {
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig = { "OnSettingUISaveConfig", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, OnSettingUISaveConfig), Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfigBlueprint__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig_MetaData)) }; // 2821451096
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig_nDisplay_MetaData[] = {
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig_nDisplay = { "OnSettingUISaveConfig_nDisplay", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, OnSettingUISaveConfig_nDisplay), Z_Construct_UDelegateFunction_ASettingUI_SettingUISaveConfig__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig_nDisplay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig_nDisplay_MetaData)) }; // 3228870444
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_ScreenClass_MetaData[] = {
		{ "Category", "SettingUI" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_ScreenClass = { "ScreenClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, ScreenClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_ScreenClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_ScreenClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_Screen_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_Screen = { "Screen", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, Screen), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_Screen_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_Screen_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_TitleText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_TitleText = { "TitleText", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, TitleText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_TitleText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_TitleText_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_ScrollBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_ScrollBox = { "ScrollBox", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, ScrollBox), Z_Construct_UClass_UScrollBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_ScrollBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_ScrollBox_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_SaveButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_SaveButton = { "SaveButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, SaveButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_SaveButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_SaveButton_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_PlayerController_MetaData[] = {
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_PlayerController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_PlayerController_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_ConfigManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_ConfigManager = { "ConfigManager", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, ConfigManager), Z_Construct_UClass_AConfigManager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_ConfigManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_ConfigManager_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_EditableTextArray_Inner = { "EditableTextArray", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UEditableText_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_EditableTextArray_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_EditableTextArray = { "EditableTextArray", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, EditableTextArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_EditableTextArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_EditableTextArray_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap_ValueProp = { "CheckBoxMap", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 1, Z_Construct_UClass_UCheckBox_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap_Key_KeyProp = { "CheckBoxMap_Key", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SettingUI.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap = { "CheckBoxMap", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASettingUI, CheckBoxMap), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASettingUI_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_OnSettingUISaveConfig_nDisplay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_ScreenClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_Screen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_TitleText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_ScrollBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_SaveButton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_ConfigManager,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_EditableTextArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_EditableTextArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASettingUI_Statics::NewProp_CheckBoxMap,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASettingUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASettingUI>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASettingUI_Statics::ClassParams = {
		&ASettingUI::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASettingUI_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASettingUI_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASettingUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASettingUI()
	{
		if (!Z_Registration_Info_UClass_ASettingUI.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASettingUI.OuterSingleton, Z_Construct_UClass_ASettingUI_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASettingUI.OuterSingleton;
	}
	template<> MUJOGEON_API UClass* StaticClass<ASettingUI>()
	{
		return ASettingUI::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASettingUI);
	ASettingUI::~ASettingUI() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASettingUI, ASettingUI::StaticClass, TEXT("ASettingUI"), &Z_Registration_Info_UClass_ASettingUI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASettingUI), 1110729603U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_2244205122(TEXT("/Script/Mujogeon"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
