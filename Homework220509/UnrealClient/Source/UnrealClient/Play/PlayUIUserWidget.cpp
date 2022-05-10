// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayUIUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "../Global/ClientGameInstance.h"
#include "../Global/ClientBlueprintFunctionLibrary.h"
#include "../Message/ClientToServer.h"
#include "../Message/ServerToClient.h"
#include "../Message/ServerAndClient.h"


void UPlayUIUserWidget::RankWindowOpen()
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (nullptr == Inst || false == Inst->IsValidLowLevel())
	{
		return;
	}

	RankRequestMessage Msg;
	std::string NickNameText;
	UClientBlueprintFunctionLibrary::FStringToUTF8(Inst->NickName, NickNameText);

	Msg.NickName = NickNameText;
	GameServerSerializer Sr;
	Msg.Serialize(Sr);
	if (false == Inst->Send(Sr.GetData()))
	{
		int a = 0;
	}


}