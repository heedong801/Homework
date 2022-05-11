// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LoginGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API ALoginGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ALoginGameMode();

	void Tick(float _Delta) override;
};
