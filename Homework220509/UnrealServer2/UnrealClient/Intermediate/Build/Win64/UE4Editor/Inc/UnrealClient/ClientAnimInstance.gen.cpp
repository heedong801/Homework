// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ClientAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientAnimInstance() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UClientAnimInstance_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UClientAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(UClientAnimInstance::execAnimNotify_End)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimNotify_End();
		P_NATIVE_END;
	}
	void UClientAnimInstance::StaticRegisterNativesUClientAnimInstance()
	{
		UClass* Class = UClientAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AnimNotify_End", &UClientAnimInstance::execAnimNotify_End },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UClientAnimInstance_AnimNotify_End_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UClientAnimInstance_AnimNotify_End_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Play/ClientAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UClientAnimInstance_AnimNotify_End_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UClientAnimInstance, nullptr, "AnimNotify_End", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UClientAnimInstance_AnimNotify_End_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UClientAnimInstance_AnimNotify_End_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UClientAnimInstance_AnimNotify_End()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UClientAnimInstance_AnimNotify_End_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UClientAnimInstance_NoRegister()
	{
		return UClientAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UClientAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UClientAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UClientAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UClientAnimInstance_AnimNotify_End, "AnimNotify_End" }, // 83193164
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UClientAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "Play/ClientAnimInstance.h" },
		{ "ModuleRelativePath", "Play/ClientAnimInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UClientAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClientAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UClientAnimInstance_Statics::ClassParams = {
		&UClientAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UClientAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UClientAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UClientAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UClientAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UClientAnimInstance, 1770136928);
	template<> UNREALCLIENT_API UClass* StaticClass<UClientAnimInstance>()
	{
		return UClientAnimInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UClientAnimInstance(Z_Construct_UClass_UClientAnimInstance, &UClientAnimInstance::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UClientAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UClientAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
