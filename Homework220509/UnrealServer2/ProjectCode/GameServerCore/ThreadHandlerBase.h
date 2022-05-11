#pragma once
#include <memory>
#include <functional>
#include <GameServerNet/TCPSession.h>
#include <GameServerNet/UDPSession.h>
#include <GameServerMessage/Messages.h>
#include "GameServerSectionManager.h"
#include "DBQueue.h"
#include "NetQueue.h"

template<class MessageType, class SessionType = class TCPSession>
class ThreadHandlerBase : public std::enable_shared_from_this<ThreadHandlerBase<MessageType, SessionType>>
{
public:
	// message std::shared_ptr<T> req
	ThreadHandlerBase() {}

	virtual ~ThreadHandlerBase() {}

	void Init(
		std::shared_ptr<MessageType> _Message,
		std::shared_ptr<SessionType> _Session
	) 
	{
		Message_ = _Message;
		Session_ = _Session;
	}

	virtual void Start() = 0;

	template<typename ChildThreadHandler>
	void DBWork(void(ChildThreadHandler::* _ChildFunction)())
	{
		DBQueue::Queue(std::bind(_ChildFunction, std::dynamic_pointer_cast<ChildThreadHandler>(this->shared_from_this())));
	}

	template<typename ChildThreadHandler>
	void NetWork(void(ChildThreadHandler::* _ChildFunction)())
	{
		NetQueue::Queue(std::bind(_ChildFunction, std::dynamic_pointer_cast<ChildThreadHandler>(this->shared_from_this())));
	}

	template<typename ChildThreadHandler>
	void SectionWork(uint64_t _ThreadIndex, void(ChildThreadHandler::* _ChildFunction)())
	{
		GameServerSectionManager::GetInst()->MessagePost(_ThreadIndex, std::bind(_ChildFunction, std::dynamic_pointer_cast<ChildThreadHandler>(this->shared_from_this())));
	}

	void ActorWork(uint64_t _ThreadIndex, uint64_t _SectionIndex, uint64_t _ActorIndex, std::shared_ptr<GameServerMessage> _Message)
	{
		GameServerSectionManager::GetInst()->ActorPost(_ThreadIndex, _SectionIndex, _ActorIndex, _Message);
	}

	void ActorPointWork(uint64_t _ThreadIndex, uint64_t _SectionIndex, uint64_t _ActorIndex, const IPEndPoint& _EndPoint, std::shared_ptr<GameServerMessage> _Message)
	{
		GameServerSectionManager::GetInst()->ActorPointPost(_ThreadIndex, _SectionIndex, _ActorIndex, _EndPoint, _Message);
	}


protected:
	std::shared_ptr<MessageType> Message_;
	std::shared_ptr<SessionType> Session_;
};


