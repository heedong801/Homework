// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Message/MessageComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMessageComponent() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UMessageComponent_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UMessageComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UDispatcher_NoRegister();
// End Cross Module References
	void UMessageComponent::StaticRegisterNativesUMessageComponent()
	{
	}
	UClass* Z_Construct_UClass_UMessageComponent_NoRegister()
	{
		return UMessageComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMessageComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Dis_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Dis;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMessageComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMessageComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Message/MessageComponent.h" },
		{ "ModuleRelativePath", "Message/MessageComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMessageComponent_Statics::NewProp_Dis_MetaData[] = {
		{ "ModuleRelativePath", "Message/MessageComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMessageComponent_Statics::NewProp_Dis = { "Dis", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMessageComponent, Dis), Z_Construct_UClass_UDispatcher_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMessageComponent_Statics::NewProp_Dis_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMessageComponent_Statics::NewProp_Dis_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMessageComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMessageComponent_Statics::NewProp_Dis,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMessageComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMessageComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMessageComponent_Statics::ClassParams = {
		&UMessageComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMessageComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMessageComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMessageComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMessageComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMessageComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMessageComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMessageComponent, 145420413);
	template<> UNREALCLIENT_API UClass* StaticClass<UMessageComponent>()
	{
		return UMessageComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMessageComponent(Z_Construct_UClass_UMessageComponent, &UMessageComponent::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UMessageComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMessageComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
