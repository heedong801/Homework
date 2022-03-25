#pragma once
#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>

// 용도 : 
// 분류 :
// 첨언 : 
class ThreadHandlerJoinMessage	final
	: public std::enable_shared_from_this<ThreadHandlerJoinMessage>
{
private: // Member Var
	// 패킷을 보낸놈
	std::shared_ptr<TCPSession> TCPSession_;

	// 온 패킷
	std::shared_ptr<JoinMessage> JoinMessage_;

	// 처리한 결과
	JoinResultMessage JoinResult_;

public: // Default
	ThreadHandlerJoinMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<JoinMessage> _JoinMessage_);
	~ThreadHandlerJoinMessage();
	ThreadHandlerJoinMessage(const ThreadHandlerJoinMessage& _Other) = delete;
	ThreadHandlerJoinMessage(ThreadHandlerJoinMessage&& _Other) noexcept = delete;

	// 이 메세지를 처음 받았을때 실행하는 함수
	void Start();

public:


private:
	// 이 메세지를 처리하는 단계
	void DBCheck();

	// 이 메세지가 처리가 끝났을때 실행되는 함수
	void ResultSend();

protected:
	ThreadHandlerJoinMessage& operator=(const ThreadHandlerJoinMessage& _Other) = delete;
	ThreadHandlerJoinMessage& operator=(ThreadHandlerJoinMessage&& _Other) = delete;

};

