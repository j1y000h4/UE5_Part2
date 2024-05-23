// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SettingUI.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MUJOGEON_SettingUI_generated_h
#error "SettingUI.generated.h already included, missing '#pragma once' in SettingUI.h"
#endif
#define MUJOGEON_SettingUI_generated_h

#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_44_DELEGATE \
static inline void FSettingUISaveConfigBlueprint_DelegateWrapper(const FMulticastScriptDelegate& SettingUISaveConfigBlueprint) \
{ \
	SettingUISaveConfigBlueprint.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_49_DELEGATE \
struct SettingUI_eventSettingUISaveConfig_Parms \
{ \
	FString JsonString; \
}; \
static inline void FSettingUISaveConfig_DelegateWrapper(const FMulticastScriptDelegate& SettingUISaveConfig, const FString& JsonString) \
{ \
	SettingUI_eventSettingUISaveConfig_Parms Parms; \
	Parms.JsonString=JsonString; \
	SettingUISaveConfig.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_SPARSE_DATA
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateConfigData); \
	DECLARE_FUNCTION(execSaveConfigData);


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateConfigData); \
	DECLARE_FUNCTION(execSaveConfigData);


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_ACCESSORS
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASettingUI(); \
	friend struct Z_Construct_UClass_ASettingUI_Statics; \
public: \
	DECLARE_CLASS(ASettingUI, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Mujogeon"), NO_API) \
	DECLARE_SERIALIZER(ASettingUI)


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_INCLASS \
private: \
	static void StaticRegisterNativesASettingUI(); \
	friend struct Z_Construct_UClass_ASettingUI_Statics; \
public: \
	DECLARE_CLASS(ASettingUI, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Mujogeon"), NO_API) \
	DECLARE_SERIALIZER(ASettingUI)


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASettingUI(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASettingUI) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASettingUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASettingUI); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASettingUI(ASettingUI&&); \
	NO_API ASettingUI(const ASettingUI&); \
public: \
	NO_API virtual ~ASettingUI();


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASettingUI(ASettingUI&&); \
	NO_API ASettingUI(const ASettingUI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASettingUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASettingUI); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASettingUI) \
	NO_API virtual ~ASettingUI();


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_16_PROLOG
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_SPARSE_DATA \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_RPC_WRAPPERS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_ACCESSORS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_INCLASS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_SPARSE_DATA \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_ACCESSORS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_INCLASS_NO_PURE_DECLS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MUJOGEON_API UClass* StaticClass<class ASettingUI>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_SettingUI_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
