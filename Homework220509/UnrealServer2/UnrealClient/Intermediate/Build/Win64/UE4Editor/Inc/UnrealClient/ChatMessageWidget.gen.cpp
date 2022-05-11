// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ChatMessageWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChatMessageWidget() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UChatMessageWidget_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UChatMessageWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UChatMessageWidget::StaticRegisterNativesUChatMessageWidget()
	{
	}
	UClass* Z_Construct_UClass_UChatMessageWidget_NoRegister()
	{
		return UChatMessageWidget::StaticClass();
	}
	struct Z_Construct_UClass_UChatMessageWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChatString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ChatString;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UChatMessageWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UChatMessageWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/ChatMessageWidget.h" },
		{ "ModuleRelativePath", "Play/ChatMessageWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UChatMessageWidget_Statics::NewProp_ChatString_MetaData[] = {
		{ "Category", "ConnectInfo" },
		{ "ModuleRelativePath", "Play/ChatMessageWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UChatMessageWidget_Statics::NewProp_ChatString = { "ChatString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UChatMessageWidget, ChatString), METADATA_PARAMS(Z_Construct_UClass_UChatMessageWidget_Statics::NewProp_ChatString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UChatMessageWidget_Statics::NewProp_ChatString_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UChatMessageWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChatMessageWidget_Statics::NewProp_ChatString,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UChatMessageWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChatMessageWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UChatMessageWidget_Statics::ClassParams = {
		&UChatMessageWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UChatMessageWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UChatMessageWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UChatMessageWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UChatMessageWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UChatMessageWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UChatMessageWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UChatMessageWidget, 235157522);
	template<> UNREALCLIENT_API UClass* StaticClass<UChatMessageWidget>()
	{
		return UChatMessageWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UChatMessageWidget(Z_Construct_UClass_UChatMessageWidget, &UChatMessageWidget::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UChatMessageWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UChatMessageWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
