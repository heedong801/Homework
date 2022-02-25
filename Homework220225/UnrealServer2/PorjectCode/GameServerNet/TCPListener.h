#pragma once
#include "IPEndPoint.h"
#include "TypeDefine.h"
#include <deque>
#include <GameServerBase/GameServerObjectPool.h>

// tcp�����ʶ�
// � �ּҰ��� ������� �����ڸ� �޾��ִ� ����� �����ϴ� Ŭ����
// �ּҰ� �ʹ��ʹ� ���� ���̰� ����ó���� ���ٲ� �����ϱ�.
// �ּҰ��̶�� ������ü�� �ٽ� Ŭ����ȭ ��Ų�̴ϴ�.

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

	// ������ �ϱ��� �غ� �ϴ� �Լ�
	bool Initialize(const IPEndPoint& _EndPoint, const std::function<void(std::shared_ptr<TCPSession>)>& CallBack_);

	bool BindQueue(GameServerQueue& _JobQueue);

	bool StartAccept(int _BackLog);

	void Close();

	void BroadCast(std::vector<unsigned char> _Data, std::shared_ptr<TCPSession> _Ignore);

protected:
	TCPListener& operator=(const TCPListener& _Other) = delete;
	TCPListener& operator=(TCPListener&& _Other) = delete;

	// 1000����� �޴¼����ε�.
	// ���ۺ��� 1000�� ����� ���� �����ϸ� �ȵɱ�?
	// ��� �״�� �Ǳ�� �ϴµ�.
	void AsyncAccept();

private: // Member Function
	SOCKET ListenSocket_;

	IPEndPoint ListenEndPoint_;

	// GameServerQueue ������ iocp�� 
	// ListenSocket_ ������ ��Ͻ�Ű�� iocp�� �̿��Ͽ�
	// ������ �̺�Ʈ�� ó���Ѵ�.
	GameServerQueue* JobQueue_;

	// Ư���� ���� �ϰ� ���ְ� �;�.
	// ������ �ϰ� ���������� ���ְ� ���� ���� ������
	// �� �ݹ��� �����ϸ� �ȴ�.
	std::function<void(std::shared_ptr<TCPSession>)> AcceptCallBack_;


	// ���� �̸� ������ n�� ����ϴ�.
	// AccpetEx�� ȣ���ϸ� ȣ���� Ƚ����ŭ ��αװ� ����� �ý����Դϴ�.
	// ���Ϳ� ����Ʈ�� 
	// 100�� ������ �߰�ũ�⿡�� ���Ϳ� ����Ʈ�� ������� �� ���ϰ� ������
	// ����ϴ� �ڷᱸ���Դϴ�.

	// iocp�� �ð����ִ� AcceptExOverlapped�� �޸𸮵�.
	GameServerObjectFindPool<AcceptExOverlapped> IocpAcceptExOverlappedPool_;
	GameServerObjectPool<AcceptExOverlapped> AcceptExOverlappedPool_;

	std::mutex connectPoolLock_;
	std::deque<std::shared_ptr<TCPSession>> connectionPool_;

	// ��ü���� ���� ������.
	std::mutex connectsLock_;
	std::unordered_map<__int64, std::shared_ptr<TCPSession>> connections_;


	// �̰� ����ϴ� ����� ���������� � 
	// Ư���� ���� ���� �츮�� �˼� �������?

	void CloseSession(PtrSTCPSession _Session);

	void OnAccept(BOOL, DWORD, LPOVERLAPPED);
};

