#pragma once
#include "GameServerObjectBase.h"
#include <string>

// 용도 : 
// 분류 :
// 첨언 : 
class GameServerNameBase : public GameServerObjectBase
{
private: // Member Var
	std::string name_;

public:
	virtual void SetName(const std::string&);

	std::string_view GetNameView();
	std::string GetNameCopy();
	const char* GetNamePtr();

public: // Default
	GameServerNameBase();
	~GameServerNameBase();

	GameServerNameBase(const GameServerNameBase& _Other) = delete;
	GameServerNameBase(GameServerNameBase&& _Other) noexcept;

protected:
	GameServerNameBase& operator=(const GameServerNameBase& _Other) = delete;
	GameServerNameBase& operator=(GameServerNameBase&& _Other) = delete;

private:

public: // Member Function
};

