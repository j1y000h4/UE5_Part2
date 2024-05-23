// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mujogeon/Public/DebugViewer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDebugViewer() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	MUJOGEON_API UClass* Z_Construct_UClass_ADebugViewer();
	MUJOGEON_API UClass* Z_Construct_UClass_ADebugViewer_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UScrollBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Mujogeon();
// End Cross Module References
	void ADebugViewer::StaticRegisterNativesADebugViewer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADebugViewer);
	UClass* Z_Construct_UClass_ADebugViewer_NoRegister()
	{
		return ADebugViewer::StaticClass();
	}
	struct Z_Construct_UClass_ADebugViewer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LogScreenClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_LogScreenClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FontSize_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_FontSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxLogCount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxLogCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsShowOutputLog_MetaData[];
#endif
		static void NewProp_IsShowOutputLog_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsShowOutputLog;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LogScreen_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LogScreen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScrollBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScrollBox;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TextBlockArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextBlockArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_TextBlockArray;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerController_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADebugViewer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Mujogeon,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DebugViewer.h" },
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreenClass_MetaData[] = {
		{ "Category", "DebugViewer" },
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreenClass = { "LogScreenClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADebugViewer, LogScreenClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreenClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreenClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::NewProp_FontSize_MetaData[] = {
		{ "Category", "DebugViewer" },
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_FontSize = { "FontSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADebugViewer, FontSize), METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::NewProp_FontSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::NewProp_FontSize_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::NewProp_MaxLogCount_MetaData[] = {
		{ "Category", "DebugViewer" },
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_MaxLogCount = { "MaxLogCount", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADebugViewer, MaxLogCount), METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::NewProp_MaxLogCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::NewProp_MaxLogCount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::NewProp_IsShowOutputLog_MetaData[] = {
		{ "Category", "DebugViewer" },
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
	void Z_Construct_UClass_ADebugViewer_Statics::NewProp_IsShowOutputLog_SetBit(void* Obj)
	{
		((ADebugViewer*)Obj)->IsShowOutputLog = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_IsShowOutputLog = { "IsShowOutputLog", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ADebugViewer), &Z_Construct_UClass_ADebugViewer_Statics::NewProp_IsShowOutputLog_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::NewProp_IsShowOutputLog_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::NewProp_IsShowOutputLog_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreen_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreen = { "LogScreen", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADebugViewer, LogScreen), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreen_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreen_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::NewProp_ScrollBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_ScrollBox = { "ScrollBox", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADebugViewer, ScrollBox), Z_Construct_UClass_UScrollBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::NewProp_ScrollBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::NewProp_ScrollBox_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_TextBlockArray_Inner = { "TextBlockArray", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::NewProp_TextBlockArray_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_TextBlockArray = { "TextBlockArray", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADebugViewer, TextBlockArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::NewProp_TextBlockArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::NewProp_TextBlockArray_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugViewer_Statics::NewProp_PlayerController_MetaData[] = {
		{ "ModuleRelativePath", "Public/DebugViewer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADebugViewer_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADebugViewer, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::NewProp_PlayerController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::NewProp_PlayerController_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADebugViewer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreenClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_FontSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_MaxLogCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_IsShowOutputLog,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_LogScreen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_ScrollBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_TextBlockArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_TextBlockArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugViewer_Statics::NewProp_PlayerController,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADebugViewer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADebugViewer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADebugViewer_Statics::ClassParams = {
		&ADebugViewer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADebugViewer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADebugViewer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugViewer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADebugViewer()
	{
		if (!Z_Registration_Info_UClass_ADebugViewer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADebugViewer.OuterSingleton, Z_Construct_UClass_ADebugViewer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADebugViewer.OuterSingleton;
	}
	template<> MUJOGEON_API UClass* StaticClass<ADebugViewer>()
	{
		return ADebugViewer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADebugViewer);
	ADebugViewer::~ADebugViewer() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugViewer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugViewer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADebugViewer, ADebugViewer::StaticClass, TEXT("ADebugViewer"), &Z_Registration_Info_UClass_ADebugViewer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADebugViewer), 1451512535U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugViewer_h_1224917450(TEXT("/Script/Mujogeon"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugViewer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugViewer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
