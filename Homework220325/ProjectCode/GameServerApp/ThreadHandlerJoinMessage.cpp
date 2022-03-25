#include "PreCompile.h"
#include "ThreadHandlerJoinMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include "DBQueue.h"
#include "NetQueue.h"
#include <GameServerBase/GameServerString.h>
#include "GameServerUser.h"
#include <GameServerNet\DBConnecter.h>
#include "UserTable.h"


ThreadHandlerJoinMessage::ThreadHandlerJoinMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<JoinMessage> _JoinMessage_)
	:TCPSession_(_TCPSession), JoinMessage_(_JoinMessage_)
{

}

ThreadHandlerJoinMessage::~ThreadHandlerJoinMessage()
{

}

void ThreadHandlerJoinMessage::Start()
{
	if (nullptr == TCPSession_)
	{
		GameServerDebug::LogError("Join TCPSession Error");
	}
	// Monster나 이런데에다가 넣어줄것이다.


	// 1	A	A
	// 2	B	B
	// 정보를 가지고

	std::string Name = GameServerThread::GetName();

	// TestClass* Test = GameServerThread::GetLocalData<TestClass>();

	JoinResult_.Code = EGameServerCode::JoinError;
	DBQueue::Queue(std::bind(&ThreadHandlerJoinMessage::DBCheck, shared_from_this()));
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

void ThreadHandlerJoinMessage::DBCheck(/*GameEngineThread* _Thread*/)
{
	std::string Name = GameServerThread::GetName();

	UserTable_SelectIDToUserInfo SelectQuery(JoinMessage_->ID);
	SelectQuery.DoQuery();

	if (nullptr == SelectQuery.RowData)
	{
		UserTable_InsertUserInfo Query = UserTable_InsertUserInfo(JoinMessage_->ID, JoinMessage_->PW);
		if (false == Query.DoQuery())
			JoinResult_.Code = EGameServerCode::JoinError;
		else
			JoinResult_.Code = EGameServerCode::OK;
	}
	else
		JoinResult_.Code = EGameServerCode::JoinError_SameID;


	// INSERT INTO `userver2`.`user` (`ID`, `PW`) VALUES('c', 'c');

	NetQueue::Queue(std::bind(&ThreadHandlerJoinMessage::ResultSend, shared_from_this()));
}

void ThreadHandlerJoinMessage::ResultSend()
{
	std::shared_ptr<GameServerUser> NewUser = std::make_shared<GameServerUser>();
	GameServerString::UTF8ToAnsi(JoinMessage_->ID, NewUser->ID);

	TCPSession_->SetLink(NewUser);

	GameServerSerializer Sr;
	JoinResult_.Serialize(Sr);
	TCPSession_->Send(Sr.GetData());

	GameServerDebug::LogInfo("Join Result Out");
}