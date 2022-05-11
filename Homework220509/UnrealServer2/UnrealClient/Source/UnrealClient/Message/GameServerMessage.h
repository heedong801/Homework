#pragma once

#include "GameServerSerializer.h"

class GameServerMessage
{
private:
	uint32_t Id_;
	unsigned int Size_;

public:
	uint32_t GetId()
	{
		return Id_;
	}

	template<typename EnumType>
	EnumType GetId()
	{
		return static_cast<EnumType>(Id_);
	}

public:
	GameServerMessage() = delete;

	GameServerMessage(uint32_t _Type)
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
	unsigned int DataSizeCheck(std::vector<Type>& _Value)
	{
		int Size = 0;
		for (size_t i = 0; i < _Value.size(); i++)
		{
			Size += _Value[i].GetDataSize();
		}
		return Size + 4;
	}

	unsigned int DataSizeCheck(std::vector<int>& _Value)
	{
		int Size = 0;
		Size +=  static_cast<int>(_Value.size()) * 4;
		return Size + 4;
	}

	unsigned int DataSizeCheck(std::vector<std::string>& _Value)
	{
		int Size = 0;
		for (size_t i = 0; i < _Value.size(); i++)
		{
			Size += DataSizeCheck(_Value[i]);
		}
		return Size + 4;
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
		Id_ = static_cast<uint32_t>(Type);
		_Serializer >> Size_;
	}
};

