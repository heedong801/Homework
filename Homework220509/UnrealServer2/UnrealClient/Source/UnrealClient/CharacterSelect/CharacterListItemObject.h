// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Message/ContentsStructure.h"
#include "CharacterListItemObject.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UCharacterListItemObject : public UObject
{
	GENERATED_BODY()
	
public:
	FCharacterInfo Info;
	FString ConvertNickName;
};
