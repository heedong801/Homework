#pragma once
#include "../ThreadHandlerBase.h"

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerPlayerDestroyMessage : public ThreadHandlerBase<PlayerDestroyMessage>
{
public: // Default
	void Start();
};

