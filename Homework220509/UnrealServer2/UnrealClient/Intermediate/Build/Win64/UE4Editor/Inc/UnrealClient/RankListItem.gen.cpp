// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/RankListItem.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRankListItem() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_URankListItem_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_URankListItem();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void URankListItem::StaticRegisterNativesURankListItem()
	{
	}
	UClass* Z_Construct_UClass_URankListItem_NoRegister()
	{
		return URankListItem::StaticClass();
	}
	struct Z_Construct_UClass_URankListItem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URankListItem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URankListItem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/RankListItem.h" },
		{ "ModuleRelativePath", "Play/RankListItem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URankListItem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URankListItem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URankListItem_Statics::ClassParams = {
		&URankListItem::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_URankListItem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URankListItem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URankListItem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URankListItem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URankListItem, 4235550322);
	template<> UNREALCLIENT_API UClass* StaticClass<URankListItem>()
	{
		return URankListItem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URankListItem(Z_Construct_UClass_URankListItem, &URankListItem::StaticClass, TEXT("/Script/UnrealClient"), TEXT("URankListItem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URankListItem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
