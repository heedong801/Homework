#pragma once
#include "../ThreadHandlerBase.h"


// 그 세션도 여기서 받는다.
class ThreadHandlerCharacterCreateResultMessage : public ThreadHandlerBase<CharacterCreateResultMessage>
{
private: 


public: // Default
	void Start();
};

