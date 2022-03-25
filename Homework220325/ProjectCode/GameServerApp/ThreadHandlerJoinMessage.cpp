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
	// Monster�� �̷������ٰ� �־��ٰ��̴�.


	// 1	A	A
	// 2	B	B
	// ������ ������

	std::string Name = GameServerThread::GetName();

	// TestClass* Test = GameServerThread::GetLocalData<TestClass>();

	JoinResult_.Code = EGameServerCode::JoinError;
	DBQueue::Queue(std::bind(&ThreadHandlerJoinMessage::DBCheck, shared_from_this()));
}

// 10 ������ �Ѹ��� �÷��̾ ������.
// 10���� �����忡��
// GetPlayer()->Damage(MyAtt);
// �浹üũ�� �����忡�� �Ҽ� ������
// (�޸𸮸� �������⸸ �Ҷ�)
// n���� �����忡�� �浹üũ�� ������
// 
// �� ��Ƴ��� ����� �ϳ��� �����忡�� �Ѳ����� ó���ϴ� �������
// �浹ó��(�޸��� ����)

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