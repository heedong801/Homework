// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/PlayUIUserWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayUIUserWidget() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UPlayUIUserWidget_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UPlayUIUserWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(UPlayUIUserWidget::execRankWindowOpen)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RankWindowOpen();
		P_NATIVE_END;
	}
	void UPlayUIUserWidget::StaticRegisterNativesUPlayUIUserWidget()
	{
		UClass* Class = UPlayUIUserWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RankWindowOpen", &UPlayUIUserWidget::execRankWindowOpen },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPlayUIUserWidget_RankWindowOpen_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPlayUIUserWidget_RankWindowOpen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Create" },
		{ "ModuleRelativePath", "Play/PlayUIUserWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayUIUserWidget_RankWindowOpen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayUIUserWidget, nullptr, "RankWindowOpen", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPlayUIUserWidget_RankWindowOpen_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayUIUserWidget_RankWindowOpen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPlayUIUserWidget_RankWindowOpen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPlayUIUserWidget_RankWindowOpen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPlayUIUserWidget_NoRegister()
	{
		return UPlayUIUserWidget::StaticClass();
	}
	struct Z_Construct_UClass_UPlayUIUserWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayUIUserWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPlayUIUserWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlayUIUserWidget_RankWindowOpen, "RankWindowOpen" }, // 1373840332
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayUIUserWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/PlayUIUserWidget.h" },
		{ "ModuleRelativePath", "Play/PlayUIUserWidget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayUIUserWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayUIUserWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPlayUIUserWidget_Statics::ClassParams = {
		&UPlayUIUserWidget::StaticClass,
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
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPlayUIUserWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayUIUserWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPlayUIUserWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPlayUIUserWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPlayUIUserWidget, 810480443);
	template<> UNREALCLIENT_API UClass* StaticClass<UPlayUIUserWidget>()
	{
		return UPlayUIUserWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPlayUIUserWidget(Z_Construct_UClass_UPlayUIUserWidget, &UPlayUIUserWidget::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UPlayUIUserWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayUIUserWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
