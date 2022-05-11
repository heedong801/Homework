#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"


// ���� :
class ThreadHandlerSelectCharacterMessage final
	: public ThreadHandlerBase<SelectCharacterMessage>
{


	// ó���� ���
	CharacterSelectResultMessage ResultMessage;

public:
	ThreadHandlerSelectCharacterMessage();
	~ThreadHandlerSelectCharacterMessage();

	// delete Function
	ThreadHandlerSelectCharacterMessage(const ThreadHandlerSelectCharacterMessage& _Other) = delete;
	ThreadHandlerSelectCharacterMessage(ThreadHandlerSelectCharacterMessage&& _Other) noexcept = delete;
	ThreadHandlerSelectCharacterMessage& operator=(const ThreadHandlerSelectCharacterMessage& _Other) = delete;
	ThreadHandlerSelectCharacterMessage& operator=(ThreadHandlerSelectCharacterMessage&& _Other) noexcept = delete;

	void Start() override;

	// �뿡 ���� ���� ����.

	// Ŭ���̾�Ʈ�� �� �÷��̸� ���� ���ҽ��� �غ��س�����?.
	// �� ���ҽ� ����Ʈ�� ������ ���������?
	// Ŭ���̾�Ʈ�� ��� ���ҽ��� �� ��� ����?
	// ���׸���.
	// => ���׸��� ���ҽ� �ε�.
	
	// �����ʿ��� ��� ó������ ����?
	// �����ʿ����� �뿡 �־��ְ� �����ɾ����.
	// �� ����� Ŭ�󿡰� �˷��ָ�

	// �� �޼����� ó���ϴ� �ܰ�
	void DBCheck();

	void SelectResult();

	void SectionInsert();

protected:

private:
	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�

};

