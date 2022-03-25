#include "PreCompile.h"
#include "DBQueue.h"
#include <GameServerNet\DBConnecter.h>

GameServerQueue DBQueue::JobQueue = GameServerQueue();

DBQueue::DBQueue() 
{

}

DBQueue::~DBQueue() 
{

}

std::mutex ConnectionRock;

void InitDBConnecter(DBConnecter* _DBCon)
{
	// �����忡 �������� ���� ���� Ŀ��Ʈ ȣ���� ������ �ɼ� �����Ƿ�
	// ���� �Ǵ�.
	ConnectionRock.lock();

	if (nullptr == _DBCon)
	{
		GameServerDebug::AssertDebugMsg("DbConnecter Is Nullptr");
		return;
	}

	if (false == _DBCon->Connect("127.0.0.1", "root", "1234", "userver2", 3306))
	{
		std::string Error =  _DBCon->GetLastError();
		GameServerDebug::AssertDebugMsg("DbConnecter Is Connection Error" + Error);
		return;
	}

	ConnectionRock.unlock();
}

void DBQueue::Init() 
{
	// �տ��� 20���� Ŀ�ؼ��� �����
	// �� �����帶�� 

	// Ŀ�ؼ��� �̸� 20���� ����� ��������

	// Thread����
	// ����ϰ� ���� 
	// �ڱ⸸ ��� �������� ����?

	// ������� �������� �����ϱ⿡�� �ùٸ� ���
	// �� 20���� Ŀ�ؼ��� ����ϴ�
	JobQueue.InitializeLocalData<DBConnecter>(GameServerQueue::WORK_TYPE::Default, 20, "DBThread", InitDBConnecter);
}

void DBQueue::Queue(const std::function<void()>& CallBack)
{
	JobQueue.EnQueue(CallBack);
}

void DBQueue::Destroy() 
{
	JobQueue.Destroy();
}