// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DebugHUD.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MUJOGEON_DebugHUD_generated_h
#error "DebugHUD.generated.h already included, missing '#pragma once' in DebugHUD.h"
#endif
#define MUJOGEON_DebugHUD_generated_h

#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_SPARSE_DATA
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetHUDActive); \
	DECLARE_FUNCTION(execHandleMouseWheelScroll);


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetHUDActive); \
	DECLARE_FUNCTION(execHandleMouseWheelScroll);


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_ACCESSORS
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADebugHUD(); \
	friend struct Z_Construct_UClass_ADebugHUD_Statics; \
public: \
	DECLARE_CLASS(ADebugHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Mujogeon"), NO_API) \
	DECLARE_SERIALIZER(ADebugHUD)


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_INCLASS \
private: \
	static void StaticRegisterNativesADebugHUD(); \
	friend struct Z_Construct_UClass_ADebugHUD_Statics; \
public: \
	DECLARE_CLASS(ADebugHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Mujogeon"), NO_API) \
	DECLARE_SERIALIZER(ADebugHUD)


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADebugHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADebugHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADebugHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADebugHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADebugHUD(ADebugHUD&&); \
	NO_API ADebugHUD(const ADebugHUD&); \
public: \
	NO_API virtual ~ADebugHUD();


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADebugHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADebugHUD(ADebugHUD&&); \
	NO_API ADebugHUD(const ADebugHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADebugHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADebugHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADebugHUD) \
	NO_API virtual ~ADebugHUD();


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_12_PROLOG
#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_SPARSE_DATA \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_RPC_WRAPPERS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_ACCESSORS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_INCLASS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_SPARSE_DATA \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_ACCESSORS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_INCLASS_NO_PURE_DECLS \
	FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MUJOGEON_API UClass* StaticClass<class ADebugHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaBattle_Plugins_Mujogeon_Source_Mujogeon_Public_DebugHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
