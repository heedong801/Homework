#include "ThreadHandlerObjectDestroyMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../Play/ChatWindow.h"
#include "../../UnrealClient.h"
#include "../../Play/ClientMonster.h"
#include "../../Play/PlayGameMode.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "../../Play/ObjectMessageComponent.h"


// DB에 접속하는일
// 검증하는일
// 마지막으로 결과 패킷을 보내는 일까지
// 전부다 이안에서 벌어져야 하고
// 절대로 외부로 새어나가서는 안됩니다.

// 모든 이렇게 하겠지라고 착각하면 큰일납니다.
// 외우는 것이 아니라 코드를 짠사람의 의도를 파악해라.
// 보통 경력자한테 원하는 겁니다.
ThreadHandlerObjectDestroyMessage::ThreadHandlerObjectDestroyMessage(std::shared_ptr<ObjectDestroyMessage> _Message)
	: Message_(_Message)
{
	// UGameplayStatics::
}

void ThreadHandlerObjectDestroyMessage::Init(UClientGameInstance* _Inst, UWorld* _World)
{
	Inst_ = _Inst;
	World_ = _World;
}


void ThreadHandlerObjectDestroyMessage::Start()
{
	APlayGameMode* PGameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(World_));

	if (nullptr == PGameMode
		|| false == PGameMode->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > GameMode Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	PGameMode->ObjectPushMessage(Message_->ObjectID, Message_);
}

