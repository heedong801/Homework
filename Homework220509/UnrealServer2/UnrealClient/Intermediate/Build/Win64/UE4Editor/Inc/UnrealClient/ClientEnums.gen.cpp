// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/ClientEnums.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientEnums() {}
// Cross Module References
	UNREALCLIENT_API UEnum* Z_Construct_UEnum_UnrealClient_ClientAnimationType();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	static UEnum* ClientAnimationType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_UnrealClient_ClientAnimationType, Z_Construct_UPackage__Script_UnrealClient(), TEXT("ClientAnimationType"));
		}
		return Singleton;
	}
	template<> UNREALCLIENT_API UEnum* StaticEnum<ClientAnimationType>()
	{
		return ClientAnimationType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ClientAnimationType(ClientAnimationType_StaticEnum, TEXT("/Script/UnrealClient"), TEXT("ClientAnimationType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_UnrealClient_ClientAnimationType_Hash() { return 91086296U; }
	UEnum* Z_Construct_UEnum_UnrealClient_ClientAnimationType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_UnrealClient();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ClientAnimationType"), 0, Get_Z_Construct_UEnum_UnrealClient_ClientAnimationType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ClientAnimationType::NONE", (int64)ClientAnimationType::NONE },
				{ "ClientAnimationType::Idle", (int64)ClientAnimationType::Idle },
				{ "ClientAnimationType::Move", (int64)ClientAnimationType::Move },
				{ "ClientAnimationType::Attack", (int64)ClientAnimationType::Attack },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Attack.DisplayName", "\xea\xb3\xb5\xea\xb2\xa9 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98" },
				{ "Attack.Name", "ClientAnimationType::Attack" },
				{ "BlueprintType", "true" },
				{ "Idle.DisplayName", "\xeb\x8c\x80\xea\xb8\xb0 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98" },
				{ "Idle.Name", "ClientAnimationType::Idle" },
				{ "ModuleRelativePath", "Play/ClientEnums.h" },
				{ "Move.DisplayName", "\xec\x9d\xb4\xeb\x8f\x99 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98" },
				{ "Move.Name", "ClientAnimationType::Move" },
				{ "NONE.DisplayName", "\xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xec\xa7\x80\xec\xa0\x95 \xec\x95\x88\xeb\x90\xa8" },
				{ "NONE.Name", "ClientAnimationType::NONE" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_UnrealClient,
				nullptr,
				"ClientAnimationType",
				"ClientAnimationType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
