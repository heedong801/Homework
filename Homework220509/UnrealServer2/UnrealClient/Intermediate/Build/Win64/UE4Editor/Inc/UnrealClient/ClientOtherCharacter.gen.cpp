// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ClientOtherCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientOtherCharacter() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientOtherCharacter_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientOtherCharacter();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ANonePlayableCharacter();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void AClientOtherCharacter::StaticRegisterNativesAClientOtherCharacter()
	{
	}
	UClass* Z_Construct_UClass_AClientOtherCharacter_NoRegister()
	{
		return AClientOtherCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AClientOtherCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AClientOtherCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANonePlayableCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AClientOtherCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// ANonePlayerbleCharacter \n// ?????? ACharacter?\xcf\xb4? ???\xc9\xb5??? ?? ?????\xd8\xbc?\n// ai\xc4\xb3???\xcd\xb5? \n" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Play/ClientOtherCharacter.h" },
		{ "ModuleRelativePath", "Play/ClientOtherCharacter.h" },
		{ "ToolTip", "ANonePlayerbleCharacter\n?????? ACharacter?\xcf\xb4? ???\xc9\xb5??? ?? ?????\xd8\xbc?\nai\xc4\xb3???\xcd\xb5?" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AClientOtherCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AClientOtherCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AClientOtherCharacter_Statics::ClassParams = {
		&AClientOtherCharacter::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AClientOtherCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AClientOtherCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AClientOtherCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AClientOtherCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AClientOtherCharacter, 2874618122);
	template<> UNREALCLIENT_API UClass* StaticClass<AClientOtherCharacter>()
	{
		return AClientOtherCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AClientOtherCharacter(Z_Construct_UClass_AClientOtherCharacter, &AClientOtherCharacter::StaticClass, TEXT("/Script/UnrealClient"), TEXT("AClientOtherCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AClientOtherCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
