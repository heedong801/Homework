#pragma once
#include "../ThreadHandlerBase.h"


// 그 세션도 여기서 받는다.
class ThreadHandlerSectionInsertResultMessage : public ThreadHandlerBase<SectionInsertResultMessage>
{
private: 


public: // Default
	void Start();
};

