// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ClientMonster.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientMonster() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientMonster_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientMonster();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ANonePlayableCharacter();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void AClientMonster::StaticRegisterNativesAClientMonster()
	{
	}
	UClass* Z_Construct_UClass_AClientMonster_NoRegister()
	{
		return AClientMonster::StaticClass();
	}
	struct Z_Construct_UClass_AClientMonster_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AClientMonster_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANonePlayableCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AClientMonster_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Play/ClientMonster.h" },
		{ "ModuleRelativePath", "Play/ClientMonster.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AClientMonster_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AClientMonster>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AClientMonster_Statics::ClassParams = {
		&AClientMonster::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AClientMonster_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AClientMonster_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AClientMonster()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AClientMonster_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AClientMonster, 1637071181);
	template<> UNREALCLIENT_API UClass* StaticClass<AClientMonster>()
	{
		return AClientMonster::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AClientMonster(Z_Construct_UClass_AClientMonster, &AClientMonster::StaticClass, TEXT("/Script/UnrealClient"), TEXT("AClientMonster"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AClientMonster);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
