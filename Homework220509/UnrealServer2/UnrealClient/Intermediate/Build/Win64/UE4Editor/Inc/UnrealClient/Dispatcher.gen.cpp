// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Message/Dispatcher.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDispatcher() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UDispatcher_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UDispatcher();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UDispatcher::StaticRegisterNativesUDispatcher()
	{
	}
	UClass* Z_Construct_UClass_UDispatcher_NoRegister()
	{
		return UDispatcher::StaticClass();
	}
	struct Z_Construct_UClass_UDispatcher_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDispatcher_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDispatcher_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "// \xc3\xb7?? : \n" },
		{ "IncludePath", "Message/Dispatcher.h" },
		{ "ModuleRelativePath", "Message/Dispatcher.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDispatcher_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDispatcher>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDispatcher_Statics::ClassParams = {
		&UDispatcher::StaticClass,
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
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDispatcher_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDispatcher_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDispatcher()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDispatcher_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDispatcher, 2804114290);
	template<> UNREALCLIENT_API UClass* StaticClass<UDispatcher>()
	{
		return UDispatcher::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDispatcher(Z_Construct_UClass_UDispatcher, &UDispatcher::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UDispatcher"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDispatcher);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
