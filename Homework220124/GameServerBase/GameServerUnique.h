#pragma once

// 용도 : 
// 분류 :
// 첨언 : 
class GameServerUnique
{
private: // Member Var
	static std::atomic<__int64> UniqueId;

public:
	static __int64 GetNextUniqueId();

private: // Default
	GameServerUnique();
	~GameServerUnique();

	GameServerUnique(const GameServerUnique& _Other) = delete;
	GameServerUnique(GameServerUnique&& _Other) noexcept;

protected:
	GameServerUnique& operator=(const GameServerUnique& _Other) = delete;
	GameServerUnique& operator=(GameServerUnique&& _Other) = delete;

private:

public: // Member Function
};

