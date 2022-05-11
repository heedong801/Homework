#pragma once
#include "ContentsStructure.h"
#include "UserTable.h"
#include <GameServerBase\GameServerObjectBase.h>


// Ό³Έν :
class ContentsUserData : public GameServerObjectBase
{

public:
	UserRow Data;
	std::vector<FCharacterInfo> Characters;
	FCharacterInfo SelectData;

	// constrcuter destructer
	ContentsUserData();
	~ContentsUserData();

	// delete Function
	ContentsUserData(const ContentsUserData& _Other) = delete;
	ContentsUserData(ContentsUserData&& _Other) noexcept = delete;
	ContentsUserData& operator=(const ContentsUserData& _Other) = delete;
	ContentsUserData& operator=(ContentsUserData&& _Other) noexcept = delete;

protected:

private:

};

