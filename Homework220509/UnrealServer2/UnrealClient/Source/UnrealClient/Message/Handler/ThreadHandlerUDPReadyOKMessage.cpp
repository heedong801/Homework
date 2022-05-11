#include "ThreadHandlerUDPReadyOKMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../Play/ChatWindow.h"
#include "../../UnrealClient.h"
#include "../../Play/ClientMonster.h"
#include "../../Play/PlayGameMode.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "../../Play/ObjectMessageComponent.h"



void ThreadHandlerUDPReadyOKMessage::Start()
{
	APlayGameMode* PGameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(World_));

	if (nullptr == PGameMode
		|| false == PGameMode->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > GameMode Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	PGameMode->ObjectPushMessage(Message_->ObjectIndex, Message_);
}

