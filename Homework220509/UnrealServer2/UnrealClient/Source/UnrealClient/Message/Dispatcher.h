#pragma once
#include "EngineMinimal.h"
#include <memory>
#include <map>
#include <functional>
#include "Messages.h"
#include "MessageIdEnum.h"
#include "Dispatcher.generated.h"

// OWNER �� ��Ŷ�� ���� ����
using  MessageHandler = std::function<void(std::shared_ptr<GameServerMessage>)>;

// ��κ��� ������ ó����
// � ��Ŷ�� �޾Ҿ�
// �� ��Ŷ�� ó���ؾ� �ϴµ�.
// ������ ȹ�� ��Ŷ�� �޾Ҿ�
// 1. ����������db�� ���ϴ�.
//     �� �������� ������ �������̾�? 
//     ��ŷ�ϰų� �� �̷� ������ �ƴϾ�?

// 2. ĳ����db�� ���ϴ�.
//     �� ������ �������� ĳ���Ϳ��� �־�����.
//     => ĳ������ ������ �����Ѵ�.

// 3. ĳ���Ϳ��� �ٽ� ��ó�� �ƾ��
//    �����ϴ�.

// �� �޼��� ����ó�� ������
//    �̷��� �پ��� �����带 �ѳ����
//    ���� �ܰ踦 ���ľ��ϴ� ����
//    �ϳ��� Ŭ�������� Ȯ���Ҽ� �ְ� ���ִ� �뵵.

// ÷�� : 
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

