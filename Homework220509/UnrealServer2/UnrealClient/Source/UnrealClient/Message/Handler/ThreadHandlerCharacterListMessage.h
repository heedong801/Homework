#pragma once
#include "../ThreadHandlerBase.h"


// 그 세션도 여기서 받는다.
class ThreadHandlerCharacterListMessage : public ThreadHandlerBase<CharacterListMessage>
{
public:
	void Start();
};

