// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/RankUI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRankUI() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_URankUI_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_URankUI();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void URankUI::StaticRegisterNativesURankUI()
	{
	}
	UClass* Z_Construct_UClass_URankUI_NoRegister()
	{
		return URankUI::StaticClass();
	}
	struct Z_Construct_UClass_URankUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URankUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URankUI_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/RankUI.h" },
		{ "ModuleRelativePath", "Play/RankUI.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URankUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URankUI>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URankUI_Statics::ClassParams = {
		&URankUI::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_URankUI_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URankUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URankUI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URankUI_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URankUI, 605944347);
	template<> UNREALCLIENT_API UClass* StaticClass<URankUI>()
	{
		return URankUI::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URankUI(Z_Construct_UClass_URankUI, &URankUI::StaticClass, TEXT("/Script/UnrealClient"), TEXT("URankUI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URankUI);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
