#include "PreCompile.h"
#include "TCPListener.h"
#include "SocketAddress.h"
#include "ServerHelper.h"
#include "TCPSession.h"
#include "GameServerOverlapped.h"

TCPListener::TCPListener() 
	: ListenSocket_(NULL)
	, JobQueue_(nullptr)
	, AcceptCallBack_(nullptr)
{

}

TCPListener::~TCPListener() 
{

	int a = 0;

	connectionPool_;
	connections_;
	AcceptExOverlappedPool_;
	IocpAcceptExOverlappedPool_;
}

TCPListener::TCPListener(TCPListener&& _Other) noexcept
	: ListenSocket_(_Other.ListenSocket_)
{
}



bool TCPListener::Initialize(const IPEndPoint& _EndPoint, const std::function<void(std::shared_ptr<TCPSession>)>& _AcceptCallBack)
{
	ServerHelper::StartEngineStartUp();

	SocketAddress Addresss = _EndPoint.Serialize();

	// �񵿱� �׼�Ʈ�� �Ϸ��� �����̴�.
	ListenSocket_ = WSASocket(AF_INET, SOCK_STREAM, IPPROTO::IPPROTO_TCP, NULL, NULL, WSA_FLAG_OVERLAPPED);

	if (INVALID_SOCKET == ListenSocket_)
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
	}

	// ���� �޴� ���� ���ε带 �ؼ� �ڽ��� �ּҸ� �������Ѿ� �մϴ�.
	int ErrorCode = ::bind(ListenSocket_, reinterpret_cast<const SOCKADDR*>(Addresss.GetBuffer()), static_cast<int>(Addresss.GetBufferLength()));

	if (SOCKET_ERROR == ErrorCode)
	{
		GameServerDebug::GetLastErrorPrint();
		Close();
		return false;
	}

	BOOL on = TRUE;

	ErrorCode = setsockopt(ListenSocket_, SOL_SOCKET, SO_CONDITIONAL_ACCEPT, reinterpret_cast<const char*>(&on), sizeof(on));
	if (SOCKET_ERROR == ErrorCode)
	{
		GameServerDebug::GetLastErrorPrint();
		Close();
		return false;
	}

	ErrorCode = listen(ListenSocket_, 512);
	if (SOCKET_ERROR == ErrorCode)
	{
		GameServerDebug::GetLastErrorPrint();
		Close();
		return false;
	}

	ListenEndPoint_ = _EndPoint;
	AcceptCallBack_ = _AcceptCallBack;
	return true;
}
void TCPListener::Close()
{
	if (NULL != ListenSocket_)
	{
		closesocket(ListenSocket_);
		ListenSocket_ = NULL;
	}
}

