// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayGameMode.h"
#include "../UnrealClient.h"
#include "../Play/ObjectMessageComponent.h"


TSubclassOf<AClientMonster> APlayGameMode::GetMonsterClass(int _MonsterType)
{
	if (0 > _MonsterType)
	{
		return nullptr;
	}

	if (_MonsterType >= ArrMonsterClass_.Num())
	{
		return nullptr;
	}

	return ArrMonsterClass_[_MonsterType];
}

bool APlayGameMode::IsRegist(int _ObjectID)
{
	return AllObject_.Contains(_ObjectID);
}

bool APlayGameMode::RegistObject(int _ObjectID, AActor* _Actor)
{
	if (nullptr == _Actor)
	{
		return false;
	}

	// 이미 존재하면
	// 그냥 아무것도 안해
	if (true == IsRegist(_ObjectID))
	{
		return false;
	}

	UObjectMessageComponent* Message = _Actor->FindComponentByClass<UObjectMessageComponent>();

	if (nullptr == Message
		|| false == Message->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > nullptr UObjectMessageComponent"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	AllObject_.Add(_ObjectID, { _Actor, Message });
	return true;
}

bool APlayGameMode::ObjectPushMessage(int _ObjectID, std::shared_ptr<GameServerMessage> _Message)
{
	if (nullptr == _Message)
	{
		return false;
	}

	// 이미 존재하면
	// 그냥 아무것도 안해
	if (false == IsRegist(_ObjectID))
	{
		return false;
	}

	AllObject_[_ObjectID].Message->Enqueue(_Message);

	return true;
}