#pragma once
#include <vector>
#include <string>
#include "GameServerMathStruct.h"

class GameServerSerializer
{
private:
	unsigned int Offset_;
	std::vector<unsigned char> Data_;

public:
	const std::vector<unsigned char>& GetData() {
		return Data_;
	}

public:
	// 이걸 그냥
	// 템플릿은 보통 좋은 선택이 아닙니다.
	void operator<<(const std::string& _Value);
	void operator<<(const int _Value);
	void operator<<(const unsigned int _Value);
	void operator<<(const FVector& _Value);

	template<typename T>
	void WriteEnum(const T _Value) 
	{
		Write(reinterpret_cast<const void*>(&_Value), static_cast<unsigned int>(sizeof(T)));
	}

	void operator>>(std::string& _Value);
	void operator>>(int& _Value);
	void operator>>(unsigned int& _Value);
	void operator>>(FVector& _Value);

	template<typename T>
	void ReadEnum(T& _Value)
	{
		Read(reinterpret_cast<void*>(&_Value), static_cast<unsigned int>(sizeof(T)));
	}


	void Write(const void* Data, unsigned int _Size);

	void Read(void* Data, unsigned int _Size);

	GameServerSerializer();
	GameServerSerializer(const std::vector<unsigned char>& _Data);
};