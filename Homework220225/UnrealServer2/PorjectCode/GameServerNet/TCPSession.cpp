#include "PreCompile.h"
#include "TCPSession.h"
#include "TypeDefine.h"
#include "GameServerOverlapped.h"
#include "TCPListener.h"

TCPSession::TCPSession() 
	: ConnectId_(0),
	SessionSocket_(INVALID_SOCKET),
	CallClose_(false),
	RecvCallBack_(nullptr),
	recvOverlapped_(nullptr),
	disconnectOverlapped_(nullptr),
	isAcceptBind_(false)
{
}

TCPSession::~TCPSession() 
{
	if (nullptr != recvOverlapped_)
	{
		delete recvOverlapped_;
	}

	if (nullptr != disconnectOverlapped_)
	{
		delete disconnectOverlapped_;
	}

	SendPool_;
}

TCPSession::TCPSession(TCPSession&& _Other) noexcept
{

}


void TCPSession::AcceptBindOn() 
{
	isAcceptBind_ = true;
}

__int64 TCPSession::GetConnectId() 
{
	return ConnectId_;
}

SOCKET TCPSession::GetSocket() 
{
	return SessionSocket_;
}

bool TCPSession::Initialize() 
{

	// �����ڸ� �������� 
	// �񵿱� �׼�Ʈ�� �Ϸ��� �����̴�.
	SessionSocket_ = WSASocket(AF_INET, SOCK_STREAM, IPPROTO::IPPROTO_TCP, NULL, NULL, WSA_FLAG_OVERLAPPED);

	if (INVALID_SOCKET == SessionSocket_)
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
	}

	int ErrorCode = 0;

	// ��Ŷ�� ������ �����ϰ� ��� ������� �մϴ�.
	// ������? ��ٷ� �����⸦ ���մϴ�.
	// ���̱� �˰���
	// ������� �ɼ�
	{
		BOOL bNodelayOption = TRUE;
		ErrorCode = setsockopt(SessionSocket_, IPPROTO::IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<const char*>(&bNodelayOption), sizeof(bNodelayOption));
		if (SOCKET_ERROR == ErrorCode)
		{
			GameServerDebug::GetLastErrorPrint();
			Close();
			return false;
		}
	}

	// ��Ȱ�� �ɼ�
	{
		BOOL bResueOption = TRUE;
		ErrorCode = setsockopt(SessionSocket_, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&bResueOption), sizeof(bResueOption));
		if (SOCKET_ERROR == ErrorCode)
		{
			GameServerDebug::GetLastErrorPrint();
			Close();
			return false;
		}
	}

	// ������� �ɼ�
	{
		LINGER lin;

		// ���� ������ �ٷ� �б�
		lin.l_onoff = 1;
		// ���� ���� ������ ��ģ��.
		lin.l_linger = 0;

		ErrorCode = setsockopt(SessionSocket_, SOL_SOCKET, SO_LINGER, reinterpret_cast<const char*>(&lin), sizeof(lin));
		if (SOCKET_ERROR == ErrorCode)
		{
			GameServerDebug::GetLastErrorPrint();
			Close();
			return false;
		}
	}

	ConnectId_ = GameServerUnique::GetNextUniqueId();

	if (nullptr == recvOverlapped_)
	{
		recvOverlapped_ = new RecvOverlapped(this);
	}

	if (nullptr == disconnectOverlapped_)
	{
		disconnectOverlapped_ = new DisconnectOverlapped(this);
	}


	return true;
}

// bool _forceClose ��������
void TCPSession::Close(bool _forceClose /*= false*/ ) 
{
	// �׶��� �ϰ� ���� ���� �������̴�.
	if (nullptr != CloseCallBack_)
	{
		CloseCallBack_(std::dynamic_pointer_cast<TCPSession>(shared_from_this()));
	}

	CallClose_ = true;

	if (false == _forceClose)
	{
		DisconnectSocket();
	}
	else 
	{
		CloseSocket();
	}
}

// ���带 �ߴ� ���ú긦 �ߴ�
// �ٵ����� �ɰ̴ϴ�.
void TCPSession::OnCallBack(std::weak_ptr<TCPSession> _weakSession, BOOL _Result, DWORD numberrOfBytes, LPOVERLAPPED _lpOverlapped)
{
	if (nullptr == _lpOverlapped)
	{
		return;
	}

	GameServerOverlapped* GameServerOver = reinterpret_cast<GameServerOverlapped*>(reinterpret_cast<char*>(_lpOverlapped) - sizeof(void*));
	GameServerOver->Execute(_Result, numberrOfBytes);
}

