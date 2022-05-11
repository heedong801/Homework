
#include "ThreadHandlerLevelMoveMessage.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "../../Play/ObjectMessageComponent.h"
#include "../../Global/ClientGameInstance.h"
#include "../../Play/ClientMonster.h"
#include "../../Play/PlayGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "../../Play/ChatWindow.h"
#include "../../Play/ChatWindow.h"
#include "../../UnrealClient.h"


// 이건 사실
// 죽이라는겁니다.
void ThreadHandlerLevelMoveMessage::Start()
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

