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

	GameServerIocp(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, int threadCount);
	GameServerIocp(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, DWORD _Time, int threadCount);
	~GameServerIocp();

	GameServerIocp(const GameServerIocp& _Other) = delete;
	GameServerIocp(GameServerIocp&& _Other) noexcept;

protected:
	GameServerIocp& operator=(const GameServerIocp& _Other) = delete;
	GameServerIocp& operator=(GameServerIocp&& _Other) = delete;

public:
	void Initialize(
		std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, 
		DWORD _Time, 
		int threadCount, 
		std::function<void(GameServerThread*)> _InitFunction
	);



	void AddThread(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, DWORD _Time, unsigned int _Order/* = 0*/);
	void Post(DWORD _byteSize, ULONG_PTR _Data);
	bool Bind(HANDLE _Handle, ULONG_PTR _CompletionKey) const;


	template<typename LocalDataType>
	void InitializeLocalData(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, DWORD _Time, int threadCount)
	{
		// 윈도우 종속적
		if (128 <= threadCount)
		{
			return;
		}


		if (0 >= threadCount)
		{
			SYSTEM_INFO Info;
			GetSystemInfo(&Info);
			threadCount = Info.dwNumberOfProcessors;
		}

		Iocp_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, threadCount);

		for (int i = 0; i < threadCount; i++)
		{
			AddThreadLocalData<LocalDataType>(_Func, _Time, i);
		}
	}

	template<typename LocalDataType>
	void AddThreadLocalData(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, DWORD _Time, unsigned int _Order/* = 0*/) 
	{
		iocpLock.lock();
		std::shared_ptr<GameServerIocpWorker> NewWork = std::make_shared<GameServerIocpWorker>(Iocp_, threadWorkerList_.size(), _Time);
		threadWorkerList_.push_back(NewWork);
		std::shared_ptr<GameServerThread> NewThread = std::make_shared<GameServerThread>(_Func, NewWork);
		threadList_.push_back(NewThread);
		NewThread->SetThreadOrder(_Order);
		// NewThread->CreateThreadLocalData<LocalDataType>();
		iocpLock.unlock();
	}

};

