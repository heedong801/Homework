// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Global/FreeCameraPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFreeCameraPawn() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_AFreeCameraPawn_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AFreeCameraPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	ENGINE_API UClass* Z_Construct_UClass_UPawnMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFreeCameraPawn::execMove_Test)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Move_Test();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFreeCameraPawn::execMoveUp_World)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Val);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveUp_World(Z_Param_Val);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFreeCameraPawn::execMoveRight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Val);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveRight(Z_Param_Val);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFreeCameraPawn::execMoveForward)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Val);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveForward(Z_Param_Val);
		P_NATIVE_END;
	}
	void AFreeCameraPawn::StaticRegisterNativesAFreeCameraPawn()
	{
		UClass* Class = AFreeCameraPawn::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Move_Test", &AFreeCameraPawn::execMove_Test },
			{ "MoveForward", &AFreeCameraPawn::execMoveForward },
			{ "MoveRight", &AFreeCameraPawn::execMoveRight },
			{ "MoveUp_World", &AFreeCameraPawn::execMoveUp_World },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFreeCameraPawn_Move_Test_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFreeCameraPawn_Move_Test_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFreeCameraPawn_Move_Test_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFreeCameraPawn, nullptr, "Move_Test", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFreeCameraPawn_Move_Test_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFreeCameraPawn_Move_Test_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFreeCameraPawn_Move_Test()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFreeCameraPawn_Move_Test_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics
	{
		struct FreeCameraPawn_eventMoveForward_Parms
		{
			float Val;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Val;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::NewProp_Val = { "Val", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FreeCameraPawn_eventMoveForward_Parms, Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::NewProp_Val,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFreeCameraPawn, nullptr, "MoveForward", nullptr, nullptr, sizeof(FreeCameraPawn_eventMoveForward_Parms), Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFreeCameraPawn_MoveForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFreeCameraPawn_MoveForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics
	{
		struct FreeCameraPawn_eventMoveRight_Parms
		{
			float Val;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Val;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::NewProp_Val = { "Val", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FreeCameraPawn_eventMoveRight_Parms, Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::NewProp_Val,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFreeCameraPawn, nullptr, "MoveRight", nullptr, nullptr, sizeof(FreeCameraPawn_eventMoveRight_Parms), Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFreeCameraPawn_MoveRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFreeCameraPawn_MoveRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics
	{
		struct FreeCameraPawn_eventMoveUp_World_Parms
		{
			float Val;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Val;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::NewProp_Val = { "Val", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FreeCameraPawn_eventMoveUp_World_Parms, Val), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::NewProp_Val,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFreeCameraPawn, nullptr, "MoveUp_World", nullptr, nullptr, sizeof(FreeCameraPawn_eventMoveUp_World_Parms), Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFreeCameraPawn_NoRegister()
	{
		return AFreeCameraPawn::StaticClass();
	}
	struct Z_Construct_UClass_AFreeCameraPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAddDefaultMovementBindings_MetaData[];
#endif
		static void NewProp_bAddDefaultMovementBindings_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAddDefaultMovementBindings;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CollisionComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFreeCameraPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFreeCameraPawn_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFreeCameraPawn_Move_Test, "Move_Test" }, // 1823520687
		{ &Z_Construct_UFunction_AFreeCameraPawn_MoveForward, "MoveForward" }, // 31161245
		{ &Z_Construct_UFunction_AFreeCameraPawn_MoveRight, "MoveRight" }, // 1592717440
		{ &Z_Construct_UFunction_AFreeCameraPawn_MoveUp_World, "MoveUp_World" }, // 490339224
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFreeCameraPawn_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// UClass?? ?\xd6\xbe??? ?\xf0\xb8\xae\xbe? ?????? ???????? c++ ?\xd7\xb8\xf1\xbf\xa1\xbc? \xc7\xa5???\xd2\xbc? ?\xd6\xb4?\n// \xc5\xac?????? ?\xc8\xb4?.\n" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Global/FreeCameraPawn.h" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
		{ "ToolTip", "UClass?? ?\xd6\xbe??? ?\xf0\xb8\xae\xbe? ?????? ???????? c++ ?\xd7\xb8\xf1\xbf\xa1\xbc? \xc7\xa5???\xd2\xbc? ?\xd6\xb4?\n\xc5\xac?????? ?\xc8\xb4?." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_bAddDefaultMovementBindings_MetaData[] = {
		{ "Category", "Pawn" },
		{ "Comment", "/** If true, adds default input bindings for movement and camera look. */" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
		{ "ToolTip", "If true, adds default input bindings for movement and camera look." },
	};
#endif
	void Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_bAddDefaultMovementBindings_SetBit(void* Obj)
	{
		((AFreeCameraPawn*)Obj)->bAddDefaultMovementBindings = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_bAddDefaultMovementBindings = { "bAddDefaultMovementBindings", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(AFreeCameraPawn), &Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_bAddDefaultMovementBindings_SetBit, METADATA_PARAMS(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_bAddDefaultMovementBindings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_bAddDefaultMovementBindings_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFreeCameraPawn, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseTurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFreeCameraPawn, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseLookUpRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFreeCameraPawn, MovementComponent), Z_Construct_UClass_UPawnMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MovementComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_CollisionComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_CollisionComponent = { "CollisionComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFreeCameraPawn, CollisionComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_CollisionComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_CollisionComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Global/FreeCameraPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFreeCameraPawn, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MeshComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFreeCameraPawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_bAddDefaultMovementBindings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_BaseLookUpRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MovementComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_CollisionComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFreeCameraPawn_Statics::NewProp_MeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFreeCameraPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFreeCameraPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFreeCameraPawn_Statics::ClassParams = {
		&AFreeCameraPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFreeCameraPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFreeCameraPawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFreeCameraPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFreeCameraPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFreeCameraPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFreeCameraPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFreeCameraPawn, 138640195);
	template<> UNREALCLIENT_API UClass* StaticClass<AFreeCameraPawn>()
	{
		return AFreeCameraPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFreeCameraPawn(Z_Construct_UClass_AFreeCameraPawn, &AFreeCameraPawn::StaticClass, TEXT("/Script/UnrealClient"), TEXT("AFreeCameraPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFreeCameraPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
