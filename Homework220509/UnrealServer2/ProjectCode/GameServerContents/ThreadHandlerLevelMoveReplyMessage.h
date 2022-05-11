#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerAndClient.h"
#include "ServerToClient.h"


// 설명 :
class ThreadHandlerLevelMoveReplyMessage final
	: public ThreadHandlerBase<LevelMoveReplyMessage>
{
	// 서바가 받았다고 치자.

public:
	ThreadHandlerLevelMoveReplyMessage();
	~ThreadHandlerLevelMoveReplyMessage();

	// delete Function
	ThreadHandlerLevelMoveReplyMessage(const ThreadHandlerLevelMoveReplyMessage& _Other) = delete;
	ThreadHandlerLevelMoveReplyMessage(ThreadHandlerLevelMoveReplyMessage&& _Other) noexcept = delete;
	ThreadHandlerLevelMoveReplyMessage& operator=(const ThreadHandlerLevelMoveReplyMessage& _Other) = delete;
	ThreadHandlerLevelMoveReplyMessage& operator=(ThreadHandlerLevelMoveReplyMessage&& _Other) noexcept = delete;

	void Start() override;


protected:

private:
	// 이 메세지를 처음 받았을때 실행하는 함수

};

