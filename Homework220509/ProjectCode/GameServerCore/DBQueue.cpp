#include "PreCompile.h"
#include "DBQueue.h"
#include <GameServerNet\DBConnecter.h>
#include "GameServerCore.h"
#include <GameServerNet\RedisConnecter.h>

DBQueue* DBQueue::Inst_ = new DBQueue();

// GameServerQueue DBQueue::JobQueue = GameServerQueue();

DBQueue::DBQueue() 
{

}

DBQueue::~DBQueue() 
{
	JobQueue.Destroy();
}

std::mutex ConnectionRock;

void InitDBConnecter(DBConnecter* _DBCon)
{
	// �����忡 �������� ���� ���� Ŀ��Ʈ ȣ���� ������ �ɼ� �����Ƿ�
	// ���� �Ǵ�.
	ConnectionRock.lock();

	_DBCon->Reset();

	if (nullptr == _DBCon)
	{
		// GameServerDebug::AssertDebugMsg("DbConnecter Is Nullptr");
		// ġ�����ϼ� �ֽ��ϴ�.
		// ������� �մϴ�.
		ConnectionRock.unlock();
		return;
	}


	

	if (false == _DBCon->Connect(
		GameServerCore::GetDBHost(),
		GameServerCore::GetDBUser(),
		GameServerCore::GetDBPW(),
		GameServerCore::GetDBName(),
		GameServerCore::GetDBPort()))
	{
		std::string Error =  _DBCon->GetLastError();
		GameServerDebug::AssertDebugMsg("DbConnecter Is Connection Error" + Error);
		ConnectionRock.unlock();
		return;
	}

	GameServerThread::CreateThreadLocalData<RedisConnecter>(1);
	RedisConnecter* RCon = GameServerThread::GetLocalData<RedisConnecter>(1);
	RCon->Connect("127.0.0.1", 6379);

	ConnectionRock.unlock();
}

void DBQueue::Init() 
{
	Inst_->JobQueue.InitializeLocalData<DBConnecter>(GameServerQueue::WORK_TYPE::Default, 20, "DBThread", 0, InitDBConnecter);
}

void DBQueue::Queue(const std::function<void()>& CallBack)
{
	Inst_->JobQueue.EnQueue(CallBack);
}

void DBQueue::Destroy() 
{
	if (nullptr != Inst_)
	{
		delete Inst_;
	}
}