#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"
#include "ContentsUserData.h"
#include <memory>

// 그 세션도 여기서 받는다.
class UserRow;
class ThreadHandlerLoginMessage final
	: public ThreadHandlerBase<LoginMessage>
{
private: // Member Var
	// 처리한 결과
	LoginResultMessage LoginResult_;
	CharacterListMessage Characters;
	std::shared_ptr<ContentsUserData> UserData;

public: // Default
	ThreadHandlerLoginMessage();
	~ThreadHandlerLoginMessage();
	ThreadHandlerLoginMessage(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage(ThreadHandlerLoginMessage&& _Other) noexcept = delete;

	// 이 메세지를 처음 받았을때 실행하는 함수
	void Start() override;

public:
	std::shared_ptr<UserRow> RowData;

	int UserIndex_;

private:
	// 이 메세지를 처리하는 단계
	void DBCheck();

	// 이 메세지가 처리가 끝났을때 실행되는 함수
	void ResultSend();

	void DBCharacterListCheck();

	void CharctersSend();

protected:
	ThreadHandlerLoginMessage& operator=(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage& operator=(ThreadHandlerLoginMessage&& _Other) = delete;

};

