#pragma once

enum class EGameServerCode
{
	OK,
	FAIL,
	LoginError,
};


enum class EGameObjectType
{
	Player,
	Monster,
	Item,
	Potal,
	MAX,
};

enum class EPlayerState
{
	NONE,
	PState_Idle,
	PState_Move,
	PState_Att,
	PState_Death,
	MAX,
};



enum class EMonsterState
{
	NONE,
	MState_Idle,
	MState_Trace,
	MState_Att,
	MState_Death,
	MAX,
};


enum class ESectionType
{
	NONE,
	NONEFIGHT,
	FIGHTZONE1,
	FIGHTZONE2,
	FIGHTZONE3,
	FIGHTZONE4,
	MAX,
};

enum class EChatMessageType
{
	NONE,
	ALL,
	ONEPLAYER,
	INSECTION,
	MAX,
};