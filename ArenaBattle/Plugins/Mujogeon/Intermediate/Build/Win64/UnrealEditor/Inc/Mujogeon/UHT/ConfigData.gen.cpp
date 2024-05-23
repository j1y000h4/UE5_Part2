// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mujogeon/Public/ConfigData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConfigData() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector4();
	MUJOGEON_API UScriptStruct* Z_Construct_UScriptStruct_FConfigData();
	UPackage* Z_Construct_UPackage__Script_Mujogeon();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ConfigData;
class UScriptStruct* FConfigData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ConfigData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ConfigData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FConfigData, Z_Construct_UPackage__Script_Mujogeon(), TEXT("ConfigData"));
	}
	return Z_Registration_Info_UScriptStruct_ConfigData.OuterSingleton;
}
template<> MUJOGEON_API UScriptStruct* StaticStruct<FConfigData>()
{
	return FConfigData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FConfigData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleInt_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SampleInt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleFloat_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SampleFloat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleBool_MetaData[];
#endif
		static void NewProp_SampleBool_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SampleBool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SampleString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleVector2D_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SampleVector2D;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleVector_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SampleVector;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleVector4_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SampleVector4;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConfigData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ConfigData.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FConfigData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FConfigData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleInt_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/ConfigData.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleInt = { "SampleInt", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FConfigData, SampleInt), METADATA_PARAMS(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleInt_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleInt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleFloat_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/ConfigData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleFloat = { "SampleFloat", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FConfigData, SampleFloat), METADATA_PARAMS(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleFloat_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleFloat_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleBool_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/ConfigData.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleBool_SetBit(void* Obj)
	{
		((FConfigData*)Obj)->SampleBool = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleBool = { "SampleBool", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FConfigData), &Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleBool_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleBool_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleBool_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleString_MetaData[] = {
		{ "ModuleRelativePath", "Public/ConfigData.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleString = { "SampleString", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FConfigData, SampleString), METADATA_PARAMS(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleString_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleString_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector2D_MetaData[] = {
		{ "ModuleRelativePath", "Public/ConfigData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector2D = { "SampleVector2D", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FConfigData, SampleVector2D), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector2D_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector2D_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector_MetaData[] = {
		{ "ModuleRelativePath", "Public/ConfigData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector = { "SampleVector", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FConfigData, SampleVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector4_MetaData[] = {
		{ "ModuleRelativePath", "Public/ConfigData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector4 = { "SampleVector4", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FConfigData, SampleVector4), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector4_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector4_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FConfigData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleInt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleFloat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleBool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector2D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConfigData_Statics::NewProp_SampleVector4,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FConfigData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Mujogeon,
		nullptr,
		&NewStructOps,
		"ConfigData",
		sizeof(FConfigData),
		alignof(FConfigData),
		Z_Construct_UScriptStruct_FConfigData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FConfigData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConfigData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FConfigData()
	{
		if (!Z_Registration_Info_UScriptStruct_ConfigData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ConfigData.InnerSingleton, Z_Construct_UScriptStruct_FConfigData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ConfigData.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigData_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigData_h_Statics::ScriptStructInfo[] = {
		{ FConfigData::StaticStruct, Z_Construct_UScriptStruct_FConfigData_Statics::NewStructOps, TEXT("ConfigData"), &Z_Registration_Info_UScriptStruct_ConfigData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FConfigData), 2131664225U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigData_h_645653623(TEXT("/Script/Mujogeon"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigData_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigData_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
