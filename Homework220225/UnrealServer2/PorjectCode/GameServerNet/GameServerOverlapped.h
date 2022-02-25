#pragma once

#include "TypeDefine.h"


// 92 
// 100

class GameServerOverlapped 
{
public:
	GameServerOverlapped();
	virtual ~GameServerOverlapped() = 0 {} ;

public:
	LPWSAOVERLAPPED GetOverlapped();

protected:
	WSAOVERLAPPED Overlapped_;

public:
	void ResetOverlapped();

	virtual void Execute(BOOL Result, DWORD _ByteSize);

};

class AcceptExOverlapped 
	: public GameServerOverlapped
{
public:
	AcceptExOverlapped();
	AcceptExOverlapped(std::shared_ptr<TCPSession> _TCPSession);
	~AcceptExOverlapped();

	void Execute(BOOL Result, DWORD _ByteSize) override;

	void* GetBuffer() {
		return Buffer;
	}

	void SetTCPSession(std::shared_ptr<TCPSession> _Session)
	{
		TCPSession_ = _Session;
	}

	std::shared_ptr<TCPSession> GetTCPSession()
	{
		return TCPSession_;
	}

private:
	// 절대로 겹치면 안됩니다.
	char Buffer[128];
	std::shared_ptr<TCPSession> TCPSession_;
};

class RecvOverlapped
	: public GameServerOverlapped
{
public:
	RecvOverlapped(TCPSession* _TCPSession);
	~RecvOverlapped();

	void Clear();

	void Execute(BOOL Result, DWORD _ByteSize) override;

	void* GetBuffer() {
		return Buffer;
	}


	LPWSABUF GetWSABuffer() {
		return &wsaBuffer;
	}

	TCPSession* GetTCPSession()
	{
		return TCPSession_;
	}

private:
	// 절대로 겹치면 안됩니다.
	// 받은 데이터가 들어가야 하니까.
	char Buffer[1024];
	WSABUF wsaBuffer;
	TCPSession* TCPSession_;
};

class DisconnectOverlapped
	: public GameServerOverlapped
{
public:
	DisconnectOverlapped(TCPSession* _TCPSession);
	~DisconnectOverlapped();

	void Execute(BOOL Result, DWORD _ByteSize) override;

private:
	TCPSession* TCPSession_;
};

class SendOverlapped
	: public GameServerOverlapped
{
public:
	SendOverlapped();
	SendOverlapped(TCPSession* _TCPSession);
	~SendOverlapped();

	void SetTCPSession(TCPSession* _TCPSession);

	int GetMaxBufferLength();

	LPWSABUF GetBuffer();

	void New(size_t _MaxBufferLength);

	// 외부에서 전달해준 버퍼를 복사하는 
	// std::vector<char> 우리 버퍼를 만들수도 있지만 안전성
	void CopyFrom(const std::vector<unsigned char>& _form);

	void Execute(BOOL /*Result*/, DWORD _ByteSize);

private:
	std::vector<char> Buffer;
	WSABUF wsaBuffer_;
	TCPSession* TCPSession_;
};