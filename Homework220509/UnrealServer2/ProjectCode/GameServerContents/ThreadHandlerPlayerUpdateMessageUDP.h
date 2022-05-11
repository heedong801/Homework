#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerAndClient.h"
#include "ServerToClient.h"


// 설명 :
class ThreadHandlerPlayerUpdateMessageUDP final
	: public ThreadHandlerBase<PlayerUpdateMessage, UDPSession>
{
	// 서바가 받았다고 치자.

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
	// 이 메세지를 처음 받았을때 실행하는 함수

};

