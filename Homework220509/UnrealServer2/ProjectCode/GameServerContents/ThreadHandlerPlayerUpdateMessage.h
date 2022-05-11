#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerAndClient.h"
#include "ServerToClient.h"


// 설명 :
class ThreadHandlerPlayerUpdateMessage final
	: public ThreadHandlerBase<PlayerUpdateMessage>
{
	// 서바가 받았다고 치자.

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
	// 이 메세지를 처음 받았을때 실행하는 함수

};

