#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"
#include "ContentsUserData.h"
#include <memory>

// �� ���ǵ� ���⼭ �޴´�.
class UserRow;
class ThreadHandlerLoginMessage final
	: public ThreadHandlerBase<LoginMessage>
{
private: // Member Var
	// ó���� ���
	LoginResultMessage LoginResult_;
	CharacterListMessage Characters;
	std::shared_ptr<ContentsUserData> UserData;

public: // Default
	ThreadHandlerLoginMessage();
	~ThreadHandlerLoginMessage();
	ThreadHandlerLoginMessage(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage(ThreadHandlerLoginMessage&& _Other) noexcept = delete;

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Start() override;

public:
	std::shared_ptr<UserRow> RowData;

	int UserIndex_;

private:
	// �� �޼����� ó���ϴ� �ܰ�
	void DBCheck();

	// �� �޼����� ó���� �������� ����Ǵ� �Լ�
	void ResultSend();

	void DBCharacterListCheck();

	void CharctersSend();

protected:
	ThreadHandlerLoginMessage& operator=(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage& operator=(ThreadHandlerLoginMessage&& _Other) = delete;

};

