#pragma once
#include "GameServerNameBase.h"
#include "GameServerIocp.h"
#include "GameServerObjectPool.h"

// �뵵 : 
// �з� :
// ÷�� : �ѹ� iocp�� ���μ� �⺻��Ģ�� ������ Queue

enum class IocpWaitReturnType
{
	RETURN_ERROR,
	RETURN_TIMEOUT,
	RETURN_OK,
};


//  �� �󸶳� string�� �޸� �����Ѵٰ� ���࿡ 
class GameServerQueue : public GameServerNameBase
{

private:
	static void QueueFunction(std::shared_ptr<GameServerIocpWorker> _Work, GameServerQueue* _this, const std::string& _ThreadName);

	// �����Ǵ� iocp��� ���ø� �˴ϴ�.
	// ������ ����.
	// ����

public:


	enum class WORK_TYPE : char
	{
		// Post�� 10�� ������?
		// GetQueuedCompletionStatus �� 10�� �����Ұ��̴�.
		Default, // �⺻�� 

		// ���ؽ�Ʈ ����Ī�� �� ȿ�������� �Ͼ��.
		// Post�� 10�� ������?
		// GetQueuedCompletionStatusEx �� n���� �ü���� �˾Ƽ� ��Ƽ� �����Ұ��̴�.
		// ������ ���� �׿��ִ� ���� �� �����ݴϴ�.
		Extension
	};


private: // Member Var
	// ���� �Ͻ�Ű�� �� job
	struct PostJob  : public std::enable_shared_from_this<PostJob>
	{
		std::function<void()> task_;
	};


	// �� ������°���? ����ü�� ������� �ǹ̰� �˴ϴ�.

	// �񵿱� ��������¿� job
	struct OverlappedJob : public std::enable_shared_from_this<PostJob>
	{
		// BOOL ���� ����
		// DWORD ���� ��Ŷ�̳� ó���� �������� ����
		// LPOVERLAPPED �񵿱� ������� ������ ��� �ִ� OVERLAPPED�� ������
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

	// enum�� byteũ�⸦ �����Ҽ��� �ִ�.

	enum class QUEUE_RETURN : char
	{
		OK,
		DESTROY,
	};

	enum class WORKMESSAGE_TYPE : char
	{
		MSG_POST = -2, // �⺻�� 
		MSG_DESTROY = -1,
		// 0 �̻��̸�
		// �����޼���
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
	GameServerQueue::QUEUE_RETURN WorkDefault(std::shared_ptr<GameServerIocpWorker> _Work); // �ѹ��� �ϳ���.
	GameServerQueue::QUEUE_RETURN WorkExtension(std::shared_ptr<GameServerIocpWorker> _Work); // �ѹ��� ������
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
			GameServerDebug::AssertDebugMsg("ť ������ ������ �����߽��ϴ�.");
		}

		GameServerThread::ThreadNameSetting(_Name + " " + std::to_string(_Work->GetIndex()));

		LocalDataType* LocalData = GameServerThread::CreateThreadLocalData<LocalDataType>();

		if (nullptr != _InitFunction)
		{
			_InitFunction( LocalData);
		}

		// Run�⵿�ϱ����� ������ ���ְ� ������ �ִ�.
		_this->Run(_Work);
	}

};



