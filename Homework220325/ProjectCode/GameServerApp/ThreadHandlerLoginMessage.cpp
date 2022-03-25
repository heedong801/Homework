#include "PreCompile.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include "DBQueue.h"
#include "NetQueue.h"
#include <GameServerBase/GameServerString.h>
#include "GameServerUser.h"
#include <GameServerNet\DBConnecter.h>
#include "UserTable.h"

// DB�� �����ϴ���
// �����ϴ���
// ���������� ��� ��Ŷ�� ������ �ϱ���
// ���δ� �̾ȿ��� �������� �ϰ�
// ����� �ܺη� ��������� �ȵ˴ϴ�.

// ��� �̷��� �ϰ������ �����ϸ� ū�ϳ��ϴ�.
// �ܿ�� ���� �ƴ϶� �ڵ带 §����� �ǵ��� �ľ��ض�.
// ���� ��������� ���ϴ� �̴ϴ�.
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
	// Monster�� �̷������ٰ� �־��ٰ��̴�.


	// 1	A	A
	// 2	B	B
	// ������ ������

	std::string Name = GameServerThread::GetName();
	
	// TestClass* Test = GameServerThread::GetLocalData<TestClass>();

	LoginResult_.Code = EGameServerCode::LoginError;
	DBQueue::Queue(std::bind(&ThreadHandlerLoginMessage::DBCheck, shared_from_this()));
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