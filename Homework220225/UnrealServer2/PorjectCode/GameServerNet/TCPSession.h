#pragma once
#include <GameServerBase/GameServerObjectBase.h>
#include <GameServerBase/GameServerObjectPool.h>
#include "IPEndPoint.h"

// 용도 : 
// 분류 :
// 첨언 : 
class TCPListener;
class SendOverlapped;
class RecvOverlapped;
class GameServerQueue;
class AcceptExOverlapped;
class DisconnectOverlapped;
class TCPSession : public GameServerObjectBase
{
	friend TCPListener;
	friend AcceptExOverlapped;
	friend RecvOverlapped;
	friend SendOverlapped;

private: // Member Var
	bool isAcceptBind_;
	__int64 ConnectId_;
	SOCKET SessionSocket_;
	IPEndPoint LocalAddress_;
	IPEndPoint RemoteAddress_;

	// 락이 늘어나겠죠.
	// 모두가 같이 사용한다.
	// 5개의 send overr 
	// 정답 x
	// 모두가 공통적으로 사용하는 Pool

	RecvOverlapped* recvOverlapped_;
	DisconnectOverlapped* disconnectOverlapped_;
	GameServerObjectPool<SendOverlapped> SendPool_;

	std::atomic_bool CallClose_;

	std::function<void(std::shared_ptr<TCPSession>, const std::vector<unsigned char>&)> RecvCallBack_;
	std::function<void(std::shared_ptr<TCPSession>)> CloseCallBack_;

	using CloseCallBack = std::function<void(std::shared_ptr<TCPSession>)>;
	using RecvCallBack = std::function<void(std::shared_ptr<TCPSession>, const std::vector<unsigned char>&)>;



public: // Default
	TCPSession();
	~TCPSession();

	TCPSession(const TCPSession& _Other) = delete;
	TCPSession(TCPSession&& _Other) noexcept;

	SOCKET GetSocket();

	__int64 GetConnectId();

	void UnregisterSession();

	bool Send(const std::vector<unsigned char>& _Buffer);

	void SetCallBack(RecvCallBack _CallBack, CloseCallBack _CloseCallBack);


protected:
	TCPSession& operator=(const TCPSession& _Other) = delete;
	TCPSession& operator=(TCPSession&& _Other) = delete;

private:
	static void OnCallBack(std::weak_ptr<TCPSession> _weakSession, BOOL _Result, DWORD numberrOfBytes, LPOVERLAPPED _lpOverlapped);
	void Close(bool _forceClsoe = false);
	void CloseSocket();
	void OnRecv(const char*, DWORD);

	void OnSendComplete(SendOverlapped* _Send);

	void RecvRequest();
	bool Initialize();
	bool BindQueue(const GameServerQueue& _jobQueue);
	void DisconnectSocket();
	void AcceptBindOn();

};

