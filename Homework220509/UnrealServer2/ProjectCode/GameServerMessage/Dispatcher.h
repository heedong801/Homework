#pragma once
#include <memory>
#include <functional>
#include "Messages.h"
#include "GameServerNet/TCPSession.h"

// OWNER 이 패킷을 받은 세션
template<class OWNER>
using  MessageHandler = std::function<void(std::shared_ptr<OWNER>, std::shared_ptr<GameServerMessage>)>;

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
template<class OWNER>
class Dispatcher final
{
private: // Member Var
	std::unordered_map<uint32_t, MessageHandler<OWNER>> Handlers_;

public: // Default
	Dispatcher() {}
	~Dispatcher() {}

	bool AddHandler(uint32_t Id, const MessageHandler<OWNER> Handler)	{
		auto Result = Handlers_.insert(std::make_pair(Id, Handler));

		return Result.second;
	}

	bool GetHandler(uint32_t Id, MessageHandler<OWNER>& _Handler) 
	{
		auto Iter = Handlers_.find(Id);

		if (Iter == Handlers_.end())
		{
			return false;
		}

		_Handler = Iter->second;

		return true;
	}


	Dispatcher(const Dispatcher& _Other) = delete;
	Dispatcher(Dispatcher&& _Other) noexcept = delete; 

protected:
	Dispatcher& operator=(const Dispatcher& _Other) = delete;
	Dispatcher& operator=(Dispatcher&& _Other) = delete;

private:

public: // Member Function
};

