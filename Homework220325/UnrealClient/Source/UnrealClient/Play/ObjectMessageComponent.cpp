// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectMessageComponent.h"

// Sets default values for this component's properties
UObjectMessageComponent::UObjectMessageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UObjectMessageComponent::BeginPlay()
{
	Super::BeginPlay();
}

//
//// Called every frame
//void UObjectMessageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}
//

bool UObjectMessageComponent::IsEmpty() 
{
	return MessageQueue_.IsEmpty();
}

void UObjectMessageComponent::Enqueue(std::shared_ptr<GameServerMessage> _Message) 
{
	MessageQueue_.Enqueue(_Message);
}

std::shared_ptr<GameServerMessage> UObjectMessageComponent::Dequeue()
{
	std::shared_ptr<GameServerMessage> MessagePtr_;

	MessageQueue_.Dequeue(MessagePtr_);

	return MessagePtr_;
}