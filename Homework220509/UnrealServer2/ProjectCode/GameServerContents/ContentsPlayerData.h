#pragma once
#include "ContentsStructure.h"
#include "UserTable.h"
#include <GameServerBase\GameServerObjectBase.h>


// �̰ͱ��� ������ �ִٸ� �̳༮�� ��¥ �÷��� �ϴ�������°�.
// ���� :
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

