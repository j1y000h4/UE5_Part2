// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mujogeon/Public/DebugManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDebugManager() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	MUJOGEON_API UClass* Z_Construct_UClass_UDebugManager();
	MUJOGEON_API UClass* Z_Construct_UClass_UDebugManager_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Mujogeon();
// End Cross Module References
	DEFINE_FUNCTION(UDebugManager::execAddLog)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_NewLogEntry);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddLog(Z_Param_NewLogEntry);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDebugManager::execInstance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDebugManager**)Z_Param__Result=UDebugManager::Instance();
		P_NATIVE_END;
	}
	void UDebugManager::StaticRegisterNativesUDebugManager()
	{
		UClass* Class = UDebugManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddLog", &UDebugManager::execAddLog },
			{ "Instance", &UDebugManager::execInstance },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDebugManager_AddLog_Statics
	{
		struct DebugManager_eventAddLog_Parms
		{
			FString NewLogEntry;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_NewLogEntry;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDebugManager_AddLog_Statics::NewProp_NewLogEntry = { "NewLogEntry", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DebugManager_eventAddLog_Parms, NewLogEntry), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugManager_AddLog_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugManager_AddLog_Statics::NewProp_NewLogEntry,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDebugManager_AddLog_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/DebugManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugManager_AddLog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDebugManager, nullptr, "AddLog", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDebugManager_AddLog_Statics::DebugManager_eventAddLog_Parms), Z_Construct_UFunction_UDebugManager_AddLog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugManager_AddLog_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDebugManager_AddLog_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugManager_AddLog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDebugManager_AddLog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugManager_AddLog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDebugManager_Instance_Statics
	{
		struct DebugManager_eventInstance_Parms
		{
			UDebugManager* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDebugManager_Instance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DebugManager_eventInstance_Parms, ReturnValue), Z_Construct_UClass_UDebugManager_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDebugManager_Instance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDebugManager_Instance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDebugManager_Instance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/DebugManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDebugManager_Instance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDebugManager, nullptr, "Instance", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDebugManager_Instance_Statics::DebugManager_eventInstance_Parms), Z_Construct_UFunction_UDebugManager_Instance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugManager_Instance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDebugManager_Instance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDebugManager_Instance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDebugManager_Instance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDebugManager_Instance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDebugManager);
	UClass* Z_Construct_UClass_UDebugManager_NoRegister()
	{
		return UDebugManager::StaticClass();
	}
	struct Z_Construct_UClass_UDebugManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDebugManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Mujogeon,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDebugManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDebugManager_AddLog, "AddLog" }, // 1067633732
		{ &Z_Construct_UFunction_UDebugManager_Instance, "Instance" }, // 2018895160
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDebugManager_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "DebugManager.h" },
		{ "ModuleRelativePath", "Public/DebugManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDebugManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDebugManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDebugManager_Statics::ClassParams = {
		&UDebugManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDebugManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDebugManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDebugManager()
	{
		if (!Z_Registration_Info_UClass_UDebugManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDebugManager.OuterSingleton, Z_Construct_UClass_UDebugManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDebugManager.OuterSingleton;
	}
	template<> MUJOGEON_API UClass* StaticClass<UDebugManager>()
	{
		return UDebugManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDebugManager);
	UDebugManager::~UDebugManager() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDebugManager, UDebugManager::StaticClass, TEXT("UDebugManager"), &Z_Registration_Info_UClass_UDebugManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDebugManager), 1265538972U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugManager_h_552668902(TEXT("/Script/Mujogeon"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
