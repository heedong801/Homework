// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Login/LoginGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoginGameMode() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_ALoginGameMode_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ALoginGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void ALoginGameMode::StaticRegisterNativesALoginGameMode()
	{
	}
	UClass* Z_Construct_UClass_ALoginGameMode_NoRegister()
	{
		return ALoginGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ALoginGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALoginGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALoginGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Login/LoginGameMode.h" },
		{ "ModuleRelativePath", "Login/LoginGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALoginGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALoginGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALoginGameMode_Statics::ClassParams = {
		&ALoginGameMode::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ALoginGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALoginGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALoginGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALoginGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALoginGameMode, 3944265577);
	template<> UNREALCLIENT_API UClass* StaticClass<ALoginGameMode>()
	{
		return ALoginGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALoginGameMode(Z_Construct_UClass_ALoginGameMode, &ALoginGameMode::StaticClass, TEXT("/Script/UnrealClient"), TEXT("ALoginGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALoginGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
