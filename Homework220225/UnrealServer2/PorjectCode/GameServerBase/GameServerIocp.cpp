#include "PreCompile.h"
#include "GameServerIocp.h"
#include <Windows.h>
#include "GameServerDebug.h"

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

GameServerIocp::GameServerIocp(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, int threadCount/* = 0*/)
{
	Initialize(_Func, INFINITE, threadCount);
}

GameServerIocp::GameServerIocp(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, DWORD _Time, int threadCount = 0)
{
	Initialize(_Func, _Time, threadCount);
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

void GameServerIocp::Initialize(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, DWORD _Time, int threadCount)
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

	Iocp_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, threadCount);


	for (size_t i = 0; i < threadCount; i++)
	{
		AddThread(_Func, _Time);
	}
}

void GameServerIocp::AddThread(std::function<void(std::shared_ptr<GameServerIocpWorker>)> _Func, DWORD _Time)
{
	iocpLock.lock();
	std::shared_ptr<GameServerIocpWorker> NewWork = std::make_shared<GameServerIocpWorker>(Iocp_, threadWorkerList_.size(), _Time);
	threadWorkerList_.push_back(NewWork);
	threadList_.push_back(std::make_shared<GameServerThread>(_Func, NewWork));
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