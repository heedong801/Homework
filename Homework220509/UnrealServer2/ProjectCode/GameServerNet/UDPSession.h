#pragma once
#include <GameServerBase/GameServerObjectBase.h>
#include <GameServerBase/GameServerObjectPool.h>
#include "IPEndPoint.h"

// UDPSession�� �����ʰ� ����?

// UDPSession�� �׳� ����⸸ �ϸ� �������� �ְ� 
// �״�� ���� 1�ּҿ� ������ �Ұ��ε���.

// IOCP�� ������� �ʴ°��� �ƴϱ� ������.
class UDPSession : public GameServerObjectBase
{
private:
	friend class UDPRecvOverlapped;
	friend class UDPSendOverlapped;

	// �ʴ�1���� ���� �� ����־� ������
	// ��밡 �����̾�� 
	// tcp�� ���ִ� �ͺ��� �츮�� �߸��� Ȯ��?

public:
	UDPSession();
	~UDPSession();

	bool Initialize(const IPEndPoint& _Endpoint, std::function<void(std::shared_ptr<UDPSession>, const std::vector<unsigned char>&, IPEndPoint&)> _CallBack);

	bool Recv();
	bool Send(const std::vector<unsigned char>& sendBytes, const IPEndPoint& _remoteEndPoint);

	bool BindQueue(const GameServerQueue& _jobQueue);

	// ���ú� �������常 �� ȣ���Ҽ� �ִ�.
private:
	void OnSendComplate(UDPSendOverlapped* _SendOverlapped);

	bool OnRecv(const char* _buffer, DWORD _numberofBytes);

	static void OnCallBack(std::weak_ptr<UDPSession> _weakSession, BOOL _Result, DWORD numberrOfBytes, LPOVERLAPPED _lpOverlapped);

	IPEndPoint LocalEndpoint_;

	SOCKADDR_IN remoteAddr_;

	SOCKET SessionSocket_;

	DWORD flag_;
	int AddrSize_;

	UDPRecvOverlapped* RecvOveralpped;
	GameServerObjectPool<UDPSendOverlapped> SendPool_;


	// ���� �ּҸ� �̹� �˾�.
	// UDP�� ���ʿ� ���ε��� �۾��� ����
	// ����θ� �׳� �׶����ʹ� ������ó�� ���� ��Ŷ�� �״�� �������̱� ������
	// ������ udp�� ���ʿ� ������
	// tcp�̹� �ּҰ� ���ε� �Ǿ��ֱ� ������ �ּҸ� �����ʿ䰡 ����.
	std::function<void(std::shared_ptr<UDPSession>, const std::vector<unsigned char>&, IPEndPoint&)> RecvCallBack_;
};

