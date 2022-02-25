#pragma once
#include "IPEndPoint.h"
#include "TypeDefine.h"
#include <deque>
#include <GameServerBase/GameServerObjectPool.h>

// tcp리스너란
// 어떤 주소값을 기반으로 접속자를 받아주는 기능을 수행하는 클래스
// 주소값 너무너무 많이 쓰이고 예외처리를 해줄께 많으니까.
// 주소값이라는 개념자체를 다시 클래스화 시킨겁니다.

class TCPSession;
class GameServerQueue;
class AcceptExOverlapped;
class TCPListener : public GameServerObjectBase
{
	friend TCPSession;


public: // Default
	TCPListener();
	~TCPListener();

	TCPListener(const TCPListener& _Other) = delete;
	TCPListener(TCPListener&& _Other) noexcept;

	// 리스닝 하기전 준비를 하는 함수
	bool Initialize(const IPEndPoint& _EndPoint, const std::function<void(std::shared_ptr<TCPSession>)>& CallBack_);

	bool BindQueue(GameServerQueue& _JobQueue);

	bool StartAccept(int _BackLog);

	void Close();

	void BroadCast(std::vector<unsigned char> _Data, std::shared_ptr<TCPSession> _Ignore);

protected:
	TCPListener& operator=(const TCPListener& _Other) = delete;
	TCPListener& operator=(TCPListener&& _Other) = delete;

	// 1000명까지 받는서버인데.
	// 시작부터 1000개 만들어 놓고 시작하면 안될까?
	// 사실 그대로 되기는 하는데.
	void AsyncAccept();

private: // Member Function
	SOCKET ListenSocket_;

	IPEndPoint ListenEndPoint_;

	// GameServerQueue 내부의 iocp에 
	// ListenSocket_ 소켓을 등록시키고 iocp를 이용하여
	// 접속자 이벤트를 처리한다.
	GameServerQueue* JobQueue_;

	// 특별한 일을 하게 해주고 싶어.
	// 접속자 니가 접속자한테 해주고 싶은 일이 있으면
	// 이 콜백을 세팅하면 된다.
	std::function<void(std::shared_ptr<TCPSession>)> AcceptCallBack_;


	// 내가 미리 세션을 n개 만듭니다.
	// AccpetEx를 호출하면 호출한 횟수만큼 백로그가 생기는 시스템입니다.
	// 벡터와 리스트의 
	// 100개 이하의 중간크기에서 벡터와 리스트의 장단점을 다 취하고 싶을때
	// 사용하는 자료구조입니다.

	// iocp에 맡겨져있는 AcceptExOverlapped의 메모리들.
	GameServerObjectFindPool<AcceptExOverlapped> IocpAcceptExOverlappedPool_;
	GameServerObjectPool<AcceptExOverlapped> AcceptExOverlappedPool_;

	std::mutex connectPoolLock_;
	std::deque<std::shared_ptr<TCPSession>> connectionPool_;

	// 전체한테 뭔가 날릴때.
	std::mutex connectsLock_;
	std::unordered_map<__int64, std::shared_ptr<TCPSession>> connections_;


	// 이걸 사용하는 사람이 접속자한테 어떤 
	// 특별한 일을 할지 우리는 알수 있을까요?

	void CloseSession(PtrSTCPSession _Session);

	void OnAccept(BOOL, DWORD, LPOVERLAPPED);
};

