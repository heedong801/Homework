#pragma once
#include <GameServerCore\GameServerSection.h>
#include "Monster.h"
// Ό³Έν :
class FightZone : public GameServerSection
{
	// std::map<int, std::string>
public:
	// constrcuter destructer
	FightZone();
	~FightZone();

	// delete Function
	FightZone(const FightZone& _Other) = delete;
	FightZone(FightZone&& _Other) noexcept = delete;
	FightZone& operator=(const FightZone& _Other) = delete;
	FightZone& operator=(FightZone&& _Other) noexcept = delete;

protected:
	int MaxCount;
	// MonstersUpdateData Packet;

private:
	void UserUpdate();
	bool Init() override;
};

