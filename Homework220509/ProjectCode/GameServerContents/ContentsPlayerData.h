#pragma once
#include "ContentsStructure.h"
#include "UserTable.h"
#include <GameServerBase\GameServerObjectBase.h>


// 이것까지 가지고 있다면 이녀석은 진짜 플레이 하던유저라는것.
// 설명 :
class Player;
class ContentsPlayerData : public GameServerObjectBase
{

public:
	Player* ConnectPlayer;

	// constrcuter destructer
	ContentsPlayerData() {}
	~ContentsPlayerData() {}

	// delete Function
	ContentsPlayerData(const ContentsPlayerData& _Other) = delete;
	ContentsPlayerData(ContentsPlayerData&& _Other) noexcept = delete;
	ContentsPlayerData& operator=(const ContentsPlayerData& _Other) = delete;
	ContentsPlayerData& operator=(ContentsPlayerData&& _Other) noexcept = delete;

protected:

private:

};

