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
	// 쓰레드에 안전하지 않은 리얼 커넥트 호출은 문제가 될수 있으므로
	// 락을 건다.
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
	// 앞에서 20개의 커넥션을 만들고
	// 각 쓰레드마다 

	// 커넥션을 미리 20개를 만들고 다음부터

	// Thread마다
	// 사용하고 싶은 
	// 자기만 기는 정보들이 있죠?

	// 어렵지만 선생님이 생각하기에는 올바른 방법
	// 그 20개의 커넥션을 사용하는
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