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

	// 접속자를 받으려는 
	// 비동기 액셉트를 하려는 소켓이다.
	SessionSocket_ = WSASocket(AF_INET, SOCK_STREAM, IPPROTO::IPPROTO_TCP, NULL, NULL, WSA_FLAG_OVERLAPPED);

	if (INVALID_SOCKET == SessionSocket_)
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
	}

	int ErrorCode = 0;

	// 패킷을 보낼때 적절하게 묶어서 보낼라고 합니다.
	// 게임은? 곧바로 보내기를 원합니다.
	// 네이글 알고리즘
	// 노딜레이 옵션
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

	// 재활용 옵션
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

	// 연결관련 옵션
	{
		LINGER lin;

		// 보낼 데이터 바로 패기
		lin.l_onoff = 1;
		// 연결 종료 과정은 거친다.
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

// bool _forceClose 강제종료
void TCPSession::Close(bool _forceClose /*= false*/ ) 
{
	// 그때또 하고 싶은 일이 있을것이다.
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

// 샌드를 했던 리시브를 했던
// 다들어오게 될겁니다.
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
	// 상 호 참조 상태를 막기 위해서 weak_ptr로 상호참조를 막습니다.
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

	// 새로운 리시브 받을때마다 무조건 클리어
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

	// 우리는 맨앞에 무조건 4바이트 뭘 붙이기로 했어.
	// 최소한의 프로토콜 처리도 해줘야 합니다.
	std::vector<unsigned char> outBuffer = std::vector<unsigned char>(_ByteSize);
	memcpy_s(&outBuffer[0], _ByteSize, _Data, _ByteSize);

	if (nullptr != RecvCallBack_)
	{
		RecvCallBack_(std::dynamic_pointer_cast<TCPSession>(shared_from_this()), outBuffer);
	}

	// 이런 패킷을 보냈을리 없어.
	// 아직 연결중이라는게 99%확실한 상황
	//if (패킷처리하다가 이상 있으면 핵인거 같다 
	//    스피드핵 정상적인 패킷을 보내는 놈이 아니다.)
	//{
	//  서버쪽에서 너 나가.
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

// 등록해제
void TCPSession::UnregisterSession() 
{
	TCPListener* Parent = GetParent<TCPListener>();

	if (nullptr == Parent)
	{
		GameServerDebug::AssertDebugMsg("리스너와 연결되지 않은 세션이 존재합니다.");
	}

	std::string TextLog = std::to_string(static_cast<int>(GetSocket()));


	Parent->CloseSession(std::dynamic_pointer_cast<TCPSession>(shared_from_this()));

	CallClose_ = false;

	// 새로운 커넥션 아이디를 부여받아야 한다.
	ConnectId_ = GameServerUnique::GetNextUniqueId();

	GameServerDebug::LogInfo(TextLog + " 소켓 재활용 처리 완료");
}

void TCPSession::DisconnectSocket()
{
	if (INVALID_SOCKET == SessionSocket_)
	{
		GameServerDebug::AssertDebugMsg("유효하지 않은 소켓을 디스커넥트 하려고 했습니다.");
		return;
	}

	if (nullptr == disconnectOverlapped_)
	{
		GameServerDebug::AssertDebugMsg("디스커넥트 오버랩드가 제대로 만들어지지 않았습니다..");
		return;
	}

	// 윈도우가 아직 붙잡고 있는 핸들에 대한 작업을 
	// 윈도우가 제대로 종료해주면
	// 알려주는 함수인데
	// 그걸 알려주는데 필요한게 또 오버랩드입니다.
	BOOL bResult = TransmitFile(SessionSocket_, 0, 0, 0, disconnectOverlapped_->GetOverlapped(), NULL, TF_DISCONNECT | TF_REUSE_SOCKET);

	// 윈도우야 이 소켓을 나는 재활용해서 다시 사용하고 싶어
	// 그런데 니가 아직 붙잡고 있다는걸 알고 있어
	// 니 작업이 완전히 끝나면 disconnectOverlapped_ 로 보내주지 않으련?

	// 다른 의미로 말하자면 이 소켓이 정말 완전히 깨끗하게 재활용할수 있는 소켓인지는
	// 윈도우가 알고 있고 그거 다 확실하면 나한테 알려줘

	if (FALSE == bResult)
	{
		int iError = WSAGetLastError();
		if (ERROR_IO_PENDING != iError)
		{
			GameServerDebug::GetLastErrorPrint();
		}
	}
}

// 서버엔진이라면 굳이 그걸 유저가 알필요가 없어요.
// 비동기 샌드 
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