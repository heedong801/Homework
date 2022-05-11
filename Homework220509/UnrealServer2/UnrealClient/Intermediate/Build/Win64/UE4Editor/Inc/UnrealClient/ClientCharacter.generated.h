// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_ClientCharacter_generated_h
#error "ClientCharacter.generated.h already included, missing '#pragma once' in ClientCharacter.h"
#endif
#define UNREALCLIENT_ClientCharacter_generated_h

#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_RPC_WRAPPERS
#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAClientCharacter(); \
	friend struct Z_Construct_UClass_AClientCharacter_Statics; \
public: \
	DECLARE_CLASS(AClientCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(AClientCharacter)


#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAClientCharacter(); \
	friend struct Z_Construct_UClass_AClientCharacter_Statics; \
public: \
	DECLARE_CLASS(AClientCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(AClientCharacter)


#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AClientCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AClientCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AClientCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AClientCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AClientCharacter(AClientCharacter&&); \
	NO_API AClientCharacter(const AClientCharacter&); \
public:


#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AClientCharacter(AClientCharacter&&); \
	NO_API AClientCharacter(const AClientCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AClientCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AClientCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AClientCharacter)


#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Animations_() { return STRUCT_OFFSET(AClientCharacter, Animations_); }


#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_13_PROLOG
#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_INCLASS \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Play_ClientCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class AClientCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Play_ClientCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
