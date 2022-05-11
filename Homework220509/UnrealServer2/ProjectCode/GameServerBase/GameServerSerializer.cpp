#include "PreCompile.h"
#include "GameServerSerializer.h"


void GameServerSerializer::Read(void* Data, unsigned int _Size)
{
	memcpy_s(Data, _Size, &Data_[Offset_], _Size);
	Offset_ += _Size;
}

void GameServerSerializer::Write(const void* Data, unsigned int _Size)
{
	memcpy_s(&Data_[Offset_], _Size, Data, _Size);
	Offset_ += _Size;
}

void GameServerSerializer::operator<<(const int _Value)
{
	Write(&_Value, sizeof(int));
}

void GameServerSerializer::operator<<(const float _Value)
{
	Write(&_Value, sizeof(float));
}

void GameServerSerializer::operator<<(const std::string& _Value)
{
	operator<<(static_cast<int>(_Value.size()));
	Write(reinterpret_cast<const void*>(&_Value[0]), static_cast<unsigned int>(_Value.size()));
}

void GameServerSerializer::operator<<(const unsigned int _Value)
{
	Write(&_Value, sizeof(unsigned int));
}

void GameServerSerializer::operator<<(const uint64_t& _Value)
{
	Write(&_Value, sizeof(uint64_t));
}

void GameServerSerializer::operator<<(const FVector4& _Value)
{
	Write(&_Value, sizeof(FVector4));
}


void GameServerSerializer::operator>>(std::string& _Value)
{
	int Size;
	operator>>(Size);
	_Value.resize(Size);
	Read(&_Value[0], Size);
}

void GameServerSerializer::operator>>(int& _Value)
{
	Read(&_Value, sizeof(int));
}

void GameServerSerializer::operator>>(unsigned int& _Value)
{
	Read(&_Value, sizeof(unsigned int));
}

void GameServerSerializer::operator>>(float& _Value) 
{
	Read(&_Value, sizeof(float));
}

void GameServerSerializer::operator>>(FVector4& _Value)
{
	Read(&_Value, sizeof(FVector4));
}

void GameServerSerializer::operator>>(uint64_t& _Value)
{
	Read(&_Value, sizeof(uint64_t));
}

GameServerSerializer::GameServerSerializer()
{
	Offset_ = 0;
	Data_.resize(1024);
}

GameServerSerializer::GameServerSerializer(const std::vector<unsigned char>& _Data)
	: Offset_(0),
	Data_(_Data)
{

}