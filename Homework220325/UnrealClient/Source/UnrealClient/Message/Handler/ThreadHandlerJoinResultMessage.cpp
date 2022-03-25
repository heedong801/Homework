#include "ThreadHandlerJoinResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "../../Login/LoginGameMode.h"
#include "Kismet/GameplayStatics.h"

// DB�� �����ϴ���
// �����ϴ���
// ���������� ��� ��Ŷ�� ������ �ϱ���
// ���δ� �̾ȿ��� �������� �ϰ�
// ����� �ܺη� ��������� �ȵ˴ϴ�.

// ��� �̷��� �ϰ������ �����ϸ� ū�ϳ��ϴ�.
// �ܿ�� ���� �ƴ϶� �ڵ带 §����� �ǵ��� �ľ��ض�.
// ���� ��������� ���ϴ� �̴ϴ�.
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

	// �α��� ui
}

