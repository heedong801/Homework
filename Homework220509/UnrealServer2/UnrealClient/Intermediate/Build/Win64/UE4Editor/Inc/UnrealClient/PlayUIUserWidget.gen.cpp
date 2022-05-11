// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/PlayUIUserWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayUIUserWidget() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UPlayUIUserWidget_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UPlayUIUserWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UPlayUIUserWidget::StaticRegisterNativesUPlayUIUserWidget()
	{
	}
	UClass* Z_Construct_UClass_UPlayUIUserWidget_NoRegister()
	{
		return UPlayUIUserWidget::StaticClass();
	}
	struct Z_Construct_UClass_UPlayUIUserWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayUIUserWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayUIUserWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/PlayUIUserWidget.h" },
		{ "ModuleRelativePath", "Play/PlayUIUserWidget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayUIUserWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayUIUserWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPlayUIUserWidget_Statics::ClassParams = {
		&UPlayUIUserWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPlayUIUserWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayUIUserWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPlayUIUserWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPlayUIUserWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPlayUIUserWidget, 2284197066);
	template<> UNREALCLIENT_API UClass* StaticClass<UPlayUIUserWidget>()
	{
		return UPlayUIUserWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPlayUIUserWidget(Z_Construct_UClass_UPlayUIUserWidget, &UPlayUIUserWidget::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UPlayUIUserWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayUIUserWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
