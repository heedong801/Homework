#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"
#include "ContentsUserData.h"
#include <memory>

// 그 세션도 여기서 받는다.
class ThreadHandlerRankRequestMessage final
	: public ThreadHandlerBase<RankRequestMessage>
{
private: // Member Var
	UserRankWindowDataMessage Result;

public: // Default
	ThreadHandlerRankRequestMessage();
	~ThreadHandlerRankRequestMessage();
	ThreadHandlerRankRequestMessage(const ThreadHandlerRankRequestMessage& _Other) = delete;
	ThreadHandlerRankRequestMessage(ThreadHandlerRankRequestMessage&& _Other) noexcept = delete;

	// 이 메세지를 처음 받았을때 실행하는 함수
	void Start() override;

public:

private:
	void DBCheck();

	void ResultSend();

protected:
	ThreadHandlerRankRequestMessage& operator=(const ThreadHandlerRankRequestMessage& _Other) = delete;
	ThreadHandlerRankRequestMessage& operator=(ThreadHandlerRankRequestMessage&& _Other) = delete;

};

