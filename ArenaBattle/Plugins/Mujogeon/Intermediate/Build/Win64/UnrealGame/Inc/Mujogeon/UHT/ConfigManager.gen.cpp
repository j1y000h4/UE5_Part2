// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mujogeon/Public/ConfigManager.h"
#include "Mujogeon/Public/ConfigData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConfigManager() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	MUJOGEON_API UClass* Z_Construct_UClass_AConfigManager();
	MUJOGEON_API UClass* Z_Construct_UClass_AConfigManager_NoRegister();
	MUJOGEON_API UClass* Z_Construct_UClass_ASettingUI_NoRegister();
	MUJOGEON_API UScriptStruct* Z_Construct_UScriptStruct_FConfigData();
	UPackage* Z_Construct_UPackage__Script_Mujogeon();
// End Cross Module References
	DEFINE_FUNCTION(AConfigManager::execGetConfigData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FConfigData*)Z_Param__Result=AConfigManager::GetConfigData();
		P_NATIVE_END;
	}
	void AConfigManager::StaticRegisterNativesAConfigManager()
	{
		UClass* Class = AConfigManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetConfigData", &AConfigManager::execGetConfigData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AConfigManager_GetConfigData_Statics
	{
		struct ConfigManager_eventGetConfigData_Parms
		{
			FConfigData ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ConfigManager_eventGetConfigData_Parms, ReturnValue), Z_Construct_UScriptStruct_FConfigData, METADATA_PARAMS(nullptr, 0) }; // 2131664225
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/ConfigManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AConfigManager, nullptr, "GetConfigData", nullptr, nullptr, sizeof(Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::ConfigManager_eventGetConfigData_Parms), Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AConfigManager_GetConfigData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AConfigManager_GetConfigData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AConfigManager);
	UClass* Z_Construct_UClass_AConfigManager_NoRegister()
	{
		return AConfigManager::StaticClass();
	}
	struct Z_Construct_UClass_AConfigManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SettingUI_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SettingUI;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AConfigManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Mujogeon,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AConfigManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AConfigManager_GetConfigData, "GetConfigData" }, // 1364624075
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConfigManager_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// USTRUCT(BlueprintType)\n// struct FConfigData\n// {\n// \x09GENERATED_USTRUCT_BODY()\n//\n// \x09UPROPERTY(BlueprintReadOnly, Category = \"Config\")\n// \x09int32 SampleInt = 1027;\n// \x09UPROPERTY(BlueprintReadOnly, Category = \"Config\")\n// \x09""float SampleFloat = 1.45f;\n// \x09UPROPERTY(BlueprintReadOnly, Category = \"Config\")\n// \x09""bool SampleBool = false;\n// \x09UPROPERTY()\n// \x09""FString SampleString = \"Hello Setting UI\";\n// \x09UPROPERTY()\n// \x09""FVector2D SampleVector2D = FVector2D(1.1f, 2.2f);\n// \x09UPROPERTY()\n// \x09""FVector SampleVector = FVector(1.1f, 2.2f, 3.3f);\n// \x09UPROPERTY()\n// \x09""FVector4 SampleVector4 = FVector4(1.1f, 2.2f, 3.3f, 4.4f);\n// };\n" },
		{ "IncludePath", "ConfigManager.h" },
		{ "ModuleRelativePath", "Public/ConfigManager.h" },
		{ "ToolTip", "USTRUCT(BlueprintType)\nstruct FConfigData\n{\n      GENERATED_USTRUCT_BODY()\n\n      UPROPERTY(BlueprintReadOnly, Category = \"Config\")\n      int32 SampleInt = 1027;\n      UPROPERTY(BlueprintReadOnly, Category = \"Config\")\n      float SampleFloat = 1.45f;\n      UPROPERTY(BlueprintReadOnly, Category = \"Config\")\n      bool SampleBool = false;\n      UPROPERTY()\n      FString SampleString = \"Hello Setting UI\";\n      UPROPERTY()\n      FVector2D SampleVector2D = FVector2D(1.1f, 2.2f);\n      UPROPERTY()\n      FVector SampleVector = FVector(1.1f, 2.2f, 3.3f);\n      UPROPERTY()\n      FVector4 SampleVector4 = FVector4(1.1f, 2.2f, 3.3f, 4.4f);\n};" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConfigManager_Statics::NewProp_SettingUI_MetaData[] = {
		{ "ModuleRelativePath", "Public/ConfigManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AConfigManager_Statics::NewProp_SettingUI = { "SettingUI", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AConfigManager, SettingUI), Z_Construct_UClass_ASettingUI_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AConfigManager_Statics::NewProp_SettingUI_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConfigManager_Statics::NewProp_SettingUI_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AConfigManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConfigManager_Statics::NewProp_SettingUI,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AConfigManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AConfigManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AConfigManager_Statics::ClassParams = {
		&AConfigManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AConfigManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AConfigManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AConfigManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AConfigManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AConfigManager()
	{
		if (!Z_Registration_Info_UClass_AConfigManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AConfigManager.OuterSingleton, Z_Construct_UClass_AConfigManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AConfigManager.OuterSingleton;
	}
	template<> MUJOGEON_API UClass* StaticClass<AConfigManager>()
	{
		return AConfigManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AConfigManager);
	AConfigManager::~AConfigManager() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AConfigManager, AConfigManager::StaticClass, TEXT("AConfigManager"), &Z_Registration_Info_UClass_AConfigManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AConfigManager), 588099624U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_218647155(TEXT("/Script/Mujogeon"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
