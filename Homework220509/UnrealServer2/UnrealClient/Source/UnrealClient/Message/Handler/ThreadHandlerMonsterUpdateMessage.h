#pragma once
#include "../ThreadHandlerBase.h"

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerMonsterUpdateMessage : public ThreadHandlerBase<MonsterUpdateMessage>
{
public: // Default
	void Start();
};

