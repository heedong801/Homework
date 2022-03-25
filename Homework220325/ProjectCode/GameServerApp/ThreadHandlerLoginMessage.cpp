#include "PreCompile.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include "DBQueue.h"
#include "NetQueue.h"
#include <GameServerBase/GameServerString.h>
#include "GameServerUser.h"
#include <GameServerNet\DBConnecter.h>
#include "UserTable.h"

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
	// Monster나 이런데에다가 넣어줄것이다.


	// 1	A	A
	// 2	B	B
	// 정보를 가지고

	std::string Name = GameServerThread::GetName();
	
	// TestClass* Test = GameServerThread::GetLocalData<TestClass>();

	LoginResult_.Code = EGameServerCode::LoginError;
	DBQueue::Queue(std::bind(&ThreadHandlerLoginMessage::DBCheck, shared_from_this()));
}

// 10 마리가 한명의 플레이어를 때린다.
// 10개의 쓰레드에서
// GetPlayer()->Damage(MyAtt);
// 충돌체크는 쓰레드에서 할수 있지만
// (메모리를 가져오기만 할때)
// n개의 쓰레드에서 충돌체크를 끝내고
// 
// 다 모아놓은 결과를 하나의 쓰레드에서 한꺼번에 처리하는 방식으로
// 충돌처리(메모리의 변조)

void ThreadHandlerLoginMessage::DBCheck(/*GameEngineThread* _Thread*/)
{
	std::string Name = GameServerThread::GetName();

	UserTable_SelectIDToUserInfo SelectQuery(LoginMessage_->ID);
	SelectQuery.DoQuery();

	if (nullptr == SelectQuery.RowData)
	{
		LoginResult_.Code = EGameServerCode::LoginError;
	}
	else 
	{
		LoginResult_.Code = EGameServerCode::OK;
	}

	// INSERT INTO `userver2`.`user` (`ID`, `PW`) VALUES('c', 'c');

	NetQueue::Queue(std::bind(&ThreadHandlerLoginMessage::ResultSend, shared_from_this()));
}

void ThreadHandlerLoginMessage::ResultSend()
{
	std::shared_ptr<GameServerUser> NewUser = std::make_shared<GameServerUser>();
	GameServerString::UTF8ToAnsi(LoginMessage_->ID, NewUser->ID);

	TCPSession_->SetLink(NewUser);

	GameServerSerializer Sr;
	LoginResult_.Serialize(Sr);
	TCPSession_->Send(Sr.GetData());

	GameServerDebug::LogInfo("Login Result Out");
}