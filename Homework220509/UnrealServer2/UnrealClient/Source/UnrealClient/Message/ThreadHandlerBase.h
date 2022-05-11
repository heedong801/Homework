#pragma once
#include "CoreMinimal.h"
#include <memory>
#include <functional>
#include "Messages.h"
#include "ServerToClient.h"
#include "ServerAndClient.h"
#include "ClientToServer.h"

template<class MessageType>
class ThreadHandlerBase : public std::enable_shared_from_this<ThreadHandlerBase<MessageType>>
{
public:
	// message std::shared_ptr<T> req
	ThreadHandlerBase() {}

	virtual ~ThreadHandlerBase() {}

	void Init(
		std::shared_ptr<MessageType> _Message,
		class UClientGameInstance* _Inst, 
		class UWorld* _World
	)
	{
		Inst_ = _Inst;
		Message_ = _Message;
		World_ = _World;
	}

	virtual void Start() = 0;

protected:
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<MessageType> Message_;
};


