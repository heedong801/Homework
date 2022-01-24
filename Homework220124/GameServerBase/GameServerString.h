#pragma once

// 용도 : 
// 분류 :
// 첨언 : 
class GameServerString
{
private: // Member Var

public: // Default
	GameServerString();
	~GameServerString();

	GameServerString(const GameServerString& _Other) = delete;
	GameServerString(GameServerString&& _Other) noexcept;

protected:
	GameServerString& operator=(const GameServerString& _Other) = delete;
	GameServerString& operator=(GameServerString&& _Other) = delete;

private:

public: // Member Function
};

