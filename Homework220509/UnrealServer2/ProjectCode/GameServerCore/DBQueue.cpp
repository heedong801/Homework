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

void InitDBConnecter()
{
	// 쓰레드에 안전하지 않은 리얼 커넥트 호출은 문제가 될수 있으므로
	// 락을 건다.
	ConnectionRock.lock();

	DBConnecter::InitConntor(GameServerCore::GetDBHost(),
		GameServerCore::GetDBUser(),
		GameServerCore::GetDBPW(),
		GameServerCore::GetDBName(),
		GameServerCore::GetDBPort());

	RedisConnecter::InitConntor("127.0.0.1", 6379);

	ConnectionRock.unlock();
}

void DBQueue::Init()
{
	Inst_->JobQueue.Initialize(GameServerQueue::WORK_TYPE::Default, 20, "DBThread", InitDBConnecter);
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