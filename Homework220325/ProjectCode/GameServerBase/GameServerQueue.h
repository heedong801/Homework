#pragma once
#include "GameServerNameBase.h"
#include "GameServerIocp.h"
#include "GameServerObjectPool.h"

// 용도 : 
// 분류 :
// 첨언 : 한번 iocp를 감싸서 기본규칙을 정의한 Queue

enum class IocpWaitReturnType
{
	RETURN_ERROR,
	RETURN_TIMEOUT,
	RETURN_OK,
};


//  뭐 얼마나 string이 메모리 차지한다고 만약에 
class GameServerQueue : public GameServerNameBase
{

private:
	static void QueueFunction(std::shared_ptr<GameServerIocpWorker> _Work, GameServerQueue* _this, const std::string& _ThreadName);

	// 관리되는 iocp라고 보시면 됩니다.
	// 조금은 걸자.
	// 직접

public:


	enum class WORK_TYPE : char
	{
		// Post를 10번 날리면?
		// GetQueuedCompletionStatus 가 10번 리턴할것이다.
		Default, // 기본형 

		// 컨텍스트 스위칭이 더 효율적으로 일어난다.
		// Post를 10번 날리면?
		// GetQueuedCompletionStatusEx 가 n개로 운영체제가 알아서 모아서 리턴할것이다.
		// 보통은 지금 쌓여있는 일을 다 보내줍니다.
		Extension
	};


private: // Member Var
	// 내가 일시키는 용 job
	struct PostJob  : public std::enable_shared_from_this<PostJob>
	{
		std::function<void()> task_;
	};


	// 뭘 보내라는거죠? 일자체를 보내라는 의미가 됩니다.

	// 비동기 파일입출력용 job
	struct OverlappedJob : public std::enable_shared_from_this<PostJob>
	{
		// BOOL 성공 실패
		// DWORD 받은 패킷이나 처리한 데이터의 길이
		// LPOVERLAPPED 비동기 입출력의 정보를 담고 있는 OVERLAPPED의 포인터
		std::function<void(BOOL _Result, DWORD _NumberOfBytes, LPOVERLAPPED)> task_;


	public:
		OverlappedJob() {

		}

		~OverlappedJob() 
		{
			int a = 0;
		}
	};


	mutable GameServerObjectFindPool<OverlappedJob> IocpOverlappedJobPool_;

	// enum의 byte크기를 제한할수가 있다.

	enum class QUEUE_RETURN : char
	{
		OK,
		DESTROY,
	};

	enum class WORKMESSAGE_TYPE : char
	{
		MSG_POST = -2, // 기본형 
		MSG_DESTROY = -1,
		// 0 이상이면
		// 서버메세지
	};


private:
	// IOCP_TYPE WorkType_;
	GameServerIocp Iocp;

public: // Default
	GameServerQueue();

	GameServerQueue(WORK_TYPE _Type, int threadCount, const std::string& _ThreadName = "", std::function<void(GameServerThread*)> _InitFunction = nullptr);
	~GameServerQueue();

	GameServerQueue(const GameServerQueue& _Other) = delete;
	GameServerQueue(GameServerQueue&& _Other) noexcept;

protected:
	GameServerQueue& operator=(const GameServerQueue& _Other) = delete;
	GameServerQueue& operator=(GameServerQueue&& _Other) = delete;

private:
	void Run(std::shared_ptr<GameServerIocpWorker> _Work);
	GameServerQueue::QUEUE_RETURN Work(std::shared_ptr<GameServerIocpWorker> _Work);
	GameServerQueue::QUEUE_RETURN WorkDefault(std::shared_ptr<GameServerIocpWorker> _Work); // 한번에 하나씩.
	GameServerQueue::QUEUE_RETURN WorkExtension(std::shared_ptr<GameServerIocpWorker> _Work); // 한번에 여러개
	std::function<GameServerQueue::QUEUE_RETURN(std::shared_ptr<GameServerIocpWorker> _Work)> WorkFunction;

private:
	void SetWorkType(WORK_TYPE _WorkType);

public: // Member Function
	void EnQueue(const std::function<void()>& _callback);
	void Destroy();
	bool NetWorkBind(SOCKET _Socket, std::function<void(BOOL, DWORD, LPOVERLAPPED)> _callback) const;
	void Initialize(WORK_TYPE _Type, int threadCount, const std::string& _ThreadName, std::function<void(GameServerThread*)> _InitFunction = nullptr);

	template<typename LocalDataType>
	void InitializeLocalData(
		WORK_TYPE _Type, 
		int threadCount, 
		const std::string& _ThreadName, 
		std::function<void(LocalDataType*)> _InitFunction = nullptr
	)
	{
		SetWorkType(_Type);
		Iocp.InitializeLocalData<LocalDataType>(
			std::bind(GameServerQueue::QueueFunctionLocalData<LocalDataType>, std::placeholders::_1, this, _ThreadName, _InitFunction),
			INFINITE, 
			threadCount);
	}

	template<typename LocalDataType>
	static void QueueFunctionLocalData(std::shared_ptr<GameServerIocpWorker> _Work, GameServerQueue* _this, const std::string& _Name, std::function<void(LocalDataType*)> _InitFunction)
	{
		if (nullptr == _this)
		{
			GameServerDebug::AssertDebugMsg("큐 쓰레드 생성에 실패했습니다.");
		}

		GameServerThread::ThreadNameSetting(_Name + " " + std::to_string(_Work->GetIndex()));

		LocalDataType* LocalData = GameServerThread::CreateThreadLocalData<LocalDataType>();

		if (nullptr != _InitFunction)
		{
			_InitFunction( LocalData);
		}

		// Run기동하기전에 뭔가를 해주고 싶을수 있다.
		_this->Run(_Work);
	}

};



