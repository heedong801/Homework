#include "ThreadHandlerChatMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../Play/ChatWindow.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"


void ThreadHandlerChatMessage::Start()
{
	FString ID;
	FString Message;
	UClientBlueprintFunctionLibrary::UTF8ToFString(Message_->ID, ID);
	UClientBlueprintFunctionLibrary::UTF8ToFString(Message_->Message, Message);

	Inst_->ChatWindow_->MessageAdd(ID, Message);
	
}

