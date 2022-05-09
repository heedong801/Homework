#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"


// ���� :
class ThreadHandlerClientToReadyMessage final
	: public ThreadHandlerBase<ClientToReadyMessage>
{
	// ó���� ���
	CharacterSelectResultMessage ResultMessage;

public:
	ThreadHandlerClientToReadyMessage();
	~ThreadHandlerClientToReadyMessage();

	// delete Function
	ThreadHandlerClientToReadyMessage(const ThreadHandlerClientToReadyMessage& _Other) = delete;
	ThreadHandlerClientToReadyMessage(ThreadHandlerClientToReadyMessage&& _Other) noexcept = delete;
	ThreadHandlerClientToReadyMessage& operator=(const ThreadHandlerClientToReadyMessage& _Other) = delete;
	ThreadHandlerClientToReadyMessage& operator=(ThreadHandlerClientToReadyMessage&& _Other) noexcept = delete;

	void Start() override;
protected:

private:
	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�

};

