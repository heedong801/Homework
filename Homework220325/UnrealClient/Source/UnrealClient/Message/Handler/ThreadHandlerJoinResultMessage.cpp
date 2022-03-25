#include "ThreadHandlerJoinResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "../../Login/LoginGameMode.h"
#include "Kismet/GameplayStatics.h"

// DB에 접속하는일
// 검증하는일
// 마지막으로 결과 패킷을 보내는 일까지
// 전부다 이안에서 벌어져야 하고
// 절대로 외부로 새어나가서는 안됩니다.

// 모든 이렇게 하겠지라고 착각하면 큰일납니다.
// 외우는 것이 아니라 코드를 짠사람의 의도를 파악해라.
// 보통 경력자한테 원하는 겁니다.
ThreadHandlerJoinResultMessage::ThreadHandlerJoinResultMessage(std::shared_ptr<JoinResultMessage> _JoinResultMessage)
	: JoinResultMessage_(_JoinResultMessage)
{
	// UGameplayStatics::
}

void ThreadHandlerJoinResultMessage::Init(UClientGameInstance* _Inst, UWorld* _World)
{
	Inst_ = _Inst;
	World_ = _World;
}


void ThreadHandlerJoinResultMessage::Start()
{
	// EGameServerCode Code

	ALoginGameMode* GameMode = Cast<ALoginGameMode>(World_->GetAuthGameMode());
	
	if (IsValid(GameMode) && GameMode != nullptr)
	{
		ULoginUI* LoginUI = GameMode->GetLoginUI();
		if (IsValid(LoginUI) && LoginUI != nullptr)
		{
			LoginUI->SetJoinResult(JoinResultMessage_->Code);
		}
	}

	// 로그인 ui
}

