// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/NonePlayableCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNonePlayableCharacter() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_ANonePlayableCharacter_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ANonePlayableCharacter();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientCharacter();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void ANonePlayableCharacter::StaticRegisterNativesANonePlayableCharacter()
	{
	}
	UClass* Z_Construct_UClass_ANonePlayableCharacter_NoRegister()
	{
		return ANonePlayableCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ANonePlayableCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANonePlayableCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AClientCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANonePlayableCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Play/NonePlayableCharacter.h" },
		{ "ModuleRelativePath", "Play/NonePlayableCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANonePlayableCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANonePlayableCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANonePlayableCharacter_Statics::ClassParams = {
		&ANonePlayableCharacter::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ANonePlayableCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANonePlayableCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANonePlayableCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANonePlayableCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANonePlayableCharacter, 585045317);
	template<> UNREALCLIENT_API UClass* StaticClass<ANonePlayableCharacter>()
	{
		return ANonePlayableCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANonePlayableCharacter(Z_Construct_UClass_ANonePlayableCharacter, &ANonePlayableCharacter::StaticClass, TEXT("/Script/UnrealClient"), TEXT("ANonePlayableCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANonePlayableCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
