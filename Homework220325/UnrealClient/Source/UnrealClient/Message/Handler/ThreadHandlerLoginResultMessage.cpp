#include "ThreadHandlerLoginResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"

// DB�� �����ϴ���
// �����ϴ���
// ���������� ��� ��Ŷ�� ������ �ϱ���
// ���δ� �̾ȿ��� �������� �ϰ�
// ����� �ܺη� ��������� �ȵ˴ϴ�.

// ��� �̷��� �ϰ������ �����ϸ� ū�ϳ��ϴ�.
// �ܿ�� ���� �ƴ϶� �ڵ带 §����� �ǵ��� �ľ��ض�.
// ���� ��������� ���ϴ� �̴ϴ�.
ThreadHandlerLoginResultMessage::ThreadHandlerLoginResultMessage(std::shared_ptr<LoginResultMessage> _LoginResultMessage)
	: LoginResultMessage_(_LoginResultMessage)
{
	// UGameplayStatics::
}

void ThreadHandlerLoginResultMessage::Init(UClientGameInstance* _Inst, UWorld* _World)
{
	Inst_ = _Inst;
	World_ = _World;
}


void ThreadHandlerLoginResultMessage::Start()
{


	// EGameServerCode Code

	if (EGameServerCode::OK == LoginResultMessage_->Code)
	{
		UGameplayStatics::OpenLevel(World_, TEXT("PlayLevel"));
		return;
	}

	// �α��� ui
}

