// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChatMessageObject.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UChatMessageObject : public UObject
{
	GENERATED_BODY()

public:
	FString ID_;
	FString Message_;
};
