// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatWindow.h"
#include "Components/ListView.h"
#include "ChatMessageObject.h"
#include "ChatMessageWidget.h"
#include "../Global/ClientGameInstance.h"
#include "../Message/Messages.h"
#include "../Global/ClientBlueprintFunctionLibrary.h"

// "BP_ChatWindow"

// "MessageList"

void UChatWindow::NativeConstruct() 
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
	Inst->ChatWindow_ = this;

	MessageListView_ = Cast<UListView>(GetWidgetFromName(TEXT("MessageList")));

	if (nullptr == MessageListView_)
	{
		UE_LOG(LogTemp, Error, TEXT("Message List View Is Nullptr"));
		return;
	}
}

void UChatWindow::MessageAdd(FString _id, FString _Message) 
{
	UChatMessageObject* NewChatObject = NewObject<UChatMessageObject>();

	NewChatObject->ID_ = _id;
	NewChatObject->Message_ = _Message;

	MessageAdd(NewChatObject);
}

void UChatWindow::MessageAdd(UChatMessageObject* _ChatObject)
{
	MessageListView_->AddItem(_ChatObject);
	MessageListView_->SetScrollOffset(MessageListView_->GetNumItems() * 50.0f);
}

void UChatWindow::ChatSend(FString _Text, ETextCommit::Type _Type)
{
	if (ETextCommit::Type::OnEnter != _Type)
	{
		return;
	}

	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

	UChatMessageObject* NewChatObject = NewObject<UChatMessageObject>();

	NewChatObject->ID_ = Inst->ID;
	NewChatObject->Message_ = _Text;

	MessageAdd(NewChatObject);
	// MessageListView_->AddItem(NewChatObject);


	ChatMessage CMessage;

	std::string ID;
	std::string Message;
	UClientBlueprintFunctionLibrary::FStringToUTF8(NewChatObject->ID_, ID);
	UClientBlueprintFunctionLibrary::FStringToUTF8(NewChatObject->Message_, Message);

	CMessage.ID = ID;
	CMessage.Message = Message;

	GameServerSerializer Sr;
	CMessage.Serialize(Sr);

	Inst->Send(Sr.GetData());

}

void UChatWindow::NewMessageAdd(UObject* _Object, UUserWidget* _Widget)
{
	UChatMessageObject* Info = Cast<UChatMessageObject>(_Object);
	UChatMessageWidget* Widget = Cast<UChatMessageWidget>(_Widget);

	if (nullptr == Info)
	{
		return;
	}

	if (nullptr == Widget)
	{
		return;
	}

	Widget->ChatString = Info->ID_ + TEXT(" : ") + Info->Message_;
}