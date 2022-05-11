// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_FreeCameraPawn_generated_h
#error "FreeCameraPawn.generated.h already included, missing '#pragma once' in FreeCameraPawn.h"
#endif
#define UNREALCLIENT_FreeCameraPawn_generated_h

#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execMove_Test); \
	DECLARE_FUNCTION(execMoveUp_World); \
	DECLARE_FUNCTION(execMoveRight); \
	DECLARE_FUNCTION(execMoveForward);


#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMove_Test); \
	DECLARE_FUNCTION(execMoveUp_World); \
	DECLARE_FUNCTION(execMoveRight); \
	DECLARE_FUNCTION(execMoveForward);


#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFreeCameraPawn(); \
	friend struct Z_Construct_UClass_AFreeCameraPawn_Statics; \
public: \
	DECLARE_CLASS(AFreeCameraPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(AFreeCameraPawn)


#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_INCLASS \
private: \
	static void StaticRegisterNativesAFreeCameraPawn(); \
	friend struct Z_Construct_UClass_AFreeCameraPawn_Statics; \
public: \
	DECLARE_CLASS(AFreeCameraPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(AFreeCameraPawn)


#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFreeCameraPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFreeCameraPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFreeCameraPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFreeCameraPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFreeCameraPawn(AFreeCameraPawn&&); \
	NO_API AFreeCameraPawn(const AFreeCameraPawn&); \
public:


#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFreeCameraPawn(AFreeCameraPawn&&); \
	NO_API AFreeCameraPawn(const AFreeCameraPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFreeCameraPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFreeCameraPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFreeCameraPawn)


#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MovementComponent() { return STRUCT_OFFSET(AFreeCameraPawn, MovementComponent); } \
	FORCEINLINE static uint32 __PPO__CollisionComponent() { return STRUCT_OFFSET(AFreeCameraPawn, CollisionComponent); } \
	FORCEINLINE static uint32 __PPO__MeshComponent() { return STRUCT_OFFSET(AFreeCameraPawn, MeshComponent); }


#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_18_PROLOG
#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_INCLASS \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class AFreeCameraPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Global_FreeCameraPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
