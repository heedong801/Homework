#pragma once
#include <string>
#include <GameServerBase/GameServerObjectBase.h>

// Ό³Έν :
class GameServerUser : public GameServerObjectBase
{
public:
	std::string ID;

public: 
	// constrcuter destructer
	GameServerUser();
	~GameServerUser();

	// delete Function
	GameServerUser(const GameServerUser& _Other) = delete;
	GameServerUser(GameServerUser&& _Other) noexcept = delete; 
	GameServerUser& operator=(const GameServerUser& _Other) = delete;
	GameServerUser& operator=(GameServerUser&& _Other) noexcept = delete;

protected:

private:

};

