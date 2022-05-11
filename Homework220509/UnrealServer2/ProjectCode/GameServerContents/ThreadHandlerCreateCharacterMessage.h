#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"


// ���� :
class ThreadHandlerCreateCharacterMessage final
	: public ThreadHandlerBase<CreateCharacterMessage>
{
	// ó���� ���
	CharacterCreateResultMessage Result_;

public:
	// constrcuter destructer
	ThreadHandlerCreateCharacterMessage();
	~ThreadHandlerCreateCharacterMessage();

	// delete Function
	ThreadHandlerCreateCharacterMessage(const ThreadHandlerCreateCharacterMessage& _Other) = delete;
	ThreadHandlerCreateCharacterMessage(ThreadHandlerCreateCharacterMessage&& _Other) noexcept = delete;
	ThreadHandlerCreateCharacterMessage& operator=(const ThreadHandlerCreateCharacterMessage& _Other) = delete;
	ThreadHandlerCreateCharacterMessage& operator=(ThreadHandlerCreateCharacterMessage&& _Other) noexcept = delete;

	void Start() override;
	// �� �޼����� ó���ϴ� �ܰ�
	void DBCheck();

	void Result();

protected:

private:
	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�

};

