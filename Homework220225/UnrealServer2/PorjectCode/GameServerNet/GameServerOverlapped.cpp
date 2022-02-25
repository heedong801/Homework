#include "PreCompile.h"
#include "GameServerOverlapped.h"
#include "TCPSession.h"
#include "TCPListener.h"


// GameServerOverlapped  ///////////////////////////////////

GameServerOverlapped::GameServerOverlapped()
	: Overlapped_()
{
	ResetOverlapped();
}

void GameServerOverlapped::ResetOverlapped()
{
	memset(&Overlapped_, 0x00, sizeof(WSAOVERLAPPED));
}

LPWSAOVERLAPPED GameServerOverlapped::GetOverlapped() 
{
	return &Overlapped_;
}

void GameServerOverlapped::Execute(BOOL Result, DWORD _ByteSize) 
{
	
}

// AcceptExOverlapped /////////////////////////////////////

AcceptExOverlapped::AcceptExOverlapped()
	: Buffer{ 0, }
	, TCPSession_(nullptr)
{

}

AcceptExOverlapped::AcceptExOverlapped(std::shared_ptr<TCPSession> _TCPSession)
	: Buffer{0,}
	, TCPSession_(_TCPSession)
{

}

AcceptExOverlapped::~AcceptExOverlapped() 
{

}

void AcceptExOverlapped::Execute(BOOL Result, DWORD _ByteSize) 
{
	if (nullptr == TCPSession_)
	{
		GameServerDebug::LogError("세션이 세팅되어있지 않은 오버랩드 객체입니다.");
	}

	// AcceptEx 주소 값이 같이 날아옵니다.
	// 뽑아내겠습니다.

	SOCKADDR_IN* pLocalAddr = nullptr;
	SOCKADDR_IN* pRemoteAddr = nullptr;

	int localLen = 0 ;
	int RemoteLen = 0;

	GetAcceptExSockaddrs(Buffer,
		0,
		sizeof(sockaddr_in) + 16,
		sizeof(sockaddr_in) + 16,
		(LPSOCKADDR*)&pLocalAddr,
		&localLen,
		(LPSOCKADDR*)&pRemoteAddr,
		&RemoteLen);

	// 바이트 덩어리로 나온다.

		char ArrLocalAddr[4];
		memcpy_s(ArrLocalAddr, 4, &pLocalAddr->sin_addr.s_addr, 4);

		char ArrRemoteAddr[4];
		memcpy_s(ArrRemoteAddr, 4, &pRemoteAddr->sin_addr.s_addr, 4);


	TCPSession_->LocalAddress_ = IPEndPoint(pLocalAddr->sin_addr.s_addr, htons(pLocalAddr->sin_port));
	TCPSession_->RemoteAddress_ = IPEndPoint(pRemoteAddr->sin_addr.s_addr, htons(pRemoteAddr->sin_port));


	int a = 0;
}

/// RecvOverlapped ////////////////////////////////////////////////////
RecvOverlapped::RecvOverlapped(TCPSession* _TCPSession)
	: Buffer{ 0, }
	, TCPSession_(_TCPSession)
{
	Clear();
}

RecvOverlapped::~RecvOverlapped()
{

}

void RecvOverlapped::Clear()
{
	memset(Buffer, 0x00, sizeof(Buffer));
	wsaBuffer.len = sizeof(Buffer);
	wsaBuffer.buf = Buffer;
}

void RecvOverlapped::Execute(BOOL Result, DWORD _ByteSize)
{
	// 그냥 연결이 끈긴겁니다.
	// Recv가 리턴됐는데 0
	// 뭔가 크게 잘못됐습니다.
	// 정리 단계로 넘어가야 합니다.
	// 무조건 잘못된것.
	if (0 == _ByteSize)
	{
		TCPSession_->Close();
		return;
	}

	TCPSession_->OnRecv(Buffer, _ByteSize);
}

/// DisconnectOverlapped ////////////////////////////////////////////////////

DisconnectOverlapped::DisconnectOverlapped(TCPSession* _TCPSession)
	: TCPSession_(_TCPSession)
{

}

DisconnectOverlapped::~DisconnectOverlapped() 
{

}


void DisconnectOverlapped::Execute(BOOL /*Result*/, DWORD _ByteSize) 
{
	if (nullptr != TCPSession_)
	{
		TCPSession_->UnregisterSession();
	}
}

/// SendOverlapped ///////////////////////////////////////////////////

SendOverlapped::SendOverlapped() 
	: TCPSession_(nullptr)
	, wsaBuffer_()
{

}

SendOverlapped::SendOverlapped(TCPSession* _TCPSession)
	: TCPSession_(_TCPSession)
	, wsaBuffer_()
{

}
SendOverlapped::~SendOverlapped() 
{

}

int SendOverlapped::GetMaxBufferLength() 
{
	return static_cast<int>(Buffer.size());
}

LPWSABUF SendOverlapped::GetBuffer() 
{
	return &wsaBuffer_;
}

void SendOverlapped::SetTCPSession(TCPSession* _TCPSession)
{
	if (nullptr == _TCPSession)
	{
		GameServerDebug::AssertDebugMsg("nullptr 세션을 세팅하려고 했습니다.");
		return;
	}

	TCPSession_ = _TCPSession;
}

void SendOverlapped::Execute(BOOL /*Result*/, DWORD _ByteSize) 
{
	TCPSession_->OnSendComplete(this);
}

void SendOverlapped::New(size_t _MaxBufferLength)
{
	Buffer.resize(_MaxBufferLength);
	wsaBuffer_.buf = &Buffer[0];
	wsaBuffer_.len = static_cast<ULONG>(Buffer.size());
}

// 외부에서 전달해준 버퍼를 복사하는 
// std::vector<char> 우리 버퍼를 만들수도 있지만 안전성
void SendOverlapped::CopyFrom(const std::vector<unsigned char>& _form)
{
	New(_form.size());
	std::copy(_form.begin(), _form.end(), Buffer.begin());
}