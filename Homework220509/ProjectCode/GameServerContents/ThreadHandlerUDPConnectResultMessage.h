#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerAndClient.h"
#include "ServerToClient.h"


// 설명 :
class ThreadHandlerUDPConnectResultMessage final
	: public ThreadHandlerBase<UDPConnectResultMessage>
{
	// 서바가 받았다고 치자.

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
	// 이 메세지를 처음 받았을때 실행하는 함수

};

