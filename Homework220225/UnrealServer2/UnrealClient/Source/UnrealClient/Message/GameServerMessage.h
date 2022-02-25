#pragma once
#include "MessageIdEnum.h"
#include "ContentsEnums.h"

#include "GameServerSerializer.h"

enum class EGameServerCode
{
	OK,
	LoginError,
	MAX,
};

class GameServerMessage
{
private:
	MessageId Id_;
	unsigned int Size_;

public:
	MessageId GetId()
	{
		return Id_;
	}

public:
	GameServerMessage() = delete;

	GameServerMessage(MessageId _Type)
		: Id_(_Type),
		Size_(-1)
	{

	}

	virtual ~GameServerMessage() {}

	virtual int SizeCheck() = 0
	{
		return -1;
	}

	unsigned int DataSizeCheck(const std::string& _Value)
	{
		return 4 + static_cast<unsigned int>(_Value.size());
	}

	template<typename Type>
	unsigned int DataSizeCheck(Type _Value)
	{
		return sizeof(_Value);
	}

	virtual void Serialize(GameServerSerializer& _Serializer)
	{
		_Serializer << static_cast<int>(Id_);
		_Serializer << SizeCheck();
	}

	virtual void DeSerialize(GameServerSerializer& _Serializer)
	{
		int Type;
		_Serializer >> Type;
		Id_ = static_cast<MessageId>(Type);
		_Serializer >> Size_;
	}
};

