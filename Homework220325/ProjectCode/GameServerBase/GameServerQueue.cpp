#include "PreCompile.h"
#include "GameServerQueue.h"
#include "GameServerDebug.h"
#include "GameServerThread.h"

void GameServerQueue::QueueFunction(std::shared_ptr<GameServerIocpWorker> _Work, GameServerQueue* _this, const std::string& _Name)
{
	if (nullptr == _this)
	{
		GameServerDebug::AssertDebugMsg("ť ������ ������ �����߽��ϴ�.");
	}

	GameServerThread::ThreadNameSetting(_Name + " " + std::to_string(_Work->GetIndex()));

	_this->Run(_Work);
}

GameServerQueue::GameServerQueue()
{

}

GameServerQueue::GameServerQueue(WORK_TYPE _Type, int threadCount, const std::string& _ThreadName, std::function<void(GameServerThread*)> _InitFunction)
// : Iocp(std::bind(GameServerQueue::QueueFunction, std::placeholders::_1, this), threadCount)
{
	Initialize(_Type, threadCount, _ThreadName, _InitFunction);
}

GameServerQueue::~GameServerQueue()
{
	Destroy();
}

void GameServerQueue::Initialize(WORK_TYPE _Type, int threadCount, const std::string& _ThreadName, std::function<void(GameServerThread*)> _InitFunction)
{
	SetWorkType(_Type);
	Iocp.Initialize(std::bind(GameServerQueue::QueueFunction, std::placeholders::_1, this, _ThreadName), INFINITE, threadCount, _InitFunction);
}

GameServerQueue::GameServerQueue(GameServerQueue&& _Other) noexcept
{

}

void GameServerQueue::SetWorkType(GameServerQueue::WORK_TYPE _WorkType)
{
	switch (_WorkType)
	{
	case GameServerQueue::WORK_TYPE::Default:
		WorkFunction = std::bind(&GameServerQueue::WorkDefault, this, std::placeholders::_1);
		break;
	case GameServerQueue::WORK_TYPE::Extension:
		WorkFunction = std::bind(&GameServerQueue::WorkExtension, this, std::placeholders::_1);
		break;
	default:
		break;
	}

	// WorkType_ = _WorkType;
}

GameServerQueue::QUEUE_RETURN GameServerQueue::Work(std::shared_ptr<GameServerIocpWorker> _Work)
{
	if (nullptr == WorkFunction)
	{
		return GameServerQueue::QUEUE_RETURN::DESTROY;
	}

	return WorkFunction(_Work);
}

// �ϴ� �̳༮�� ���� ��� �޾ƾ� �Ѵ�.
void GameServerQueue::Run(std::shared_ptr<GameServerIocpWorker> _Work)
{
	while (QUEUE_RETURN::DESTROY != Work(_Work));

	int a = 0;
}

GameServerQueue::QUEUE_RETURN GameServerQueue::WorkDefault(std::shared_ptr<GameServerIocpWorker> _Work)
{

	BOOL ReturnType = _Work->Wait();

	int ByteSize = _Work->GetNumberOfBytes();

	IocpWaitReturnType CheckType = IocpWaitReturnType::RETURN_OK;

	if (0 == ReturnType)
	{
		if (WAIT_TIMEOUT == GetLastError())
		{
			CheckType = IocpWaitReturnType::RETURN_TIMEOUT;
		}
		CheckType = IocpWaitReturnType::RETURN_ERROR;
	}

	DWORD MsgType = _Work->GetNumberOfBytes();

	// MsgType == 0�϶� ó���� ��

	switch (MsgType)
	{
	case (DWORD)GameServerQueue::WORKMESSAGE_TYPE::MSG_DESTROY:
		return QUEUE_RETURN::DESTROY;
	case (DWORD)GameServerQueue::WORKMESSAGE_TYPE::MSG_POST:
	{
		if (0 != _Work->GetCompletionKey())
		{
			std::unique_ptr<PostJob> JobTesk = std::unique_ptr<PostJob>(_Work->GetConvertCompletionKey<PostJob*>());
			JobTesk->task_();
		}
		else
		{
			GameServerDebug::LogError("PostJob Is Null");
		}
	}
	break;
	default:
	{
		if (0 != _Work->GetCompletionKey())
		{
			// �� ������ Ŭ�����ϸ� ���ŵɰŴ�.

			// �̰͵� ó���ؾ� �մϴ�.
			OverlappedJob* JobTesk = _Work->GetConvertCompletionKey<OverlappedJob*>();
			JobTesk->task_(ReturnType, _Work->GetNumberOfBytes(), _Work->GetOverlappedPtr());
		}
		else
		{
			GameServerDebug::LogError("OverJob Is Null");
		}

		break;
	}
	}

	return GameServerQueue::QUEUE_RETURN::OK;
}

GameServerQueue::QUEUE_RETURN GameServerQueue::WorkExtension(std::shared_ptr<GameServerIocpWorker> _Work)
{
	return GameServerQueue::QUEUE_RETURN::OK;
}

void GameServerQueue::EnQueue(const std::function<void()>& _callback) 
{
	if (nullptr == _callback)
	{
		GameServerDebug::AssertDebugMsg("�ݹ��� nullptr�� �Ѿ� �Խ��ϴ�.");
		return;
	}
	// �� ����Ʈ ����� 
	// -2�� Post �Լ������͸� ó���ؾ��ϴ� ���̴�.

	// ���� �������ϼ��� ����
	std::unique_ptr<PostJob> PostJobPtr = std::make_unique<PostJob>();
	PostJobPtr->task_ = _callback;
	Iocp.Post(static_cast<DWORD>(WORKMESSAGE_TYPE::MSG_POST), reinterpret_cast<ULONG_PTR>(PostJobPtr.get()));
	PostJobPtr.release();
}

void GameServerQueue::Destroy()
{
	for (size_t i = 0; i < Iocp.GetThreadCount(); i++)
	{
		// �Ϲ����� default
		Iocp.Post(static_cast<DWORD>(WORKMESSAGE_TYPE::MSG_DESTROY), 0);
		Sleep(1);
	}
}

bool GameServerQueue::NetWorkBind(SOCKET _Socket, std::function<void(BOOL, DWORD, LPOVERLAPPED)> _callback) const
{
	std::unique_ptr<OverlappedJob> OverJobPtr = std::make_unique<OverlappedJob>();
	OverJobPtr->task_ = _callback;

	IocpOverlappedJobPool_.Push(OverJobPtr.get());

	if (false == Iocp.Bind(reinterpret_cast<HANDLE>(_Socket), reinterpret_cast<ULONG_PTR>(OverJobPtr.get())))
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
		// GameServerDebug::AssertDebugMsg("���� IOCP ���ε忡 �����߽��ϴ�.");
	}
	OverJobPtr.release();

	return true;
}