// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserRankItemObject.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UUserRankItemObject : public UObject
{
	GENERATED_BODY()
	
public:
	FString ConvertNickName;
	int Score;


};
