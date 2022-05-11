#pragma once
#include "GameServerSerializer.h"

struct FCharacterInfo
{
public:
	int			Index;
	std::string NickName;
	int			UserIndex;
	float		Att;
	float		Hp;
	int			LastSectionID;
	float		SectionX;
	float		SectionY;
	float		SectionZ;

public:
	int GetDataSize() 
	{
		return (4 * 8) + 4 + static_cast<int>(NickName.size());
	}

	void Serialize(GameServerSerializer& _Ser) 
	{
		_Ser <<Index;
		_Ser << NickName;
		_Ser << UserIndex;
		_Ser << Att;
		_Ser << Hp;
		_Ser << LastSectionID;
		_Ser << SectionX;
		_Ser << SectionY;
		_Ser << SectionZ;
	}

	void DeSerialize(GameServerSerializer& _Ser)
	{
		_Ser >> Index;
		_Ser >> NickName;
		_Ser >> UserIndex;
		_Ser >> Att;
		_Ser >> Hp;
		_Ser >> LastSectionID;
		_Ser >> SectionX;
		_Ser >> SectionY;
		_Ser >> SectionZ;
	}


	FCharacterInfo() {
	}
	~FCharacterInfo() {
	}
};

struct FPlayerUpdateData
{
	uint64_t ObjectIndex;
	uint64_t ThreadIndex;
	uint64_t SectionIndex;
	FVector4 Dir;
	FVector4 Pos;
	FVector4 Rot;
	int State;

	template<typename EnumType>
	EnumType GetState()
	{
		return static_cast<EnumType>(State);
	}

	template<typename EnumType>
	void SetState(EnumType _Type)
	{
		State = static_cast<int>(_Type);
	}


	int GetDataSize()
	{
		return sizeof(FPlayerUpdateData);
	}

	void Serialize(GameServerSerializer& _Ser)
	{
		_Ser << ObjectIndex;
		_Ser << ThreadIndex;
		_Ser << SectionIndex;
		_Ser << Dir;
		_Ser << Pos;
		_Ser << Rot;
		_Ser << State;
	}

	void DeSerialize(GameServerSerializer& _Ser)
	{
		_Ser >> ObjectIndex;
		_Ser >> ThreadIndex;
		_Ser >> SectionIndex;
		_Ser >> Dir;
		_Ser >> Pos;
		_Ser >> Rot;
		_Ser >> State;
	}


	FPlayerUpdateData() {
	}
	~FPlayerUpdateData() {
	}
};


struct FMonsterUpdateData
{
	uint64_t ObjectIndex;
	uint64_t ThreadIndex;
	uint64_t SectionIndex;
	FVector4 Dir;
	FVector4 Pos;
	FVector4 Rot;
	float DeltaTime;
	int State;

	template<typename EnumType>
	EnumType GetState()
	{
		return static_cast<EnumType>(State);
	}

	template<typename EnumType>
	void SetState(EnumType _Type)
	{
		State = static_cast<int>(_Type);
	}


	int GetDataSize()
	{
		return sizeof(FMonsterUpdateData);
	}

	void Serialize(GameServerSerializer& _Ser)
	{
		_Ser << ObjectIndex;
		_Ser << ThreadIndex;
		_Ser << SectionIndex;
		_Ser << Dir;
		_Ser << Pos;
		_Ser << Rot;
		_Ser << State;
	}

	void DeSerialize(GameServerSerializer& _Ser)
	{
		_Ser >> ObjectIndex;
		_Ser >> ThreadIndex;
		_Ser >> SectionIndex;
		_Ser >> Dir;
		_Ser >> Pos;
		_Ser >> Rot;
		_Ser >> State;
	}


	FMonsterUpdateData() {
	}
	~FMonsterUpdateData() {
	}
};