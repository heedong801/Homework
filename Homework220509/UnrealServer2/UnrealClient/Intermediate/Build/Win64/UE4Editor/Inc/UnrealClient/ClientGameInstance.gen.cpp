// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Global/ClientGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientGameInstance() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UClientGameInstance_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UClientGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(UClientGameInstance::execGetClientIndex)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetClientIndex();
		P_NATIVE_END;
	}
	void UClientGameInstance::StaticRegisterNativesUClientGameInstance()
	{
		UClass* Class = UClientGameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetClientIndex", &UClientGameInstance::execGetClientIndex },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics
	{
		struct ClientGameInstance_eventGetClientIndex_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ClientGameInstance_eventGetClientIndex_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Instance" },
		{ "ModuleRelativePath", "Global/ClientGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UClientGameInstance, nullptr, "GetClientIndex", nullptr, nullptr, sizeof(ClientGameInstance_eventGetClientIndex_Parms), Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UClientGameInstance_GetClientIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UClientGameInstance_GetClientIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UClientGameInstance_NoRegister()
	{
		return UClientGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UClientGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UClientGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UClientGameInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UClientGameInstance_GetClientIndex, "GetClientIndex" }, // 3481822846
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UClientGameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Global/ClientGameInstance.h" },
		{ "ModuleRelativePath", "Global/ClientGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UClientGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClientGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UClientGameInstance_Statics::ClassParams = {
		&UClientGameInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UClientGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UClientGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UClientGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UClientGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UClientGameInstance, 198285580);
	template<> UNREALCLIENT_API UClass* StaticClass<UClientGameInstance>()
	{
		return UClientGameInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UClientGameInstance(Z_Construct_UClass_UClientGameInstance, &UClientGameInstance::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UClientGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UClientGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
