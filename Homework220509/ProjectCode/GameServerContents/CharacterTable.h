#pragma once
#include <GameServerNet\DBQuery.h>
#include "ContentsStructure.h"

class CharacterRow : public std::enable_shared_from_this<CharacterRow>
{
public:
	union {
		struct 
		{
			int Index;
			std::string NickName;
			int UserIndex;
			float Att;
			float Hp;
			int LastSectionID;
			float SectionX;
			float SectionY;
			float SectionZ;
		};
		FCharacterInfo Info;
	};


public:
	CharacterRow(
		int _Index,
		std::string _NickName,
		int _UserIndex,
		float _Att,
		float _Hp,
		int _LastSectionID,
		float _SectionX,
		float _SectionY,
		float _SectionZ
	) : Index(_Index),
		NickName(_NickName),
		UserIndex(_UserIndex),
		Att(_Att),
		Hp(_Hp),
		LastSectionID(_LastSectionID),
		SectionX(_SectionX),
		SectionY(_SectionY),
		SectionZ(_SectionZ)
	{

	}

	CharacterRow(
		const CharacterRow& _Data
	) : Index(_Data.Index),
		NickName(_Data.NickName),
		UserIndex(_Data.UserIndex),
		Att(_Data.Att),
		Hp(_Data.Hp),
		LastSectionID(_Data.LastSectionID),
		SectionX(_Data.SectionX),
		SectionY(_Data.SectionY),
		SectionZ(_Data.SectionZ)
	{

	}



	CharacterRow(
		const FCharacterInfo& _Data
	) : Info(_Data)
	{

	}

	~CharacterRow() {
	}
};



class CharacterTable_SelectNickName : public DBQuery
{
public:
	std::string NickName;
	std::shared_ptr<CharacterRow> RowData;

	
	FCharacterInfo ConvertInfoCharacter() 
	{
		FCharacterInfo Info;

		Info.Index = RowData->Index;
		Info.NickName = RowData->NickName;
		Info.UserIndex = RowData->UserIndex;
		Info.Att = RowData->Att;
		Info.Hp = RowData->Hp;
		Info.LastSectionID = RowData->LastSectionID;
		Info.SectionX = RowData->SectionX;
		Info.SectionY = RowData->SectionY;
		Info.SectionZ = RowData->SectionZ;
	}
	

public:
	CharacterTable_SelectNickName(std::string _NickName);
	bool DoQuery() override;
};


class CharacterTable_SelectUserCharacters : public DBQuery
{
public:
	std::vector<std::shared_ptr<CharacterRow>> RowDatas;
	int UserIndex_;

public:
	CharacterTable_SelectUserCharacters(int _Idx);

	bool DoQuery() override;
};



class CharacterTable_CreateCharacter : public DBQuery
{
public:
	std::string NickName;
	int Id_;

public:
	CharacterTable_CreateCharacter(std::string _NickName, int _Id);
	bool DoQuery() override;
};

