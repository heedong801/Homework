#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"


// 설명 :
class ThreadHandlerClientToReadyMessage final
	: public ThreadHandlerBase<ClientToReadyMessage>
{
	// 처리한 결과
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
	// 이 메세지를 처음 받았을때 실행하는 함수

};

