// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ConfigManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FConfigData;
#ifdef MUJOGEON_ConfigManager_generated_h
#error "ConfigManager.generated.h already included, missing '#pragma once' in ConfigManager.h"
#endif
#define MUJOGEON_ConfigManager_generated_h

#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_SPARSE_DATA
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetConfigData);


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetConfigData);


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_ACCESSORS
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAConfigManager(); \
	friend struct Z_Construct_UClass_AConfigManager_Statics; \
public: \
	DECLARE_CLASS(AConfigManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Mujogeon"), NO_API) \
	DECLARE_SERIALIZER(AConfigManager)


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_INCLASS \
private: \
	static void StaticRegisterNativesAConfigManager(); \
	friend struct Z_Construct_UClass_AConfigManager_Statics; \
public: \
	DECLARE_CLASS(AConfigManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Mujogeon"), NO_API) \
	DECLARE_SERIALIZER(AConfigManager)


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AConfigManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AConfigManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AConfigManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AConfigManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AConfigManager(AConfigManager&&); \
	NO_API AConfigManager(const AConfigManager&); \
public: \
	NO_API virtual ~AConfigManager();


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AConfigManager(AConfigManager&&); \
	NO_API AConfigManager(const AConfigManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AConfigManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AConfigManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AConfigManager) \
	NO_API virtual ~AConfigManager();


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_34_PROLOG
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_SPARSE_DATA \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_RPC_WRAPPERS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_ACCESSORS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_INCLASS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_SPARSE_DATA \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_ACCESSORS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_INCLASS_NO_PURE_DECLS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MUJOGEON_API UClass* StaticClass<class AConfigManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_ConfigManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
