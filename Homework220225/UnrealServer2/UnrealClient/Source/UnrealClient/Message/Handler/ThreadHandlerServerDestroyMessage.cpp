#include "ThreadHandlerServerDestroyMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../Play/ChatWindow.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"

// DB�� �����ϴ���
// �����ϴ���
// ���������� ��� ��Ŷ�� ������ �ϱ���
// ���δ� �̾ȿ��� �������� �ϰ�
// ����� �ܺη� ��������� �ȵ˴ϴ�.

// ��� �̷��� �ϰ������ �����ϸ� ū�ϳ��ϴ�.
// �ܿ�� ���� �ƴ϶� �ڵ带 §����� �ǵ��� �ľ��ض�.
// ���� ��������� ���ϴ� �̴ϴ�.
ThreadHandlerServerDestroyMessage::ThreadHandlerServerDestroyMessage(std::shared_ptr<ServerDestroyMessage> _Message)
	: Message_(_Message)
{
	// UGameplayStatics::
}

void ThreadHandlerServerDestroyMessage::Init(UClientGameInstance* _Inst, UWorld* _World)
{
	Inst_ = _Inst;
	World_ = _World;
}


void ThreadHandlerServerDestroyMessage::Start()
{
	if (World_->GetName() != TEXT("LoginLevel"))
	{
		UGameplayStatics::OpenLevel(World_, TEXT("LoginLevel"));
		return;
	}
	
}

