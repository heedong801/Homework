#include "ThreadHandlerChatMessage.h"
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
ThreadHandlerChatMessage::ThreadHandlerChatMessage(std::shared_ptr<ChatMessage> _Message)
	: Message_(_Message)
{
	// UGameplayStatics::
}

void ThreadHandlerChatMessage::Init(UClientGameInstance* _Inst, UWorld* _World)
{
	Inst_ = _Inst;
	World_ = _World;
}


void ThreadHandlerChatMessage::Start()
{
	FString ID;
	FString Message;
	UClientBlueprintFunctionLibrary::UTF8ToFString(Message_->ID, ID);
	UClientBlueprintFunctionLibrary::UTF8ToFString(Message_->Message, Message);

	Inst_->ChatWindow_->MessageAdd(ID, Message);
	
}

