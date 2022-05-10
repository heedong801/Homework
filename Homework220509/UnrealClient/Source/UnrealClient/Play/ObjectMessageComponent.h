// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <string>
#include <vector>
#include <Memory>
#include <functional>
#include "../Message/Messages.h"
#include "ObjectMessageComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCLIENT_API UObjectMessageComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectMessageComponent();


	bool IsEmpty();

	void Enqueue(std::shared_ptr<GameServerMessage> _Message);
	std::shared_ptr<GameServerMessage> Dequeue();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TQueue<std::shared_ptr<GameServerMessage>> MessageQueue_;
//public:	
//	// Called every frame
//	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
