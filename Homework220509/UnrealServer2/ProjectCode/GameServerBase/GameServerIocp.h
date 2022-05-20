#pragma once
#include <WinSock2.h>
#include <thread>
#include <vector>
#include <mutex>
#include <functional>
#include "GameServerThread.h"
#include "GameServerObjectBase.h"

// 용도 : 
// 분류 : 
// 첨언 : 


class GameServerThread;
class GameServerIocpWorker
{
public:
	friend class GameServerIocp;

private:
	HANDLE IocpHandle;
	DWORD NumberOfBytesTransferred;
	ULONG_PTR CompletionKey;
	LPOVERLAPPED lpOverlapped;
	DWORD Time;
	size_t Index;

public:
	template<typename ConvertType>
	ConvertType GetConvertCompletionKey()
	{
		return reinterpret_cast<ConvertType>(CompletionKey);
	}

	ULONG_PTR GetCompletionKey()
	{
		return CompletionKey;
	}

	DWORD GetNumberOfBytes()
	{
		return NumberOfBytesTransferred;
	}

	LPOVERLAPPED GetOverlappedPtr()
	{
		return lpOverlapped;
	}


public:
	size_t GetIndex()
	{
		return Index;
	}

public:
	GameServerIocpWorker(HANDLE _IocpHandle, size_t _Index, DWORD _time);

public:
	BOOL Wait();
};

// 이녀석이 쓰레드도 만들거냐 말거냐.
class GameServerThread;
class GameServerIocp : public GameServerObjectBase
{
private: // Member Var
	HANDLE Iocp_;
	std::mutex iocpLock;
	std::vector<std::shared_ptr<GameServerThread>> threadList_;
	std::vector<std::shared_ptr<GameServerIocpWorker>> threadWorkerList_;

public:
	size_t GetThreadCount()
	{
		return threadList_.size();
	}


public: // Default
	// -1은 그냥 기본 시스템 코어개수 * 2 만큼 만들어라.

	GameServerIocp();

	~GameServerIocp();

	GameServerIocp(const GameServerIocp& _Other) = delete;
	GameServerIocp(GameServerIocp&& _Other) noexcept;

protected:
	GameServerIocp& operator=(const GameServerIocp& _Other) = delete;
	GameServerIocp& operator=(GameServerIocp&& _Other) = delete;

public:
	void Initialize(
		std::string ThreadName,
		std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func,
		std::function<void()> _Init,
		std::function<void()> _End,
		DWORD _Time,
		int threadCount
	);

	void InitializeIocpHandle(int Count);

	void AddThread(std::string ThreadName,
		std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func,
		std::function<void()> _InitFunction,
		std::function<void()> _End,
		DWORD _Time, unsigned int _Order/* = 0*/);
	void Post(DWORD _byteSize, ULONG_PTR _Data);
	bool Bind(HANDLE _Handle, ULONG_PTR _CompletionKey) const;

	BOOL Execute(DWORD& NumberOfBytesTransferred, ULONG_PTR& CompletionKey, LPOVERLAPPED& lpOverlapped, DWORD _Time);

	BOOL ExecuteEx(LPOVERLAPPED_ENTRY _Entry, PULONG _ulNumEntriesRemoved, DWORD _TimeOut);

};

