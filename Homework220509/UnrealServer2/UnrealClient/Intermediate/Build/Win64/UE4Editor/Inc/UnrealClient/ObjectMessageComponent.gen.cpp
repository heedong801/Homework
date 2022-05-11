// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ObjectMessageComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectMessageComponent() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UObjectMessageComponent_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UObjectMessageComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UObjectMessageComponent::StaticRegisterNativesUObjectMessageComponent()
	{
	}
	UClass* Z_Construct_UClass_UObjectMessageComponent_NoRegister()
	{
		return UObjectMessageComponent::StaticClass();
	}
	struct Z_Construct_UClass_UObjectMessageComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectMessageComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectMessageComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Play/ObjectMessageComponent.h" },
		{ "ModuleRelativePath", "Play/ObjectMessageComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectMessageComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectMessageComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectMessageComponent_Statics::ClassParams = {
		&UObjectMessageComponent::StaticClass,
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
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectMessageComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectMessageComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectMessageComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectMessageComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectMessageComponent, 2589589132);
	template<> UNREALCLIENT_API UClass* StaticClass<UObjectMessageComponent>()
	{
		return UObjectMessageComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectMessageComponent(Z_Construct_UClass_UObjectMessageComponent, &UObjectMessageComponent::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UObjectMessageComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectMessageComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
