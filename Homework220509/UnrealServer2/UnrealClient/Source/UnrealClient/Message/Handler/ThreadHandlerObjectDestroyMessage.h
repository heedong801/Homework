#pragma once
#include "../ThreadHandlerBase.h"


// 그 세션도 여기서 받는다.
class ThreadHandlerObjectDestroyMessage : public ThreadHandlerBase<ObjectDestroyMessage>
{
public: // Default
	void Start();
};

