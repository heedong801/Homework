// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ClientPlayCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientPlayCharacter() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientPlayCharacter_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientPlayCharacter();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientCharacter();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void AClientPlayCharacter::StaticRegisterNativesAClientPlayCharacter()
	{
	}
	UClass* Z_Construct_UClass_AClientPlayCharacter_NoRegister()
	{
		return AClientPlayCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AClientPlayCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AClientPlayCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AClientCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AClientPlayCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Play/ClientPlayCharacter.h" },
		{ "ModuleRelativePath", "Play/ClientPlayCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AClientPlayCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AClientPlayCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AClientPlayCharacter_Statics::ClassParams = {
		&AClientPlayCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AClientPlayCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AClientPlayCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AClientPlayCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AClientPlayCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AClientPlayCharacter, 1330727658);
	template<> UNREALCLIENT_API UClass* StaticClass<AClientPlayCharacter>()
	{
		return AClientPlayCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AClientPlayCharacter(Z_Construct_UClass_AClientPlayCharacter, &AClientPlayCharacter::StaticClass, TEXT("/Script/UnrealClient"), TEXT("AClientPlayCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AClientPlayCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
