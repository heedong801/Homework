#pragma once
#include "../ThreadHandlerBase.h"


// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerObjectDestroyMessage : public ThreadHandlerBase<ObjectDestroyMessage>
{
public: // Default
	void Start();
};

