#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"


// 설명 :
class ThreadHandlerCreateCharacterMessage final
	: public ThreadHandlerBase<CreateCharacterMessage>
{
	// 처리한 결과
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
	// 이 메세지를 처리하는 단계
	void DBCheck();

	void Result();

protected:

private:
	// 이 메세지를 처음 받았을때 실행하는 함수

};

