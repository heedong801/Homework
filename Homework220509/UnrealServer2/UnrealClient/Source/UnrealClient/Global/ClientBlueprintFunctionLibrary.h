// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <vector>
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ClientBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UClientBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static bool FStringToUTF8(const FString& _FString, std::string& _UTF8);

	static bool UTF8ToFString(const std::string& _UTF8, FString& _FString);

	static bool StringToData(const std::string& _UTF8, std::vector<uint8> _Data);

	static bool FStringToUTF8Data(const FString& _FString, std::vector<uint8> _Data);
};
