// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mujogeon/Public/Toast.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeToast() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	MUJOGEON_API UClass* Z_Construct_UClass_UToast();
	MUJOGEON_API UClass* Z_Construct_UClass_UToast_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Mujogeon();
// End Cross Module References
	DEFINE_FUNCTION(UToast::execBake)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Message);
		P_FINISH;
		P_NATIVE_BEGIN;
		UToast::Bake(Z_Param_Message);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UToast::execGetInstance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UToast**)Z_Param__Result=UToast::GetInstance();
		P_NATIVE_END;
	}
	void UToast::StaticRegisterNativesUToast()
	{
		UClass* Class = UToast::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Bake", &UToast::execBake },
			{ "GetInstance", &UToast::execGetInstance },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UToast_Bake_Statics
	{
		struct Toast_eventBake_Parms
		{
			FString Message;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UToast_Bake_Statics::NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UToast_Bake_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(Toast_eventBake_Parms, Message), METADATA_PARAMS(Z_Construct_UFunction_UToast_Bake_Statics::NewProp_Message_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UToast_Bake_Statics::NewProp_Message_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToast_Bake_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToast_Bake_Statics::NewProp_Message,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UToast_Bake_Statics::Function_MetaDataParams[] = {
		{ "Category", "Toast" },
		{ "ModuleRelativePath", "Public/Toast.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToast_Bake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UToast, nullptr, "Bake", nullptr, nullptr, sizeof(Z_Construct_UFunction_UToast_Bake_Statics::Toast_eventBake_Parms), Z_Construct_UFunction_UToast_Bake_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UToast_Bake_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UToast_Bake_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UToast_Bake_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UToast_Bake()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToast_Bake_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UToast_GetInstance_Statics
	{
		struct Toast_eventGetInstance_Parms
		{
			UToast* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UToast_GetInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(Toast_eventGetInstance_Parms, ReturnValue), Z_Construct_UClass_UToast_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UToast_GetInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UToast_GetInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UToast_GetInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Toast" },
		{ "ModuleRelativePath", "Public/Toast.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UToast_GetInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UToast, nullptr, "GetInstance", nullptr, nullptr, sizeof(Z_Construct_UFunction_UToast_GetInstance_Statics::Toast_eventGetInstance_Parms), Z_Construct_UFunction_UToast_GetInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UToast_GetInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UToast_GetInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UToast_GetInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UToast_GetInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UToast_GetInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UToast);
	UClass* Z_Construct_UClass_UToast_NoRegister()
	{
		return UToast::StaticClass();
	}
	struct Z_Construct_UClass_UToast_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToastScreenClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ToastScreenClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Screen_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Screen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToastImage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ToastImage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToastText_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ToastText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UToast_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Mujogeon,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UToast_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UToast_Bake, "Bake" }, // 3440692817
		{ &Z_Construct_UFunction_UToast_GetInstance, "GetInstance" }, // 3670754208
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UToast_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Toast.h" },
		{ "ModuleRelativePath", "Public/Toast.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UToast_Statics::NewProp_ToastScreenClass_MetaData[] = {
		{ "ModuleRelativePath", "Public/Toast.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UToast_Statics::NewProp_ToastScreenClass = { "ToastScreenClass", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UToast, ToastScreenClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UToast_Statics::NewProp_ToastScreenClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UToast_Statics::NewProp_ToastScreenClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UToast_Statics::NewProp_Screen_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Toast.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UToast_Statics::NewProp_Screen = { "Screen", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UToast, Screen), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UToast_Statics::NewProp_Screen_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UToast_Statics::NewProp_Screen_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UToast_Statics::NewProp_ToastImage_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Toast.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UToast_Statics::NewProp_ToastImage = { "ToastImage", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UToast, ToastImage), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UToast_Statics::NewProp_ToastImage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UToast_Statics::NewProp_ToastImage_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UToast_Statics::NewProp_ToastText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Toast.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UToast_Statics::NewProp_ToastText = { "ToastText", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UToast, ToastText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UToast_Statics::NewProp_ToastText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UToast_Statics::NewProp_ToastText_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UToast_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToast_Statics::NewProp_ToastScreenClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToast_Statics::NewProp_Screen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToast_Statics::NewProp_ToastImage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToast_Statics::NewProp_ToastText,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UToast_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToast>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UToast_Statics::ClassParams = {
		&UToast::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UToast_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UToast_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UToast_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UToast_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UToast()
	{
		if (!Z_Registration_Info_UClass_UToast.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToast.OuterSingleton, Z_Construct_UClass_UToast_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UToast.OuterSingleton;
	}
	template<> MUJOGEON_API UClass* StaticClass<UToast>()
	{
		return UToast::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UToast);
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_Toast_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_Toast_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UToast, UToast::StaticClass, TEXT("UToast"), &Z_Registration_Info_UClass_UToast, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToast), 3701477412U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_Toast_h_181847575(TEXT("/Script/Mujogeon"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_Toast_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_Toast_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
