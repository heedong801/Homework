// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Login/LoginUI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoginUI() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_ULoginUI_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ULoginUI();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(ULoginUI::execSetClientMode)
	{
		P_GET_UBOOL(Z_Param__Mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClientMode(Z_Param__Mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULoginUI::execJoinUser)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinUser();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULoginUI::execServerLogin)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ServerLogin();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULoginUI::execServerConnect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ServerConnect();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULoginUI::execResetInfo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetInfo();
		P_NATIVE_END;
	}
	void ULoginUI::StaticRegisterNativesULoginUI()
	{
		UClass* Class = ULoginUI::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "JoinUser", &ULoginUI::execJoinUser },
			{ "ResetInfo", &ULoginUI::execResetInfo },
			{ "ServerConnect", &ULoginUI::execServerConnect },
			{ "ServerLogin", &ULoginUI::execServerLogin },
			{ "SetClientMode", &ULoginUI::execSetClientMode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULoginUI_JoinUser_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_JoinUser_Statics::Function_MetaDataParams[] = {
		{ "Category", "Join|Join" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_JoinUser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "JoinUser", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_JoinUser_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_JoinUser_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_JoinUser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_JoinUser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULoginUI_ResetInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_ResetInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Login|Connect" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_ResetInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "ResetInfo", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_ResetInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_ResetInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_ResetInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_ResetInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULoginUI_ServerConnect_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::Function_MetaDataParams[] = {
		{ "Category", "Login|Connect" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "ServerConnect", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_ServerConnect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULoginUI_ServerLogin_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::Function_MetaDataParams[] = {
		{ "Category", "Login|Login" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "ServerLogin", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_ServerLogin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULoginUI_SetClientMode_Statics
	{
		struct LoginUI_eventSetClientMode_Parms
		{
			bool _Mode;
		};
		static void NewProp__Mode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp__Mode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::NewProp__Mode_SetBit(void* Obj)
	{
		((LoginUI_eventSetClientMode_Parms*)Obj)->_Mode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::NewProp__Mode = { "_Mode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(LoginUI_eventSetClientMode_Parms), &Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::NewProp__Mode_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::NewProp__Mode,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameMode" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "SetClientMode", nullptr, nullptr, sizeof(LoginUI_eventSetClientMode_Parms), Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_SetClientMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_SetClientMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULoginUI_NoRegister()
	{
		return ULoginUI::StaticClass();
	}
	struct Z_Construct_UClass_ULoginUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IPString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_IPString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PORTString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PORTString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConnectStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ConnectStatus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IDString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_IDString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PWString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PWString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LoginStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_LoginStatus;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULoginUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULoginUI_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULoginUI_JoinUser, "JoinUser" }, // 2476250810
		{ &Z_Construct_UFunction_ULoginUI_ResetInfo, "ResetInfo" }, // 2083623402
		{ &Z_Construct_UFunction_ULoginUI_ServerConnect, "ServerConnect" }, // 2510593805
		{ &Z_Construct_UFunction_ULoginUI_ServerLogin, "ServerLogin" }, // 1919845901
		{ &Z_Construct_UFunction_ULoginUI_SetClientMode, "SetClientMode" }, // 3508930725
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Login/LoginUI.h" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_IPString_MetaData[] = {
		{ "Category", "ConnectInfo" },
		{ "Comment", "// FName\n// FText\n// FString\n// ?\xf0\xb8\xae\xbe\xf3\xbf\xa1\xbc? \n// FString ?\xda\xb5\xe5\xb3\xaa ?\xc7\xbd\xc3\xb0? ???\xda\xbf??? \xc3\xb3???\xd2\xb6? ?????\xcf\xb0? ?\xc8\xb4?.\n" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
		{ "ToolTip", "FName\nFText\nFString\n?\xf0\xb8\xae\xbe\xf3\xbf\xa1\xbc?\nFString ?\xda\xb5\xe5\xb3\xaa ?\xc7\xbd\xc3\xb0? ???\xda\xbf??? \xc3\xb3???\xd2\xb6? ?????\xcf\xb0? ?\xc8\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_IPString = { "IPString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, IPString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_IPString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_IPString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_PORTString_MetaData[] = {
		{ "Category", "ConnectInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_PORTString = { "PORTString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, PORTString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_PORTString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_PORTString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_ConnectStatus_MetaData[] = {
		{ "Category", "ConnectInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_ConnectStatus = { "ConnectStatus", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, ConnectStatus), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_ConnectStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_ConnectStatus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_IDString_MetaData[] = {
		{ "Category", "LoginInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_IDString = { "IDString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, IDString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_IDString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_IDString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_PWString_MetaData[] = {
		{ "Category", "LoginInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_PWString = { "PWString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, PWString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_PWString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_PWString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_LoginStatus_MetaData[] = {
		{ "Category", "LoginInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_LoginStatus = { "LoginStatus", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, LoginStatus), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_LoginStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_LoginStatus_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULoginUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_IPString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_PORTString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_ConnectStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_IDString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_PWString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_LoginStatus,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULoginUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULoginUI>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULoginUI_Statics::ClassParams = {
		&ULoginUI::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ULoginUI_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULoginUI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULoginUI_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULoginUI, 2560045808);
	template<> UNREALCLIENT_API UClass* StaticClass<ULoginUI>()
	{
		return ULoginUI::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULoginUI(Z_Construct_UClass_ULoginUI, &ULoginUI::StaticClass, TEXT("/Script/UnrealClient"), TEXT("ULoginUI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULoginUI);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
