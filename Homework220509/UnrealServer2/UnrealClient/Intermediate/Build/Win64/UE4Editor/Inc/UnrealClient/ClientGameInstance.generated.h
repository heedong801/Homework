// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_ClientGameInstance_generated_h
#error "ClientGameInstance.generated.h already included, missing '#pragma once' in ClientGameInstance.h"
#endif
#define UNREALCLIENT_ClientGameInstance_generated_h

#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetClientIndex);


#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetClientIndex);


#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUClientGameInstance(); \
	friend struct Z_Construct_UClass_UClientGameInstance_Statics; \
public: \
	DECLARE_CLASS(UClientGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UClientGameInstance)


#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_INCLASS \
private: \
	static void StaticRegisterNativesUClientGameInstance(); \
	friend struct Z_Construct_UClass_UClientGameInstance_Statics; \
public: \
	DECLARE_CLASS(UClientGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UClientGameInstance)


#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UClientGameInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UClientGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UClientGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UClientGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UClientGameInstance(UClientGameInstance&&); \
	NO_API UClientGameInstance(const UClientGameInstance&); \
public:


#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UClientGameInstance(UClientGameInstance&&); \
	NO_API UClientGameInstance(const UClientGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UClientGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UClientGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UClientGameInstance)


#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_PRIVATE_PROPERTY_OFFSET
#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_67_PROLOG
#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_INCLASS \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h_70_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class UClientGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Global_ClientGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
