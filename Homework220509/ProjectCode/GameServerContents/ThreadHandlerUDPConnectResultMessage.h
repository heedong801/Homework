#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerAndClient.h"
#include "ServerToClient.h"


// ���� :
class ThreadHandlerUDPConnectResultMessage final
	: public ThreadHandlerBase<UDPConnectResultMessage>
{
	// ���ٰ� �޾Ҵٰ� ġ��.

public:
	ThreadHandlerUDPConnectResultMessage();
	~ThreadHandlerUDPConnectResultMessage();

	// delete Function
	ThreadHandlerUDPConnectResultMessage(const ThreadHandlerUDPConnectResultMessage& _Other) = delete;
	ThreadHandlerUDPConnectResultMessage(ThreadHandlerUDPConnectResultMessage&& _Other) noexcept = delete;
	ThreadHandlerUDPConnectResultMessage& operator=(const ThreadHandlerUDPConnectResultMessage& _Other) = delete;
	ThreadHandlerUDPConnectResultMessage& operator=(ThreadHandlerUDPConnectResultMessage&& _Other) noexcept = delete;

	void Start() override;


protected:

private:
	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�

};

