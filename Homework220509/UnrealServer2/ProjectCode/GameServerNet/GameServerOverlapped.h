#pragma once

#include "TypeDefine.h"
#include <memory>


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
	// ����� ��ġ�� �ȵ˴ϴ�.
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
	// ����� ��ġ�� �ȵ˴ϴ�.
	// ���� �����Ͱ� ���� �ϴϱ�.
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

	// �ܺο��� �������� ���۸� �����ϴ� 
	// std::vector<char> �츮 ���۸� ������� ������ ������
	void CopyFrom(const std::vector<unsigned char>& _form);

	void Execute(BOOL /*Result*/, DWORD _ByteSize);

private:
	std::vector<char> Buffer;
	WSABUF wsaBuffer_;
	TCPSession* TCPSession_;
};


class UDPRecvOverlapped
	: public GameServerOverlapped
{
public:
	UDPRecvOverlapped(std::weak_ptr<class UDPSession> _UDPSession);
	~UDPRecvOverlapped() {}

	void Execute(BOOL Result, DWORD _ByteSize) override;

	void* GetBuffer() {
		return Buffer;
	}

	inline LPDWORD GetBufferLength() 
	{
		return &numberofBytes_;
	}

	inline LPWSABUF GetWSABuffer() {
		return &wsaBuffer;
	}

private:
	std::weak_ptr<class UDPSession> UDPSession_;
	// ����� ��ġ�� �ȵ˴ϴ�.
	// ���� �����Ͱ� ���� �ϴϱ�.
	char Buffer[1024];
	WSABUF wsaBuffer;
	DWORD numberofBytes_;
};


class UDPSendOverlapped
	: public GameServerOverlapped
{
public:
	UDPSendOverlapped();
	~UDPSendOverlapped() {}

	void SetUDPSession(std::weak_ptr<class UDPSession> _UDPSession)
	{
		UDPSession_ = _UDPSession;
	}

	void* GetBuffer() 
	{
		return Buffer;
	}

	inline LPDWORD GetBufferLength()
	{
		return &numberofBytes_;
	}

	inline LPWSABUF GetWSABuffer() {
		return &wsaBuffer;
	}

	void Execute(BOOL Result, DWORD _ByteSize) override;

	void CopyFrom(const std::vector<unsigned char>& _fromData);

private:
	std::weak_ptr<class UDPSession> UDPSession_;
	// ����� ��ġ�� �ȵ˴ϴ�.
	// ���� �����Ͱ� ���� �ϴϱ�.
	char Buffer[1024];
	WSABUF wsaBuffer;
	DWORD numberofBytes_;
};