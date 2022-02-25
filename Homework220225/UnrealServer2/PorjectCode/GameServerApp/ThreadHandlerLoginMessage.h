#pragma once
#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerLoginMessage final
	: public std::enable_shared_from_this<ThreadHandlerLoginMessage>
{
private: // Member Var
	// ��Ŷ�� ������
	std::shared_ptr<TCPSession> TCPSession_;

	// �� ��Ŷ
	std::shared_ptr<LoginMessage> LoginMessage_;

	// ó���� ���
	LoginResultMessage LoginResult_;

public: // Default
	ThreadHandlerLoginMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<LoginMessage> _LogineMessage);
	~ThreadHandlerLoginMessage();
	ThreadHandlerLoginMessage(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage(ThreadHandlerLoginMessage&& _Other) noexcept = delete;

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Start();

private:
	// �� �޼����� ó���ϴ� �ܰ�
	void DBCheck();

	// �� �޼����� ó���� �������� ����Ǵ� �Լ�
	void ResultSend();



protected:
	ThreadHandlerLoginMessage& operator=(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage& operator=(ThreadHandlerLoginMessage&& _Other) = delete;

};

