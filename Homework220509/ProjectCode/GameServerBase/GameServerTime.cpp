#include "PreCompile.h"
#include "GameServerTime.h"

GameServerTime::GameServerTime() 
{
}

GameServerTime::~GameServerTime() 
{
}



void GameServerTime::Reset()
{
	Current_ = Timer_.now();
	Prev_ = Timer_.now();
}

float GameServerTime::Update()
{
	Current_ = Timer_.now();
	DoubleDeltaTime = std::chrono::duration<double>(Current_ - Prev_).count();
	Prev_ = Current_;

	DeltaTime = static_cast<float>(DoubleDeltaTime);
	return DeltaTime;
}