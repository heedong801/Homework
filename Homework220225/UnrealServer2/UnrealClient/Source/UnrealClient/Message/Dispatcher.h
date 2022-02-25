#pragma once
#include "EngineMinimal.h"
#include <memory>
#include <functional>
#include "Messages.h"

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
class Dispatcher final
{
private: // Member Var
	TMap<unsigned int, MessageHandler> Handlers_;

public: // Default
	Dispatcher() {}
	~Dispatcher() {}

	bool AddHandler(MessageId Id, const MessageHandler& _Handler)
	{
		return AddHandler(static_cast<unsigned int>(Id), _Handler);
	}

	bool AddHandler(unsigned int Id, const MessageHandler& _Handler)
	{
		Handlers_.Add(Id, _Handler);

		return true;
	}

	// int* TMap.find

	bool GetHandler(MessageId Id, MessageHandler& _Handler) 
	{
		return GetHandler(static_cast<unsigned int>(Id), _Handler);
	}

	bool GetHandler(uint32_t Id, MessageHandler& _Handler) 
	{
		auto FindData = Handlers_.Find(Id);

		if (nullptr == FindData)
		{
			return false;
		}

		_Handler = *FindData;

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