bool TCPListener::BindQueue(GameServerQueue& _JobQueue)
{
	JobQueue_ = &_JobQueue;

	// �Ѵܰ� ���ܳ��� �Լ��� �������� �̴ϴ�.
	return JobQueue_->NetWorkBind(ListenSocket_, std::bind(&TCPListener::OnAccept, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

}

void TCPListener::OnAccept(BOOL _Result, DWORD _ByteSize, LPOVERLAPPED _Overlapped)
{
	// ���Ӵ���� �Ѹ��� ��������̴ϱ�.
	AsyncAccept();

	if (nullptr == _Overlapped)
	{
		return;
	}

	// ó���ǰ� ���� �ʿ� �����
	// ���� �̰� ���� �����ؼ� ��ٸ� ������ ������ �����̰�
	// �װ� �ƴ϶�� �������ϱ�.
	std::unique_ptr<AcceptExOverlapped> AcceptExOverPtr = std::unique_ptr<AcceptExOverlapped>(reinterpret_cast<AcceptExOverlapped*>(reinterpret_cast<char*>(_Overlapped) - sizeof(void*)));


	if (nullptr == AcceptCallBack_)
	{
		return;
	}

	if (_Result != 0)
	{
		AcceptExOverPtr->Execute(TRUE, _ByteSize);

		if (nullptr == AcceptCallBack_)
		{
			return;
		}


		// �������� ������ ��� ������� ���⼭ ����
		// Ư�� �������̽��� ���ؼ�
		// �츮�� ������ �տ� 1����Ʈ �����鼭 ����.

		if (false == AcceptExOverPtr->GetTCPSession()->isAcceptBind_)
		{
			AcceptExOverPtr->GetTCPSession()->BindQueue(*JobQueue_);
			AcceptExOverPtr->GetTCPSession()->AcceptBindOn();
		}
		AcceptCallBack_(std::dynamic_pointer_cast<TCPSession>(AcceptExOverPtr->GetTCPSession()->shared_from_this()));


		AcceptExOverPtr->GetTCPSession()->RecvRequest();
		// ���� ���ú긦
		// AcceptExOverPtr->
		// GetTCPSession() 
		// GetTCPSession()-

		connectsLock_.lock();
		connections_.insert(std::make_pair(AcceptExOverPtr->GetTCPSession()->GetConnectId(), AcceptExOverPtr->GetTCPSession()));
		connectsLock_.unlock();

		// ������ �������� �Ѵ�.
		IocpAcceptExOverlappedPool_.Erase(AcceptExOverPtr.get());

		AcceptExOverlappedPool_.Push(AcceptExOverPtr.get());
		AcceptExOverPtr.release();
	}
	else 
	{
		GameServerDebug::AssertDebugMsg("Accept Error");
	}

}

// ������� ������ ������ŭ
// _BackLog ����̳� ���Ӵ�⸦ ��ų�ų�
bool TCPListener::StartAccept(int _BackLog) 
{
	// 128����� �Ѱ�� ���� �� ������ ���̶��
	// �Ȱ��� �ھ����ŭ�� ���Ӵ�⸦ ����� ���ڽ��ϴ�.
	if (0 > _BackLog || 128 < _BackLog )
	{
		SYSTEM_INFO systemInfo;
		GetSystemInfo(&systemInfo);

		_BackLog = systemInfo.dwNumberOfProcessors;
	}

	// ���Ӵ�� ������ ��Ͻ��ѳ��´�.
	for (size_t i = 0; i < _BackLog; i++)
	{
		// ������ �ȵǾ��ִµ� 
		// ������ ���� �� ������ �޾ư��� ���� ���� _BackLog������ ����ٴ� �̾߱�.
		AsyncAccept();
	}

	return true;

}

void TCPListener::AsyncAccept()
{
	// ���Լ��� �ǹ̰� ����?
	// ����ϴ� ���� 1���� �����.
	
	// ������ ������ �ʰ�����.
	
	// 1000�� �����϶�
	// 10�� ������ �����ϴ� => 10���� ������ ������ٴ� �̾߱�.
	// ������ �����߾� 10 => 9�� ����?
	// 1���� ������ �״�� => �� ���ӵ� ������ ����ä�� �÷��̸� ������.
	// ->AsyncAccept()

	// 1000���� �� ��á���.
	// �Ϲ����� ���ӵ� �ް� �ִ� ��Ȳ�̰���? 
	// �÷����ϴ� ������ �ƽ��ϴ�.
	// �������� �÷����ϴٰ� ������ ��Ȳ�� �������̰�?
	
	// �Ѹ��� ������.
	// ���ο� ������ ����°� �ƴ϶�.
	// ������ ��Ȱ���ϴ� �̴ϴ�.
	// �ڸ� ����� ������ �Ǽ� �� �������� �ٽ� ACCEPTEX �ɾ �״�� ���� �ִ�.
	

	// ������ �ڵ鸵�� �޸� ���������� �������ִ°� �ƴϴ�
	// ������� ���ÿ� 10�� ��������� 10���� ���ÿ� ������� �ִ�.
	// 10�� ����� ���ÿ� AsyncAccpet()�� ȣ���ߴٰ� �Ѵٸ�
	// AsyncAccpet() �Լ��� ������ �ڵ�
	PtrSTCPSession NewSession = nullptr;
	{
		// std::lock_guard<std::mutex> lock(connectPoolLock_);

		connectPoolLock_.lock();

		// � �������� ���ԵǸ�
		
		// �̹� ��������ٰ� �ٽ� ��ϱ�ٸ��� ������ ����� �ִ� ����.
		// ������ ��Ƴ����մϴ�.
		// ������
		// list
		// [���Ӵ��][���Ӵ��][���Ӵ��][���Ӵ��][���Ӵ��][][][][]
		
		if (true == connectionPool_.empty())
		{
			NewSession = std::make_unique<TCPSession>();
			NewSession->Initialize();

			std::string LogText = std::to_string(static_cast<int>(NewSession->GetSocket()));
			GameServerDebug::LogInfo(LogText + " ���� ����");

			NewSession->SetParent(this);
		}
		else 
		{
			// ���⿡�� ��Ȱ��� �����̰���?
			// ����ƴٰ� �׳� ���ʿ� �ȵ˴ϴ�.
			// OK?
			NewSession = connectionPool_.front();
			std::string LogText = std::to_string(static_cast<int>(NewSession->GetSocket()));
			GameServerDebug::LogInfo(LogText + " ���� ��Ȱ��");
			connectionPool_.pop_front();
		}

		connectPoolLock_.unlock();
	}

	// �����Ҵ�Ǿ 

	//SOCKET sListenSocket, ������ ���Ӽ���
	//SOCKET sAcceptSocket, ���ӵ� Ŭ���̾�Ʈ���� ���Ǽ���
	//PVOID lpOutputBuffer, �������� ip�ּҸ� �����ִ� ����
	//DWORD dwReceiveDataLength, ������Ŷ�� ������ �ִ� 0������ �ȹ޴´�.
	//DWORD dwLocalAddressLength, // 
	//DWORD dwRemoteAddressLength,
	//LPDWORD lpdwBytesReceived,
	//LPOVERLAPPED lpOverlapped

	// unique_ptr �߻����غ��ô�.
	// �����带 �ѳ������ �־ ���� �ٸ������忡�� ���ÿ� �����ϴ� ���� �����ؼ��� �ȵǴ�
	// �޸𸮵��� �ظ��ϸ� unique_ptr�� ����� �̴ϴ�.
	// �ǵ��� �����ְ� �ִ°�

	AcceptExOverlapped* AcceptOver = nullptr;/* = std::make_unique<AcceptExOverlapped>(NewSession)*/;
	{
		// �� �������� ���� ���ؽ�Ʈ ����Ī�� �Ͼ ���̴�.
		if (true == AcceptExOverlappedPool_.IsEmpty())
		{
			AcceptOver = new AcceptExOverlapped(NewSession);
		}
		else
		{
			// ���⿡�� ��Ȱ��� �����̰���?
			// ����ƴٰ� �׳� ���ʿ� �ȵ˴ϴ�.
			// OK?
			AcceptOver = AcceptExOverlappedPool_.Pop();
			AcceptOver->SetTCPSession(NewSession);
		}
	}
	

	DWORD dwByte = 0;
	// �����Ҷ� ��Ŷ�� �ѹ� �޾ƺ��� �ִ� �����Դϴ�.
	// �ּҰ��� ���� ���ƿɴϴ�.

	// LPFN_ACCEPTEX�� ���ؼ� ���̺귯�� ���̵� �����͸� ���ü��� �ִ�.
	// sizeof(sockaddr_in) +16 Ip4 Ip6���� 
	// ����� ���ᰡ �ȵ� ������ ������?
	BOOL Result = AcceptEx(ListenSocket_, NewSession->GetSocket(), AcceptOver->GetBuffer(), 0, sizeof(sockaddr_in) +16, sizeof(sockaddr_in) + 16, &dwByte, AcceptOver->GetOverlapped());
	IocpAcceptExOverlappedPool_.Push(AcceptOver);

	// ���п���
	if (FALSE == Result)
	{
		// ERROR_IO_PENDING �񵿱� IO�� �ϴ� ���̰� ��ٸ��� ���̴� ����
		if (ERROR_IO_PENDING != WSAGetLastError())
		{
			GameServerDebug::GetLastErrorPrint();
			return;
		}
	}
}

//class LockTest
//{
//	std::mutex Lock;
//public:
//	LockTest() {
//		Lock.lock();
//	}
//  ~LockTest() {
//		Lock.Unlock();
//	}
//};

void TCPListener::CloseSession(PtrSTCPSession _Session)
{
	// ������� �Դٴ°� 
	// ������ ó���� �����ٴ� �̾߱��Դϴ�.
	
	// �̷� ������ ���� ���� �ֽ��ϴ�.
	{
		std::lock_guard<std::mutex> lock(connectsLock_);
		connections_.erase(_Session->GetConnectId());
	}

	// ������� �Ȱ��� ����
	{
		std::lock_guard<std::mutex> lock(connectPoolLock_);
		// ��ٷ� �ٽ� ������ �ϴ°�
		connectionPool_.push_back(_Session);
	}
}

void TCPListener::BroadCast(std::vector<unsigned char> _Data, std::shared_ptr<TCPSession> _Ignore)
{
	connectsLock_.lock();
	for (auto& Session : connections_)
	{
		if (_Ignore == Session.second)
		{
			continue;
		}

		Session.second->Send(_Data);
	}
	connectsLock_.unlock();
}