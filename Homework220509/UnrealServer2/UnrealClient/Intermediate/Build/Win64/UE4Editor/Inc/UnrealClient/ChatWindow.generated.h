// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UUserWidget;
#ifdef UNREALCLIENT_ChatWindow_generated_h
#error "ChatWindow.generated.h already included, missing '#pragma once' in ChatWindow.h"
#endif
#define UNREALCLIENT_ChatWindow_generated_h

#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execNewMessageAdd); \
	DECLARE_FUNCTION(execChatSend);


#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execNewMessageAdd); \
	DECLARE_FUNCTION(execChatSend);


#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUChatWindow(); \
	friend struct Z_Construct_UClass_UChatWindow_Statics; \
public: \
	DECLARE_CLASS(UChatWindow, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UChatWindow)


#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUChatWindow(); \
	friend struct Z_Construct_UClass_UChatWindow_Statics; \
public: \
	DECLARE_CLASS(UChatWindow, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UChatWindow)


#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UChatWindow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UChatWindow) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UChatWindow); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UChatWindow); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UChatWindow(UChatWindow&&); \
	NO_API UChatWindow(const UChatWindow&); \
public:


#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UChatWindow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UChatWindow(UChatWindow&&); \
	NO_API UChatWindow(const UChatWindow&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UChatWindow); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UChatWindow); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UChatWindow)


#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_PRIVATE_PROPERTY_OFFSET
#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_14_PROLOG
#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_INCLASS \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Play_ChatWindow_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class UChatWindow>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Play_ChatWindow_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
