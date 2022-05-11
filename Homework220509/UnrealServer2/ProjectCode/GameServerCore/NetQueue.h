#pragma once
#include <GameServerBase/GameServerQueue.h>

// db에 관련된 일은 이녀석에게 맡길것이다.
class NetQueue
{
private: // Member Var

public: // Default
	NetQueue();
	~NetQueue();

	NetQueue(const NetQueue& _Other) = delete;
	NetQueue(NetQueue&& _Other) noexcept = delete;

protected:
	NetQueue& operator=(const NetQueue& _Other) = delete;
	NetQueue& operator=(NetQueue&& _Other) = delete;


private: // Member Function
	static GameServerQueue JobQueue;

public:
	static GameServerQueue& GetQueue() 
	{
		return JobQueue;
	}

	static void Destroy();

public:
	static void Init();
	static void Queue(const std::function<void()>& CallBack);
};

