#include "PreCompile.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include "DBQueue.h"
#include "NetQueue.h"
#include <GameServerBase/GameServerString.h>
#include "GameServerUser.h"

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

	//if (�̰��� ���� �����尡 �ƴ϶��)
	//{
	//	return;
	//}

	// �Ź� �ٸ�������
	// ��ȹ�ڿ� �������α׷��Ӱ� �̾߱⸦ �ؼ�

	// ��ȹ�ڴ� ���� ���� �̾߱��մϴ�.
	// ��� ���̵� �α��� ���ϰ� ���ּ���.
	// ���� �� �ؽ��ڵ�� �ٲ۴ٿ� �����˰����� ������ �մϴ�.
	// db���� ������ ���� ���ü��� �ְ�.
	
	// LoginMessage_->Id.size()

	// ���� �ȵǴ� id�����
	// ����üũ
	// ��� id
	// ���⼭ ó���Ѵٰ� ġ��

	// ȸ�������� �Ǿ��־�� �մϴ�.

	// JHK 1234�� �α��� �ߴ�.

	LoginResult_.Code = EGameServerCode::LoginError;

	DBQueue::Queue(std::bind(&ThreadHandlerLoginMessage::DBCheck, shared_from_this()));
}

void ThreadHandlerLoginMessage::DBCheck()
{
	NetQueue::Queue(std::bind(&ThreadHandlerLoginMessage::ResultSend, shared_from_this()));

	// DB�� �˻��ϰ�
	
	// ���� ��¥ okok
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