bool TCPSession::BindQueue(const GameServerQueue& _jobQueue)
{
	// this == TCPSession* const ;
	// std::shaerd_ptr<TCPSession>();
	// �� ȣ ���� ���¸� ���� ���ؼ� weak_ptr�� ��ȣ������ �����ϴ�.
	std::weak_ptr<TCPSession> Ptr = std::dynamic_pointer_cast<TCPSession>(shared_from_this());

	return _jobQueue.NetWorkBind(SessionSocket_, std::bind(&TCPSession::OnCallBack, Ptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void TCPSession::CloseSocket()
{
	if (INVALID_SOCKET != SessionSocket_)
	{
		shutdown(SessionSocket_, SD_BOTH);
		closesocket(SessionSocket_);
		SessionSocket_ = INVALID_SOCKET;
	}
}

void TCPSession::RecvRequest() 
{
	DWORD recvByte = 0;
	DWORD dwFlags = 0;

	// ���ο� ���ú� ���������� ������ Ŭ����
	recvOverlapped_->Clear();

	if (SOCKET_ERROR == WSARecv(
		SessionSocket_,
		recvOverlapped_->GetWSABuffer(),
		1,
		&recvByte,
		&dwFlags,
		recvOverlapped_->GetOverlapped(),
		nullptr))
	{
		int Error = WSAGetLastError();
		if (WSA_IO_PENDING != Error)
		{
			GameServerDebug::GetLastErrorPrint();
			return;
		}
	}
}

// enum DataType
// {
//    PlayMessage,
//    PlayMessage,
// }

void TCPSession::OnRecv(const char* _Data, DWORD _ByteSize)
{

	// �츮�� �Ǿտ� ������ 4����Ʈ �� ���̱�� �߾�.
	// �ּ����� �������� ó���� ����� �մϴ�.
	std::vector<unsigned char> outBuffer = std::vector<unsigned char>(_ByteSize);
	memcpy_s(&outBuffer[0], _ByteSize, _Data, _ByteSize);

	if (nullptr != RecvCallBack_)
	{
		RecvCallBack_(std::dynamic_pointer_cast<TCPSession>(shared_from_this()), outBuffer);
	}

	// �̷� ��Ŷ�� �������� ����.
	// ���� �������̶�°� 99%Ȯ���� ��Ȳ
	//if (��Ŷó���ϴٰ� �̻� ������ ���ΰ� ���� 
	//    ���ǵ��� �������� ��Ŷ�� ������ ���� �ƴϴ�.)
	//{
	//  �����ʿ��� �� ����.
	//	Close();
	//	return;
	//}

	if (false == CallClose_)
	{
		RecvRequest();
	}
	
}

void TCPSession::SetCallBack(RecvCallBack _RecvCallBack, CloseCallBack _CloseCallBack)
{
	if (nullptr == _RecvCallBack)
	{
		GameServerDebug::LogError("RecvCallBack Is Nullptr");
	}

	RecvCallBack_ = _RecvCallBack;
	CloseCallBack_ = _CloseCallBack;
}

// �������
void TCPSession::UnregisterSession() 
{
	TCPListener* Parent = GetParent<TCPListener>();

	if (nullptr == Parent)
	{
		GameServerDebug::AssertDebugMsg("�����ʿ� ������� ���� ������ �����մϴ�.");
	}

	std::string TextLog = std::to_string(static_cast<int>(GetSocket()));


	Parent->CloseSession(std::dynamic_pointer_cast<TCPSession>(shared_from_this()));

	CallClose_ = false;

	// ���ο� Ŀ�ؼ� ���̵� �ο��޾ƾ� �Ѵ�.
	ConnectId_ = GameServerUnique::GetNextUniqueId();

	GameServerDebug::LogInfo(TextLog + " ���� ��Ȱ�� ó�� �Ϸ�");
}

void TCPSession::DisconnectSocket()
{
	if (INVALID_SOCKET == SessionSocket_)
	{
		GameServerDebug::AssertDebugMsg("��ȿ���� ���� ������ ��Ŀ��Ʈ �Ϸ��� �߽��ϴ�.");
		return;
	}

	if (nullptr == disconnectOverlapped_)
	{
		GameServerDebug::AssertDebugMsg("��Ŀ��Ʈ �������尡 ����� ��������� �ʾҽ��ϴ�..");
		return;
	}

	// �����찡 ���� ����� �ִ� �ڵ鿡 ���� �۾��� 
	// �����찡 ����� �������ָ�
	// �˷��ִ� �Լ��ε�
	// �װ� �˷��ִµ� �ʿ��Ѱ� �� ���������Դϴ�.
	BOOL bResult = TransmitFile(SessionSocket_, 0, 0, 0, disconnectOverlapped_->GetOverlapped(), NULL, TF_DISCONNECT | TF_REUSE_SOCKET);

	// ������� �� ������ ���� ��Ȱ���ؼ� �ٽ� ����ϰ� �;�
	// �׷��� �ϰ� ���� ����� �ִٴ°� �˰� �־�
	// �� �۾��� ������ ������ disconnectOverlapped_ �� �������� ������?

	// �ٸ� �ǹ̷� �����ڸ� �� ������ ���� ������ �����ϰ� ��Ȱ���Ҽ� �ִ� ����������
	// �����찡 �˰� �ְ� �װ� �� Ȯ���ϸ� ������ �˷���

	if (FALSE == bResult)
	{
		int iError = WSAGetLastError();
		if (ERROR_IO_PENDING != iError)
		{
			GameServerDebug::GetLastErrorPrint();
		}
	}
}

// ���������̶�� ���� �װ� ������ ���ʿ䰡 �����.
// �񵿱� ���� 
bool TCPSession::Send(const std::vector<unsigned char>& _Buffer)
{
	if (_Buffer.empty())
	{
		return false;
	}

	DWORD ByteSize = 0;
	DWORD flag = 0;


	//if (SOCKET_ERROR == WSARecv(
	//	SessionSocket_,
	//	recvOverlapped_->GetWSABuffer(),
	//	1,
	//	&recvByte,
	//	&dwFlags,
	//	recvOverlapped_->GetOverlapped(),
	//	nullptr))

	SendOverlapped* SendOverLapped = SendPool_.Pop();
	SendOverLapped->SetTCPSession(this);
	SendOverLapped->CopyFrom(_Buffer);
	// SendOverLapped->New(1024);

	int socketError = WSASend(SessionSocket_, SendOverLapped->GetBuffer(), 1, &ByteSize, flag, SendOverLapped->GetOverlapped(), nullptr);

	if (SOCKET_ERROR == socketError)
	{
		if (WSA_IO_PENDING != WSAGetLastError())
		{
			GameServerDebug::GetLastErrorPrint();
			return false;
		}
	}

	return true;
}

void TCPSession::OnSendComplete(SendOverlapped* _Send) 
{
	SendPool_.Push(_Send);
}