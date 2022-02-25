#pragma once
#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>

// 그 세션도 여기서 받는다.
class ThreadHandlerLoginMessage final
	: public std::enable_shared_from_this<ThreadHandlerLoginMessage>
{
private: // Member Var
	// 패킷을 보낸놈
	std::shared_ptr<TCPSession> TCPSession_;

	// 온 패킷
	std::shared_ptr<LoginMessage> LoginMessage_;

	// 처리한 결과
	LoginResultMessage LoginResult_;

public: // Default
	ThreadHandlerLoginMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<LoginMessage> _LogineMessage);
	~ThreadHandlerLoginMessage();
	ThreadHandlerLoginMessage(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage(ThreadHandlerLoginMessage&& _Other) noexcept = delete;

	// 이 메세지를 처음 받았을때 실행하는 함수
	void Start();

private:
	// 이 메세지를 처리하는 단계
	void DBCheck();

	// 이 메세지가 처리가 끝났을때 실행되는 함수
	void ResultSend();



protected:
	ThreadHandlerLoginMessage& operator=(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage& operator=(ThreadHandlerLoginMessage&& _Other) = delete;

};

