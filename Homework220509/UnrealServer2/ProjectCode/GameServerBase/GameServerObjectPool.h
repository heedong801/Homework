#pragma once
#include <deque>
#include <set>
#include <mutex>

// 용도 : 
// 분류 :
// 첨언 : 

// using DataType = int;

template<typename DataType>
class GameServerObjectPool
{
public: // Member Var
	DataType* Pop()
	{
		std::lock_guard<std::mutex> lock(QueueLock_);
		if (true == poolQueue_.empty())
		{
			return new DataType();
		}

		DataType* NewData = poolQueue_.front();
		poolQueue_.pop_front();
		return NewData;
	}

	void Push(DataType* _Data)
	{
		std::lock_guard<std::mutex> lock(QueueLock_);
		poolQueue_.push_front(_Data);
	}


	bool IsEmpty() 
	{
		std::lock_guard<std::mutex> lock(QueueLock_);
		return poolQueue_.empty();
	}



public: // Default
	GameServerObjectPool() {}
	~GameServerObjectPool() 
	{
		for (DataType* Data : poolQueue_)
		{
			delete Data;
		}
	}

	GameServerObjectPool(const GameServerObjectPool& _Other) = delete;
	GameServerObjectPool(GameServerObjectPool&& _Other) 
	{
	}

protected:
	GameServerObjectPool& operator=(const GameServerObjectPool& _Other) = delete;
	GameServerObjectPool& operator=(GameServerObjectPool&& _Other) = delete;

private:
	std::deque<DataType*> poolQueue_;
	std::mutex QueueLock_;

};


template<typename DataType>

// iocp가 맡고 있는 녀석은 여기에 집어 넣습니다.
class GameServerObjectFindPool
{
public: // Member Var
	void Erase(DataType* _Data)
	{
		std::lock_guard<std::mutex> lock(QueueLock_);
		poolQueue_.erase(_Data);
		return;
	}

	void Push(DataType* _Data)
	{
		std::lock_guard<std::mutex> lock(QueueLock_);
		poolQueue_.insert(_Data);
	}

	bool IsEmpty()
	{
		std::lock_guard<std::mutex> lock(QueueLock_);
		return poolQueue_.empty();
	}



public: // Default
	GameServerObjectFindPool() {}
	~GameServerObjectFindPool()
	{
		for (DataType* Data : poolQueue_)
		{
			delete Data;
		}
	}

	GameServerObjectFindPool(const GameServerObjectFindPool& _Other) = delete;
	GameServerObjectFindPool(GameServerObjectFindPool&& _Other)
	{
	}

protected:
	GameServerObjectFindPool& operator=(const GameServerObjectFindPool& _Other) = delete;
	GameServerObjectFindPool& operator=(GameServerObjectFindPool&& _Other) = delete;

private:
	std::set<DataType*> poolQueue_;
	std::mutex QueueLock_;

};

