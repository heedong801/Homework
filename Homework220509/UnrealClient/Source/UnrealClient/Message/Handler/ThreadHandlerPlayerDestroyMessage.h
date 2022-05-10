#pragma once
#include "../ThreadHandlerBase.h"

// 그 세션도 여기서 받는다.
class ThreadHandlerPlayerDestroyMessage : public ThreadHandlerBase<PlayerDestroyMessage>
{
public: // Default
	void Start();
};

