// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterListItem.h"
#include "../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../Global/ClientBlueprintFunctionLibrary.h"
#include "../Message/Messages.h"
#include "../UnrealClient.h"
#include "../Message/ServerToClient.h"
#include "../Message/ServerAndClient.h"
#include "../Message/ClientToServer.h"

void UCharacterListItem::CharacterSelect()
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

	if (true == Inst->GetClientMode())
	{
		std::shared_ptr<CharacterSelectResultMessage> Message = std::make_shared<CharacterSelectResultMessage>();
		Message->Code = EGameServerCode::OK;
		Inst->PushClientMessage(Message);
		return;
	}


	std::string ConvertNickName;
	UClientBlueprintFunctionLibrary::FStringToUTF8(NickName, ConvertNickName);

	Inst->NickName = NickName;
	Inst->NickNameUTF8 = ConvertNickName;

	SelectCharacterMessage NewPacket;
	NewPacket.NickName = ConvertNickName;
	GameServerSerializer Sr;
	NewPacket.Serialize(Sr);

	if (false != Inst->Send(Sr.GetData()))
	{
		int a = 0;
	}
}