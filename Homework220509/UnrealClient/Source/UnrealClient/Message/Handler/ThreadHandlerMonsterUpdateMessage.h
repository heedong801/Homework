#pragma once
#include "../ThreadHandlerBase.h"

// 그 세션도 여기서 받는다.
class ThreadHandlerMonsterUpdateMessage : public ThreadHandlerBase<MonsterUpdateMessage>
{
public: // Default
	void Start();
};

