#pragma once
#include "../ThreadHandlerBase.h"


// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerUDPReadyOKMessage : public ThreadHandlerBase<UDPReadyOKMessage>
{
public: // Default
	void Start();
};

