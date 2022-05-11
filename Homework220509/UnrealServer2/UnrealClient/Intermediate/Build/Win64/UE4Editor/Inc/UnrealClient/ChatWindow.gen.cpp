// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ChatWindow.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChatWindow() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UChatWindow_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UChatWindow();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UListView_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UChatWindow::execNewMessageAdd)
	{
		P_GET_OBJECT(UObject,Z_Param__Object);
		P_GET_OBJECT(UUserWidget,Z_Param__Widget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->NewMessageAdd(Z_Param__Object,Z_Param__Widget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UChatWindow::execChatSend)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param__Text);
		P_GET_PROPERTY(FByteProperty,Z_Param__Type);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ChatSend(Z_Param__Text,ETextCommit::Type(Z_Param__Type));
		P_NATIVE_END;
	}
	void UChatWindow::StaticRegisterNativesUChatWindow()
	{
		UClass* Class = UChatWindow::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChatSend", &UChatWindow::execChatSend },
			{ "NewMessageAdd", &UChatWindow::execNewMessageAdd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UChatWindow_ChatSend_Statics
	{
		struct ChatWindow_eventChatSend_Parms
		{
			FString _Text;
			TEnumAsByte<ETextCommit::Type> _Type;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp__Text;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp__Type;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChatWindow_ChatSend_Statics::NewProp__Text = { "_Text", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ChatWindow_eventChatSend_Parms, _Text), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChatWindow_ChatSend_Statics::NewProp__Type = { "_Type", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ChatWindow_eventChatSend_Parms, _Type), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChatWindow_ChatSend_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChatWindow_ChatSend_Statics::NewProp__Text,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChatWindow_ChatSend_Statics::NewProp__Type,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UChatWindow_ChatSend_Statics::Function_MetaDataParams[] = {
		{ "Category", "Chat" },
		{ "ModuleRelativePath", "Play/ChatWindow.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UChatWindow_ChatSend_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UChatWindow, nullptr, "ChatSend", nullptr, nullptr, sizeof(ChatWindow_eventChatSend_Parms), Z_Construct_UFunction_UChatWindow_ChatSend_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChatWindow_ChatSend_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UChatWindow_ChatSend_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UChatWindow_ChatSend_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UChatWindow_ChatSend()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UChatWindow_ChatSend_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics
	{
		struct ChatWindow_eventNewMessageAdd_Parms
		{
			UObject* _Object;
			UUserWidget* _Widget;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__Object;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__Widget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__Widget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::NewProp__Object = { "_Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ChatWindow_eventNewMessageAdd_Parms, _Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::NewProp__Widget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::NewProp__Widget = { "_Widget", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ChatWindow_eventNewMessageAdd_Parms, _Widget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::NewProp__Widget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::NewProp__Widget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::NewProp__Object,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::NewProp__Widget,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::Function_MetaDataParams[] = {
		{ "Category", "Chat" },
		{ "ModuleRelativePath", "Play/ChatWindow.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UChatWindow, nullptr, "NewMessageAdd", nullptr, nullptr, sizeof(ChatWindow_eventNewMessageAdd_Parms), Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UChatWindow_NewMessageAdd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UChatWindow_NewMessageAdd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UChatWindow_NoRegister()
	{
		return UChatWindow::StaticClass();
	}
	struct Z_Construct_UClass_UChatWindow_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChatString__MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ChatString_;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MessageListView__MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MessageListView_;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UChatWindow_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UChatWindow_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UChatWindow_ChatSend, "ChatSend" }, // 2728518523
		{ &Z_Construct_UFunction_UChatWindow_NewMessageAdd, "NewMessageAdd" }, // 4175700122
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UChatWindow_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/ChatWindow.h" },
		{ "ModuleRelativePath", "Play/ChatWindow.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UChatWindow_Statics::NewProp_ChatString__MetaData[] = {
		{ "Category", "Chat" },
		{ "ModuleRelativePath", "Play/ChatWindow.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UChatWindow_Statics::NewProp_ChatString_ = { "ChatString_", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UChatWindow, ChatString_), METADATA_PARAMS(Z_Construct_UClass_UChatWindow_Statics::NewProp_ChatString__MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UChatWindow_Statics::NewProp_ChatString__MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UChatWindow_Statics::NewProp_MessageListView__MetaData[] = {
		{ "Category", "Chat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Play/ChatWindow.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UChatWindow_Statics::NewProp_MessageListView_ = { "MessageListView_", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UChatWindow, MessageListView_), Z_Construct_UClass_UListView_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UChatWindow_Statics::NewProp_MessageListView__MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UChatWindow_Statics::NewProp_MessageListView__MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UChatWindow_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChatWindow_Statics::NewProp_ChatString_,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChatWindow_Statics::NewProp_MessageListView_,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UChatWindow_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChatWindow>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UChatWindow_Statics::ClassParams = {
		&UChatWindow::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UChatWindow_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UChatWindow_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UChatWindow_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UChatWindow_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UChatWindow()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UChatWindow_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UChatWindow, 857076790);
	template<> UNREALCLIENT_API UClass* StaticClass<UChatWindow>()
	{
		return UChatWindow::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UChatWindow(Z_Construct_UClass_UChatWindow, &UChatWindow::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UChatWindow"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UChatWindow);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
