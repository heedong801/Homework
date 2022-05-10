// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSelectUI.h"
#include "../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../Global/ClientBlueprintFunctionLibrary.h"
#include "../Message/Messages.h"
#include "Components/ListView.h"
#include "../UnrealClient.h"
#include "../Message/ServerToClient.h"
#include "../Message/ServerAndClient.h"
#include "../Message/ClientToServer.h"
#include "CharacterListItemObject.h"
#include "CharacterListItem.h"


void UCharacterSelectUI::CharacterCreate() 
{
	if (NickName == "")
	{
		return;
	}


	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

	if (true == Inst->GetClientMode())
	{
		std::shared_ptr<CharacterCreateResultMessage> Message = std::make_shared<CharacterCreateResultMessage>();
		Message->Code = EGameServerCode::OK;
		Inst->PushClientMessage(Message);
		return;
	}


	std::string DataNickName;
	UClientBlueprintFunctionLibrary::FStringToUTF8(NickName, DataNickName);

	CreateCharacterMessage NewPacket;
	NewPacket.NickName = DataNickName;
	GameServerSerializer Sr;
	NewPacket.Serialize(Sr);

	Inst->NickName = NickName;
	Inst->NickNameUTF8 = DataNickName;

	if (Inst->Send(Sr.GetData()))
	{

	}
}

void UCharacterSelectUI::NativeConstruct()
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
	//Inst->ChatWindow_ = this;

	CharacterListView_ = Cast<UListView>(GetWidgetFromName(TEXT("CharacterList")));

	Inst->CharacterListView_ = CharacterListView_;

	for (size_t i = 0; i < Inst->Characters_.size(); i++)
	{
		UCharacterListItemObject* NewCharacterObject = NewObject<UCharacterListItemObject>();
		NewCharacterObject->Info = Inst->Characters_[i];
		UClientBlueprintFunctionLibrary::UTF8ToFString(NewCharacterObject->Info.NickName, NewCharacterObject->ConvertNickName);
		CharacterListView_->AddItem(NewCharacterObject);
		CharacterListView_->SetScrollOffset(CharacterListView_->GetNumItems() * 50.0f);
	}
}



void UCharacterSelectUI::NewCharacterAdd(UObject* _Object, UUserWidget* _Widget)
{
	UCharacterListItemObject* Info = Cast<UCharacterListItemObject>(_Object);
	UCharacterListItem* Widget = Cast<UCharacterListItem>(_Widget);

	if (nullptr == Info)
	{
		return;
	}

	if (nullptr == Widget)
	{
		return;
	}

	Widget->NickName = Info->ConvertNickName;
}
