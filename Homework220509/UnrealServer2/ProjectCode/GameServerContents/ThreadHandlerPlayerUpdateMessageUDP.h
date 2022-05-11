#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerAndClient.h"
#include "ServerToClient.h"


// ���� :
class ThreadHandlerPlayerUpdateMessageUDP final
	: public ThreadHandlerBase<PlayerUpdateMessage, UDPSession>
{
	// ���ٰ� �޾Ҵٰ� ġ��.

public:
	IPEndPoint Point;

	ThreadHandlerPlayerUpdateMessageUDP();
	~ThreadHandlerPlayerUpdateMessageUDP();

	// delete Function
	ThreadHandlerPlayerUpdateMessageUDP(const ThreadHandlerPlayerUpdateMessageUDP& _Other) = delete;
	ThreadHandlerPlayerUpdateMessageUDP(ThreadHandlerPlayerUpdateMessageUDP&& _Other) noexcept = delete;
	ThreadHandlerPlayerUpdateMessageUDP& operator=(const ThreadHandlerPlayerUpdateMessageUDP& _Other) = delete;
	ThreadHandlerPlayerUpdateMessageUDP& operator=(ThreadHandlerPlayerUpdateMessageUDP&& _Other) noexcept = delete;

	void Start() override;


protected:

private:
	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�

};

