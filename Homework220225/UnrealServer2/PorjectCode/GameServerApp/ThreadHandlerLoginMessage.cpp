#include "PreCompile.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include "DBQueue.h"
#include "NetQueue.h"
#include <GameServerBase/GameServerString.h>
#include "GameServerUser.h"

// DB에 접속하는일
// 검증하는일
// 마지막으로 결과 패킷을 보내는 일까지
// 전부다 이안에서 벌어져야 하고
// 절대로 외부로 새어나가서는 안됩니다.

// 모든 이렇게 하겠지라고 착각하면 큰일납니다.
// 외우는 것이 아니라 코드를 짠사람의 의도를 파악해라.
// 보통 경력자한테 원하는 겁니다.
ThreadHandlerLoginMessage::ThreadHandlerLoginMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<LoginMessage> _LoginMessage)
	:TCPSession_(_TCPSession), LoginMessage_(_LoginMessage)
{

}

ThreadHandlerLoginMessage::~ThreadHandlerLoginMessage()
{

}

void ThreadHandlerLoginMessage::Start()
{
	if (nullptr == TCPSession_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	//if (이곳이 로직 쓰레드가 아니라면)
	//{
	//	return;
	//}

	// 매번 다르겠지만
	// 기획자와 선임프로그래머가 이야기를 해서

	// 기획자는 정말 쉽게 이야기합니다.
	// 욕들어간 아이디 로그인 못하게 해주세요.
	// 욕을 다 해쉬코드로 바꾼다움 검증알고리즘을 만들어야 합니다.
	// db에다 저장해 놓고 얻어올수도 있고.
	
	// LoginMessage_->Id.size()

	// 말도 안되는 id라던가
	// 길이체크
	// 욕들어간 id
	// 여기서 처리한다고 치고

	// 회원가입이 되어있어야 합니다.

	// JHK 1234로 로그인 했다.

	LoginResult_.Code = EGameServerCode::LoginError;

	DBQueue::Queue(std::bind(&ThreadHandlerLoginMessage::DBCheck, shared_from_this()));
}

void ThreadHandlerLoginMessage::DBCheck()
{
	NetQueue::Queue(std::bind(&ThreadHandlerLoginMessage::ResultSend, shared_from_this()));

	// DB를 검색하고
	
	// 이제 진짜 okok
	LoginResult_.Code = EGameServerCode::OK;
}

void ThreadHandlerLoginMessage::ResultSend()
{
	std::shared_ptr<GameServerUser> NewUser = std::make_shared<GameServerUser>();
	GameServerString::UTF8ToAnsi(LoginMessage_->ID, NewUser->ID);

	TCPSession_->SetLink(NewUser);

	GameServerSerializer Sr;
	LoginResult_.Serialize(Sr);
	TCPSession_->Send(Sr.GetData());

}