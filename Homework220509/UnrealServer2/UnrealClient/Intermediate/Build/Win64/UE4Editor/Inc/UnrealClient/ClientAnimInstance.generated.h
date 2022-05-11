// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_ClientAnimInstance_generated_h
#error "ClientAnimInstance.generated.h already included, missing '#pragma once' in ClientAnimInstance.h"
#endif
#define UNREALCLIENT_ClientAnimInstance_generated_h

#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAnimNotify_End);


#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAnimNotify_End);


#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUClientAnimInstance(); \
	friend struct Z_Construct_UClass_UClientAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UClientAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UClientAnimInstance)


#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUClientAnimInstance(); \
	friend struct Z_Construct_UClass_UClientAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UClientAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UClientAnimInstance)


#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UClientAnimInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UClientAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UClientAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UClientAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UClientAnimInstance(UClientAnimInstance&&); \
	NO_API UClientAnimInstance(const UClientAnimInstance&); \
public:


#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UClientAnimInstance(UClientAnimInstance&&); \
	NO_API UClientAnimInstance(const UClientAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UClientAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UClientAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UClientAnimInstance)


#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_PRIVATE_PROPERTY_OFFSET
#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_17_PROLOG
#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_INCLASS \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class UClientAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Play_ClientAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
