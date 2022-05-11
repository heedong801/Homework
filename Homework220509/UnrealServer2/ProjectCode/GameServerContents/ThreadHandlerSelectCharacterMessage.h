#pragma once
#include <GameServerCore\ThreadHandlerBase.h>
#include "ClientToServer.h"
#include "ServerToClient.h"


// 설명 :
class ThreadHandlerSelectCharacterMessage final
	: public ThreadHandlerBase<SelectCharacterMessage>
{


	// 처리한 결과
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

	// 룸에 들어가면 게임 시작.

	// 클라이언트는 그 플레이를 위한 리소스를 준비해놔야죠?.
	// 그 리소스 리스트도 서버가 보내줘야죠?
	// 클라이언트는 모든 리소스를 다 들고 있죠?
	// 오그리마.
	// => 오그리마 리소스 로딩.
	
	// 서버쪽에서 어떻게 처리할지 모르죠?
	// 서버쪽에서는 룸에 넣어주고 무적걸어줬어.
	// 그 사실을 클라에게 알려주면

	// 이 메세지를 처리하는 단계
	void DBCheck();

	void SelectResult();

	void SectionInsert();

protected:

private:
	// 이 메세지를 처음 받았을때 실행하는 함수

};

