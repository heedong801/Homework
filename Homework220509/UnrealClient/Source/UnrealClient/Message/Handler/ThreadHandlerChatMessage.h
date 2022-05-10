#pragma once
#include "../ThreadHandlerBase.h"


// 그 세션도 여기서 받는다.
class ThreadHandlerChatMessage : public ThreadHandlerBase<ChatMessage>
{
public: // Default
	void Start();
};

