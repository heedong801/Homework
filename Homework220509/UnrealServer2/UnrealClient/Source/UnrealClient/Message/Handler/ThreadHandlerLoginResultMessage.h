#pragma once
#include "../ThreadHandlerBase.h"


// 그 세션도 여기서 받는다.
class ThreadHandlerLoginResultMessage : public ThreadHandlerBase<LoginResultMessage>
{

public: // Default

	void Start();
};

