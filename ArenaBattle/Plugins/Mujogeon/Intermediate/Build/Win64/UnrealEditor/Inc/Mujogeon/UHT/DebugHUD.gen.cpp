// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mujogeon/Public/DebugHUD.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDebugHUD() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	ENGINE_API UClass* Z_Construct_UClass_UFont_NoRegister();
	MUJOGEON_API UClass* Z_Construct_UClass_ADebugHUD();
	MUJOGEON_API UClass* Z_Construct_UClass_ADebugHUD_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Mujogeon();
// End Cross Module References
	DEFINE_FUNCTION(ADebugHUD::execSetHUDActive)
	{
		P_GET_UBOOL(Z_Param_bActive);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHUDActive(Z_Param_bActive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADebugHUD::execHandleMouseWheelScroll)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_ScrollDirection);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleMouseWheelScroll(Z_Param_ScrollDirection);
		P_NATIVE_END;
	}
	void ADebugHUD::StaticRegisterNativesADebugHUD()
	{
		UClass* Class = ADebugHUD::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleMouseWheelScroll", &ADebugHUD::execHandleMouseWheelScroll },
			{ "SetHUDActive", &ADebugHUD::execSetHUDActive },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics
	{
		struct DebugHUD_eventHandleMouseWheelScroll_Parms
		{
			float ScrollDirection;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ScrollDirection;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::NewProp_ScrollDirection = { "ScrollDirection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DebugHUD_eventHandleMouseWheelScroll_Parms, ScrollDirection), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::NewProp_ScrollDirection,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/DebugHUD.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADebugHUD, nullptr, "HandleMouseWheelScroll", nullptr, nullptr, sizeof(Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::DebugHUD_eventHandleMouseWheelScroll_Parms), Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics
	{
		struct DebugHUD_eventSetHUDActive_Parms
		{
			bool bActive;
		};
		static void NewProp_bActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bActive;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::NewProp_bActive_SetBit(void* Obj)
	{
		((DebugHUD_eventSetHUDActive_Parms*)Obj)->bActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::NewProp_bActive = { "bActive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(DebugHUD_eventSetHUDActive_Parms), &Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::NewProp_bActive_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::NewProp_bActive,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/DebugHUD.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADebugHUD, nullptr, "SetHUDActive", nullptr, nullptr, sizeof(Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::DebugHUD_eventSetHUDActive_Parms), Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADebugHUD_SetHUDActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADebugHUD_SetHUDActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADebugHUD);
	UClass* Z_Construct_UClass_ADebugHUD_NoRegister()
	{
		return ADebugHUD::StaticClass();
	}
	struct Z_Construct_UClass_ADebugHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsOverlayActive_MetaData[];
#endif
		static void NewProp_bIsOverlayActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOverlayActive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoadedFont_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LoadedFont;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADebugHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_Mujogeon,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ADebugHUD_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ADebugHUD_HandleMouseWheelScroll, "HandleMouseWheelScroll" }, // 2249934370
		{ &Z_Construct_UFunction_ADebugHUD_SetHUDActive, "SetHUDActive" }, // 983548888
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugHUD_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "DebugHUD.h" },
		{ "ModuleRelativePath", "Public/DebugHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugHUD_Statics::NewProp_bIsOverlayActive_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/DebugHUD.h" },
	};
#endif
	void Z_Construct_UClass_ADebugHUD_Statics::NewProp_bIsOverlayActive_SetBit(void* Obj)
	{
		((ADebugHUD*)Obj)->bIsOverlayActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADebugHUD_Statics::NewProp_bIsOverlayActive = { "bIsOverlayActive", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ADebugHUD), &Z_Construct_UClass_ADebugHUD_Statics::NewProp_bIsOverlayActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADebugHUD_Statics::NewProp_bIsOverlayActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugHUD_Statics::NewProp_bIsOverlayActive_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADebugHUD_Statics::NewProp_LoadedFont_MetaData[] = {
		{ "ModuleRelativePath", "Public/DebugHUD.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADebugHUD_Statics::NewProp_LoadedFont = { "LoadedFont", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADebugHUD, LoadedFont), Z_Construct_UClass_UFont_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADebugHUD_Statics::NewProp_LoadedFont_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugHUD_Statics::NewProp_LoadedFont_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADebugHUD_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugHUD_Statics::NewProp_bIsOverlayActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADebugHUD_Statics::NewProp_LoadedFont,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADebugHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADebugHUD>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADebugHUD_Statics::ClassParams = {
		&ADebugHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ADebugHUD_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ADebugHUD_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ADebugHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADebugHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADebugHUD()
	{
		if (!Z_Registration_Info_UClass_ADebugHUD.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADebugHUD.OuterSingleton, Z_Construct_UClass_ADebugHUD_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADebugHUD.OuterSingleton;
	}
	template<> MUJOGEON_API UClass* StaticClass<ADebugHUD>()
	{
		return ADebugHUD::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADebugHUD);
	ADebugHUD::~ADebugHUD() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADebugHUD, ADebugHUD::StaticClass, TEXT("ADebugHUD"), &Z_Registration_Info_UClass_ADebugHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADebugHUD), 2102026506U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_1616603547(TEXT("/Script/Mujogeon"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
