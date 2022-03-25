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
		GameServerDebug::LogError("������ ���õǾ����� ���� �������� ��ü�Դϴ�.");
	}

	// AcceptEx �ּ� ���� ���� ���ƿɴϴ�.
	// �̾Ƴ��ڽ��ϴ�.

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

	// ����Ʈ ����� ���´�.

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
	// �׳� ������ ����̴ϴ�.
	// Recv�� ���ϵƴµ� 0
	// ���� ũ�� �߸��ƽ��ϴ�.
	// ���� �ܰ�� �Ѿ�� �մϴ�.
	// ������ �߸��Ȱ�.
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
		GameServerDebug::AssertDebugMsg("nullptr ������ �����Ϸ��� �߽��ϴ�.");
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

// �ܺο��� �������� ���۸� �����ϴ� 
// std::vector<char> �츮 ���۸� ������� ������ ������
void SendOverlapped::CopyFrom(const std::vector<unsigned char>& _form)
{
	New(_form.size());
	std::copy(_form.begin(), _form.end(), Buffer.begin());
}