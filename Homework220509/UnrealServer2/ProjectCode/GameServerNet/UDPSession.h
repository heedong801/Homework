#pragma once
#include <GameServerBase/GameServerObjectBase.h>
#include <GameServerBase/GameServerObjectPool.h>
#include "IPEndPoint.h"

// UDPSession는 리스너가 없죠?

// UDPSession은 그냥 만들기만 하면 받을수도 있고 
// 그대신 보통 1주소와 연결을 할것인데ㅐ.

// IOCP를 사용하지 않는것은 아니기 때문에.
class UDPSession : public GameServerObjectBase
{
private:
	friend class UDPRecvOverlapped;
	friend class UDPSendOverlapped;

	// 초당1번씩 내가 너 살아있어 보내고
	// 상대가 릴레이어블 
	// tcp가 해주는 것보다 우리가 잘만들 확률?

public:
	UDPSession();
	~UDPSession();

	bool Initialize(const IPEndPoint& _Endpoint, std::function<void(std::shared_ptr<UDPSession>, const std::vector<unsigned char>&, IPEndPoint&)> _CallBack);

	bool Recv();
	bool Send(const std::vector<unsigned char>& sendBytes, const IPEndPoint& _remoteEndPoint);

	bool BindQueue(const GameServerQueue& _jobQueue);

	// 리시브 오버랩드만 날 호출할수 있다.
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


	// 상대방 주소를 이미 알아.
	// UDP는 애초에 바인드라는 작업이 없고
	// 열어두면 그냥 그때부터는 열린문처럼 오는 패킷을 그대로 받을뿐이기 때문에
	// 상대방의 udp는 애초에 날릴때
	// tcp이미 주소가 바인드 되어있기 때문에 주소를 받을필요가 없다.
	std::function<void(std::shared_ptr<UDPSession>, const std::vector<unsigned char>&, IPEndPoint&)> RecvCallBack_;
};

