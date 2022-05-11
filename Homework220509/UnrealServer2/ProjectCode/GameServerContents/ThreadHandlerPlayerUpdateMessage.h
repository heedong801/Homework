#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerAndClient.h"
#include "ServerToClient.h"


// ���� :
class ThreadHandlerPlayerUpdateMessage final
	: public ThreadHandlerBase<PlayerUpdateMessage>
{
	// ���ٰ� �޾Ҵٰ� ġ��.

public:
	ThreadHandlerPlayerUpdateMessage();
	~ThreadHandlerPlayerUpdateMessage();

	// delete Function
	ThreadHandlerPlayerUpdateMessage(const ThreadHandlerPlayerUpdateMessage& _Other) = delete;
	ThreadHandlerPlayerUpdateMessage(ThreadHandlerPlayerUpdateMessage&& _Other) noexcept = delete;
	ThreadHandlerPlayerUpdateMessage& operator=(const ThreadHandlerPlayerUpdateMessage& _Other) = delete;
	ThreadHandlerPlayerUpdateMessage& operator=(ThreadHandlerPlayerUpdateMessage&& _Other) noexcept = delete;

	void Start() override;


protected:

private:
	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�

};

