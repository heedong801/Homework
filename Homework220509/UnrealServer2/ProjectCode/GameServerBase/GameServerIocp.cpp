#include "PreCompile.h"
#include "GameServerIocp.h"
#include <Windows.h>
#include "GameServerDebug.h"
#include "GameServerThread.h"

GameServerIocpWorker::GameServerIocpWorker(HANDLE _IocpHandle, size_t _Index, DWORD _time)
	: IocpHandle(_IocpHandle)
	, Time(_time)
	, Index(_Index)
{
}


BOOL GameServerIocpWorker::Wait()
{
	//BOOL ReturnValue = GetQueuedCompletionStatus(IocpHandle, &NumberOfBytesTransferred, &CompletionKey, &lpOverlapped, Time);

	//if (0 == ReturnValue )
	//{
	//	if (WAIT_TIMEOUT == GetLastError())
	//	{
	//		return IocpWaitReturnType::RETURN_TIMEOUT;
	//	}

	//	return IocpWaitReturnType::RETURN_ERROR;
	//}

	// NetWorkBind�� �Ҷ� CompletionKey�� ������ �����Ѵ�.
	// => ������ ���Ͽ� �������� ���ܼ� �� �Լ��� ���ϵǸ� 
	// CompletionKey�� ���ðŴ�.
	// �� ���ϵ��� ���� �ް� �Ǿ���
	// ��¥ �ϵ��� �־��?


	// AcceptEx
	// WsaRecv
	// WsaSend
	// OverLapped ���� �־��ش�.
	// ȣ���Ҷ����� �ٸ� ���귦�����

	// TranmitFile (��Ŀ��Ʈ)
	// OverLappet

	// CompletionKey => OverlappedJOB 
	// lpOverlapped => AcceptExOverapped
	//              => SendExOverapped


	// �� ���Ͽ� send�� ���ú갡 ���ÿ� �Ͼ�� ���ݾƿ�?
	// �װ� ���ÿ� ó���Ϸ��°� �񵿱��ݾƿ�!!!
	// 

	return GetQueuedCompletionStatus(IocpHandle, &NumberOfBytesTransferred, &CompletionKey, &lpOverlapped, Time);
}

GameServerIocp::~GameServerIocp()
{
	for (size_t i = 0; i < threadList_.size(); i++)
	{
		threadList_[i]->join();
	}
}

GameServerIocp::GameServerIocp()
	: Iocp_(NULL)
{

}

GameServerIocp::GameServerIocp(GameServerIocp&& _Other) noexcept
{

}

void GameServerIocp::InitializeIocpHandle(int Count)
{
	Iocp_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, Count);
}

void GameServerIocp::Initialize(std::string ThreadName,
	std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func,
	std::function<void()> _Init,
	std::function<void()> _End,
	DWORD _Time,
	int threadCount)
{
	// ������ ������
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

	InitializeIocpHandle(threadCount);

	for (int i = 0; i < threadCount; i++)
	{
		AddThread(ThreadName, _Func, _Init, _End, _Time, i);
	}
}

void GameServerIocp::AddThread(std::string _Name, std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, std::function<void()> _InitFunction, std::function<void()> _EndFunction, DWORD _Time, unsigned int _Order = 0)
{
	iocpLock.lock();
	std::shared_ptr<GameServerIocpWorker> NewWork = std::make_shared<GameServerIocpWorker>(Iocp_, threadWorkerList_.size(), _Time);
	threadWorkerList_.push_back(NewWork);
	std::shared_ptr<GameServerThread> NewThread = std::make_shared<GameServerThread>(_Name, std::bind(_Func, NewWork), _InitFunction, _EndFunction);
	threadList_.push_back(NewThread);
	NewThread->SetThreadOrder(_Order);
	iocpLock.unlock();
}

void GameServerIocp::Post(DWORD _byteSize, ULONG_PTR _Data)
{
	// �׳� ��� 8����Ʈ�� �����ִ°ž�
	// �츮�� �����Ҵ��ؼ� ��������?
	// �̳༮�� �������Ѵ�.
	PostQueuedCompletionStatus(Iocp_, _byteSize, _Data, nullptr);
}

bool GameServerIocp::Bind(HANDLE _Handle, ULONG_PTR _CompletionKey) const
{
	// ���ϰ� �ϳ��� 8����Ʈ ���� ��ũ�� ����?
	// 8����Ʈ ���� �츮�� �����Ҵ��ؼ� �־�������
	// _Handle ���Ͽ� ���� ���� ���涧���� 8����Ʈ �츮���� ������ ���̴�.
	// �̳༮�� �����ϸ�
	// ���ú갡 �ѹ��� �ǳ���? ��� ������ ���ú� �Ұǵ�.
	// �츮�� ����������?????????????
	if (Iocp_ != CreateIoCompletionPort(_Handle, Iocp_, _CompletionKey, 0))
	{
		return false;
	}

	return true;
}

BOOL GameServerIocp::Execute(DWORD& NumberOfBytesTransferred, ULONG_PTR& CompletionKey, LPOVERLAPPED& lpOverlapped, DWORD _Time)
{
	return GetQueuedCompletionStatus(Iocp_, &NumberOfBytesTransferred, &CompletionKey, &lpOverlapped, _Time);
}

BOOL GameServerIocp::ExecuteEx(LPOVERLAPPED_ENTRY _Entry, PULONG _ulNumEntriesRemoved, DWORD _TimeOut)
{
	//_In_ HANDLE CompletionPort,
	//	_Out_writes_to_(ulCount, *ulNumEntriesRemoved) LPOVERLAPPED_ENTRY lpCompletionPortEntries,
	//	_In_ ULONG ulCount,
	//	_Out_ PULONG ulNumEntriesRemoved,
	//	_In_ DWORD dwMilliseconds,
	//	_In_ BOOL fAlertable

	// 16�� �ѹ��� ó���ϴ� ����
	// �ϴ��� 16
	return GetQueuedCompletionStatusEx(Iocp_, _Entry, 16, _ulNumEntriesRemoved, _TimeOut, FALSE);
}