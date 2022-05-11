#include "PreCompile.h"
#include "CharacterTable.h"

//////////////////////////////////////////////////////////////////// 

CharacterTable_SelectNickName::CharacterTable_SelectNickName(std::string _NickName)
	: DBQuery("SELECT Idx, NickName, UserIndex, ATT, HP, LastSectionid, LastSectionPosx, LastSectionPosy, LastSectionPosz FROM userver2.characterinfo WHERE NickName = ? LIMIT 1")
	, NickName(_NickName)
{
}

bool CharacterTable_SelectNickName::DoQuery()
{
	std::unique_ptr<DBStmt> Stmt = DBConnecterPtr->CreateStmt(QueryString);

	Stmt->ParamBindString(NickName);

	std::unique_ptr<DBStmtResult> Result(Stmt->Execute());

	uint64_t Row = Stmt->AffectedRows();

	if (0 >= Row)
	{
		return false;
	}

	Result->Next();

	RowData =
		std::make_shared<CharacterRow>(CharacterRow(
			Result->GetInt(0),
			Result->GetString(1),
			Result->GetInt(2),
			Result->GetFloat(3),
			Result->GetFloat(4),
			Result->GetInt(5),
			Result->GetFloat(6),
			Result->GetFloat(7),
			Result->GetFloat(8)
		));


	return true;
}

/// ///////////////////////// CharacterTable_SelectUserCharacters

CharacterTable_SelectUserCharacters::CharacterTable_SelectUserCharacters(int _Index)
	: DBQuery("SELECT Idx, NickName, UserIndex, ATT, HP, LastSectionid, LastSectionPosx, LastSectionPosy, LastSectionPosz FROM userver2.characterinfo WHERE UserIndex = ?")
	, UserIndex_(_Index)
{
}

bool CharacterTable_SelectUserCharacters::DoQuery()
{
	std::unique_ptr<DBStmt> Stmt = DBConnecterPtr->CreateStmt(QueryString);

	Stmt->ParamBindInt(UserIndex_);

	std::unique_ptr<DBStmtResult> Result(Stmt->Execute());

	uint64_t Row = Result->AffectedRows();
	RowDatas.reserve(Row);


	while (Result->Next())
	{
		RowDatas.push_back(
			std::make_shared<CharacterRow>(CharacterRow(
			Result->GetInt(0),  
			Result->GetString(1), 
			Result->GetInt(2),
			Result->GetFloat(3),
			Result->GetFloat(4),
			Result->GetInt(5),
			Result->GetFloat(6),
			Result->GetFloat(7),
			Result->GetFloat(8)
			)
			)
		);
	}

	return true;
}



/// ///////////////////////// CharacterTable_SelectUserCharacters

CharacterTable_CreateCharacter::CharacterTable_CreateCharacter(std::string _NickName, int _Id)
	: DBQuery("INSERT INTO userver2.characterinfo (NickName, UserIndex) VALUES (?, ?);")
	, NickName(_NickName)
	, Id_(_Id)
{
}

bool CharacterTable_CreateCharacter::DoQuery()
{
	std::unique_ptr<DBStmt> Stmt = DBConnecterPtr->CreateStmt(QueryString);

	Stmt->ParamBindString(NickName);
	Stmt->ParamBindInt(Id_);

	Stmt->Execute();

	uint64_t Row = Stmt->AffectedRows();

	if (0 == Row)
	{
		return false;
	}

	return true;
}

