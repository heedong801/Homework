#pragma once

enum class EGameObjectType 
{
	Player,
	Monster,
	Item,
	MAX,
};

enum class EMonsterState
{
	NONE,
	MState_Idle,
	MState_Trace,
	MState_Att,
	MAX,
};
