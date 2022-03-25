#pragma once
#include "EngineMinimal.h"
#include <memory>
#include <map>
#include <functional>
#include "Messages.h"
#include "Dispatcher.generated.h"

// OWNER 이 패킷을 받은 세션
using  MessageHandler = std::function<void(std::shared_ptr<GameServerMessage>)>;

// 대부분의 서버의 처리란
// 어떤 패킷을 받았어
// 그 패킷을 처리해야 하는데.
// 아이템 획득 패킷을 받았어
// 1. 아이템정보db로 갑니다.
//     이 아이템이 유요한 아이템이야? 
//     해킹하거나 뭐 이런 아이템 아니야?

// 2. 캐릭터db로 갑니다.
//     이 유요한 아이템을 캐릭터에게 넣어주자.
//     => 캐릭터의 정보를 수정한다.

// 3. 캐릭터에게 다시 잘처리 됐어로
//    보냅니다.

// 이 메세지 디스패처의 역할은
//    이렇게 다양한 쓰레드를 넘나들고
//    많은 단계를 거쳐야하는 일을
//    하나의 클래스에서 확인할수 있게 해주는 용도.

// 첨언 : 
UCLASS(ClassGroup = (Custom))
class UDispatcher : public UObject
{
	GENERATED_BODY()

private: // Member Var
	std::map<unsigned int, MessageHandler> Handlers_;

public: // Default
	UDispatcher() {}
	~UDispatcher() {}

	bool AddHandler(MessageId Id, const MessageHandler _Handler)
	{
		return AddHandler(static_cast<unsigned int>(Id), _Handler);
	}

	bool AddHandler(unsigned int Id, const MessageHandler _Handler)
	{
		Handlers_.insert(std::make_pair(Id, _Handler));

		return true;
	}

	// int* TMap.find

	bool GetHandler(MessageId Id, MessageHandler& _Handler) 
	{
		return GetHandler(static_cast<unsigned int>(Id), _Handler);
	}

	bool GetHandler(uint32_t Id, MessageHandler& _Handler) 
	{
		auto FindData = Handlers_.find(Id);

		if (Handlers_.end() == FindData)
		{
			return false;
		}

		// _Handler = *FindData;

		_Handler = FindData->second;

		return true;
	}


public: // Member Function
};

