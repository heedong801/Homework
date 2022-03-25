// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageComponent.h"
#include <Memory>
#include <functional>
#include "Handler/HandlerHeader.h"
#include "../Global/ClientGameInstance.h"


// Sets default values for this component's properties
UMessageComponent::UMessageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void UMessageComponent::BeginPlay()
{
	Super::BeginPlay();

	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetOwner()->GetGameInstance());

	Dis = NewObject<UDispatcher>();

	CheckHandler(*Dis,Inst, GetWorld());

	// ...
	
}


// Called every frame
void UMessageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);



	// 여기서 틱을 돈다.

	// [리시브 쓰레드 메세지가 올때마다 리턴되서 뭔가를 한다.]
	// 여기서 갑자기 액터의 위치를 바꿔.
	// 받아서 메세지를 저장만 해 놓습니다.
	// 쌓아 놓기만 하는 겁니다.


	// 프레임이 시작....
	// 메세지를 다 빼냅니다.
	// 한번은 답이 없습니다.
	// 언리얼의 queue를 이용해야 합니다.
	// 그안에서 
	// 
	// 
	// 
	// [언리얼 로직 쓰레드 액터들이 움직이고 뭐 그러고 있다.]
	// 움직인다 랜더링을 해라.
	// 여기서 뭔가를 하고 있었어.


	// 리시브 쓰레드에서 액터를 움직이려고 하거나

	if (false == GetOwner()->IsValidLowLevel())
	{
		return;
	}


	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetOwner()->GetGameInstance());

	while (false == Inst->IsEmptyMessage())
	{
		std::shared_ptr<GameServerMessage> Message = Inst->PopMessage();

		if (nullptr == Message)
		{
			continue;
		}

		MessageHandler MsgHandler;

		MessageId Id = Message->GetId();

		Dis->GetHandler(Id, MsgHandler);

		if (nullptr == MsgHandler)
		{
			return;
		}

		// 그방식으로 가도 되고요.
		// 각오브젝트들은 각 오브젝트별로 어차피 틱을 가지고 있잖아요?
		MsgHandler(Message);
		// Inst->get
	}


	// ...
}

