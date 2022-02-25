#pragma once
#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>

// 그 세션도 여기서 받는다.
class ThreadHandlerChatMessage final
	: public std::enable_shared_from_this<ThreadHandlerChatMessage>
{
private: // Member Var
	std::shared_ptr<TCPSession> TCPSession_;
	std::shared_ptr<ChatMessage> Message_;

public: // Default
	ThreadHandlerChatMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<ChatMessage> _Message);
	~ThreadHandlerChatMessage();
	ThreadHandlerChatMessage(const ThreadHandlerChatMessage& _Other) = delete;
	ThreadHandlerChatMessage(ThreadHandlerChatMessage&& _Other) noexcept = delete;
	ThreadHandlerChatMessage& operator=(ThreadHandlerChatMessage&& _Other) = delete;
	ThreadHandlerChatMessage& operator=(const ThreadHandlerChatMessage& _Other) = delete;

	void Start();

private:

protected:

};