#pragma once
#include "../ThreadHandlerBase.h"


// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerChatMessage : public ThreadHandlerBase<ChatMessage>
{
public: // Default
	void Start();
};

