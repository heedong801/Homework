#pragma once
#include "CoreMinimal.h"
#include <Memory>
#include "../Messages.h"

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerChatMessage final
{
private: 
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<ChatMessage> Message_;


public: // Default
	ThreadHandlerChatMessage(std::shared_ptr<ChatMessage> _LoginMessage);

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Init(UClientGameInstance* _Inst, UWorld* _World);
	void Start();
};

