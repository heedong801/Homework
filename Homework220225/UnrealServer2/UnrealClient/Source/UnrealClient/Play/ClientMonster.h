// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClientCharacter.h"
#include "ClientMonster.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API AClientMonster : public AClientCharacter
{
	GENERATED_BODY()
	

public:
	bool ClientMode_;

protected:
	void Tick(float DeltaTime);

private:
	// TQueue<std::shared_ptr<GameServerMessage>> ObjectMessageQueue_;
};
