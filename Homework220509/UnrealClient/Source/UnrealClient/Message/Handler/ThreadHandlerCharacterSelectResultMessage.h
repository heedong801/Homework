#pragma once
#include "../ThreadHandlerBase.h"


// 그 세션도 여기서 받는다.
class ThreadHandlerCharacterSelectResultMessage : public ThreadHandlerBase<CharacterSelectResultMessage>
{
private: 


public: // Default
	void Start();
};

