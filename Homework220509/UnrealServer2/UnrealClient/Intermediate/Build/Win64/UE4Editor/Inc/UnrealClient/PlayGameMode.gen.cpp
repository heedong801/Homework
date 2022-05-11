// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/PlayGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayGameMode() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_APlayGameMode_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_APlayGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientMonster_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientCharacter_NoRegister();
// End Cross Module References
	void APlayGameMode::StaticRegisterNativesAPlayGameMode()
	{
	}
	UClass* Z_Construct_UClass_APlayGameMode_NoRegister()
	{
		return APlayGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APlayGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ArrMonsterClass__Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ArrMonsterClass__MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ArrMonsterClass_;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherPlayerClass__MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_OtherPlayerClass_;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Play/PlayGameMode.h" },
		{ "ModuleRelativePath", "Play/PlayGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_APlayGameMode_Statics::NewProp_ArrMonsterClass__Inner = { "ArrMonsterClass_", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AClientMonster_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayGameMode_Statics::NewProp_ArrMonsterClass__MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "ClientData" },
		{ "ModuleRelativePath", "Play/PlayGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APlayGameMode_Statics::NewProp_ArrMonsterClass_ = { "ArrMonsterClass_", nullptr, (EPropertyFlags)0x0044000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayGameMode, ArrMonsterClass_), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_APlayGameMode_Statics::NewProp_ArrMonsterClass__MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayGameMode_Statics::NewProp_ArrMonsterClass__MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass__MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "ClientData" },
		{ "ModuleRelativePath", "Play/PlayGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass_ = { "OtherPlayerClass_", nullptr, (EPropertyFlags)0x0044000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayGameMode, OtherPlayerClass_), Z_Construct_UClass_AClientCharacter_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass__MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass__MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlayGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayGameMode_Statics::NewProp_ArrMonsterClass__Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayGameMode_Statics::NewProp_ArrMonsterClass_,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass_,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlayGameMode_Statics::ClassParams = {
		&APlayGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APlayGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APlayGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_APlayGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlayGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlayGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlayGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlayGameMode, 3710793753);
	template<> UNREALCLIENT_API UClass* StaticClass<APlayGameMode>()
	{
		return APlayGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayGameMode(Z_Construct_UClass_APlayGameMode, &APlayGameMode::StaticClass, TEXT("/Script/UnrealClient"), TEXT("APlayGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
