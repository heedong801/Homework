// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/CharacterSelect/CharacterListItem.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterListItem() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCharacterListItem_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCharacterListItem();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(UCharacterListItem::execCharacterSelect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CharacterSelect();
		P_NATIVE_END;
	}
	void UCharacterListItem::StaticRegisterNativesUCharacterListItem()
	{
		UClass* Class = UCharacterListItem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CharacterSelect", &UCharacterListItem::execCharacterSelect },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCharacterListItem_CharacterSelect_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCharacterListItem_CharacterSelect_Statics::Function_MetaDataParams[] = {
		{ "Category", "Login|Connect" },
		{ "ModuleRelativePath", "CharacterSelect/CharacterListItem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterListItem_CharacterSelect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCharacterListItem, nullptr, "CharacterSelect", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCharacterListItem_CharacterSelect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterListItem_CharacterSelect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCharacterListItem_CharacterSelect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCharacterListItem_CharacterSelect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCharacterListItem_NoRegister()
	{
		return UCharacterListItem::StaticClass();
	}
	struct Z_Construct_UClass_UCharacterListItem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NickName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NickName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCharacterListItem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCharacterListItem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCharacterListItem_CharacterSelect, "CharacterSelect" }, // 3514269031
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterListItem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CharacterSelect/CharacterListItem.h" },
		{ "ModuleRelativePath", "CharacterSelect/CharacterListItem.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterListItem_Statics::NewProp_NickName_MetaData[] = {
		{ "Category", "CharcterInfo" },
		{ "ModuleRelativePath", "CharacterSelect/CharacterListItem.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCharacterListItem_Statics::NewProp_NickName = { "NickName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCharacterListItem, NickName), METADATA_PARAMS(Z_Construct_UClass_UCharacterListItem_Statics::NewProp_NickName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterListItem_Statics::NewProp_NickName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharacterListItem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterListItem_Statics::NewProp_NickName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCharacterListItem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterListItem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCharacterListItem_Statics::ClassParams = {
		&UCharacterListItem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCharacterListItem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterListItem_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCharacterListItem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterListItem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCharacterListItem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCharacterListItem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCharacterListItem, 2224010408);
	template<> UNREALCLIENT_API UClass* StaticClass<UCharacterListItem>()
	{
		return UCharacterListItem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCharacterListItem(Z_Construct_UClass_UCharacterListItem, &UCharacterListItem::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UCharacterListItem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCharacterListItem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
