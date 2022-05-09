#pragma once
#include <GameServerBase/GameServerQueue.h>
// db�� ���õ� ���� �̳༮���� �ñ���̴�.
class DBQueue
{
private: // Member Var
	static DBQueue* Inst_;

private: // Default
	DBQueue();
	~DBQueue();

	DBQueue(const DBQueue& _Other) = delete;
	DBQueue(DBQueue&& _Other) noexcept = delete;

protected:
	DBQueue& operator=(const DBQueue& _Other) = delete;
	DBQueue& operator=(DBQueue&& _Other) = delete;


private: // Member Function
	// ������ �������� �����Ǵ°� ������?
	GameServerQueue JobQueue;

public:
	static void Destroy();

public:
	static void Init();
	static void Queue(const std::function<void()>& CallBack);
};

