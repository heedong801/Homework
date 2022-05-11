// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ClientAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientAIController() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientAIController_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void AClientAIController::StaticRegisterNativesAClientAIController()
	{
	}
	UClass* Z_Construct_UClass_AClientAIController_NoRegister()
	{
		return AClientAIController::StaticClass();
	}
	struct Z_Construct_UClass_AClientAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AClientAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AClientAIController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Play/ClientAIController.h" },
		{ "ModuleRelativePath", "Play/ClientAIController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AClientAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AClientAIController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AClientAIController_Statics::ClassParams = {
		&AClientAIController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AClientAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AClientAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AClientAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AClientAIController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AClientAIController, 2468495592);
	template<> UNREALCLIENT_API UClass* StaticClass<AClientAIController>()
	{
		return AClientAIController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AClientAIController(Z_Construct_UClass_AClientAIController, &AClientAIController::StaticClass, TEXT("/Script/UnrealClient"), TEXT("AClientAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AClientAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
