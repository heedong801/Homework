#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"
#include "ContentsUserData.h"
#include <memory>

// �� ���ǵ� ���⼭ �޴´�.
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

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Start() override;

public:

private:
	void DBCheck();

	void ResultSend();

protected:
	ThreadHandlerRankRequestMessage& operator=(const ThreadHandlerRankRequestMessage& _Other) = delete;
	ThreadHandlerRankRequestMessage& operator=(ThreadHandlerRankRequestMessage&& _Other) = delete;

};

