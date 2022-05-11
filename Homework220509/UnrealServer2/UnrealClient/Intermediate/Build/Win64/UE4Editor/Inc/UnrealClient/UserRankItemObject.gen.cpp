// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/UserRankItemObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUserRankItemObject() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UUserRankItemObject_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UUserRankItemObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UUserRankItemObject::StaticRegisterNativesUUserRankItemObject()
	{
	}
	UClass* Z_Construct_UClass_UUserRankItemObject_NoRegister()
	{
		return UUserRankItemObject::StaticClass();
	}
	struct Z_Construct_UClass_UUserRankItemObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUserRankItemObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUserRankItemObject_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/UserRankItemObject.h" },
		{ "ModuleRelativePath", "Play/UserRankItemObject.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUserRankItemObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUserRankItemObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUserRankItemObject_Statics::ClassParams = {
		&UUserRankItemObject::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUserRankItemObject_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUserRankItemObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUserRankItemObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUserRankItemObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUserRankItemObject, 2886506142);
	template<> UNREALCLIENT_API UClass* StaticClass<UUserRankItemObject>()
	{
		return UUserRankItemObject::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUserRankItemObject(Z_Construct_UClass_UUserRankItemObject, &UUserRankItemObject::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UUserRankItemObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUserRankItemObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
