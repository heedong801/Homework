#pragma once
#include "../ThreadHandlerBase.h"

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerServerDestroyMessage : public ThreadHandlerBase<ServerDestroyMessage>
{
public: // Default
	void Start();
};

