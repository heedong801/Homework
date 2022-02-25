#include "PreCompile.h"
#include "NetQueue.h"

GameServerQueue NetQueue::JobQueue = GameServerQueue();

NetQueue::NetQueue()
{

}

NetQueue::~NetQueue()
{

}


void NetQueue::Init() {
	JobQueue.Initialize(GameServerQueue::WORK_TYPE::Default, 20, "NetThread");
}

void NetQueue::Queue(const std::function<void()>& CallBack)
{
	JobQueue.EnQueue(CallBack);
}

void NetQueue::Destroy()
{
	JobQueue.Destroy();
}