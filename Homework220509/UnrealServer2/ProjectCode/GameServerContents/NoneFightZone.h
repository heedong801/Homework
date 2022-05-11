#pragma once
#include <GameServerCore\GameServerSection.h>

//class MapMovePoint 
//{
//public:
//	FVector4 Pos;
//	FVector4 Scale;
//	GameServerSection* Section;
//};

// Ό³Έν :
class NoneFightZone : public GameServerSection
{
public:
	// constrcuter destructer
	NoneFightZone();
	~NoneFightZone();

	// delete Function
	NoneFightZone(const NoneFightZone& _Other) = delete;
	NoneFightZone(NoneFightZone&& _Other) noexcept = delete;
	NoneFightZone& operator=(const NoneFightZone& _Other) = delete;
	NoneFightZone& operator=(NoneFightZone&& _Other) noexcept = delete;

protected:

private:
	void UserUpdate();

	bool Init() override;
};

