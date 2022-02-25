// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientMonster.h"
#include "ObjectMessageComponent.h"


void AClientMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	while (false == GetMessage()->IsEmpty())
	{
		std::shared_ptr<GameServerMessage> Message = GetMessage()->Dequeue();

		if (MessageId::MonsterUpdate ==  Message->GetId())
		{
			std::shared_ptr<MonsterUpdateMessage> UpdateMessage = std::static_pointer_cast<MonsterUpdateMessage>(Message);

			if (nullptr == UpdateMessage)
			{
				continue;
			}

			SetActorLocation(UpdateMessage->Pos);
		}
	}
}