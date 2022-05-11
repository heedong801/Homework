#pragma once

// 용도 : 
// 분류 :
// 첨언 : 
class GameServerUnique
{
private: // Member Var
	static std::atomic<uint64_t> UniqueId;

public:
	static uint64_t GetNextUniqueId();

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

