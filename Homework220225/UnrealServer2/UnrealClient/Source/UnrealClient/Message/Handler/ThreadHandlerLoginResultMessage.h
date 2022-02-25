#pragma once
#include "CoreMinimal.h"
#include <Memory>
#include "../Messages.h"

// 그 세션도 여기서 받는다.
class ThreadHandlerLoginResultMessage final
{
private: 
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<LoginResultMessage> LoginResultMessage_;


public: // Default
	ThreadHandlerLoginResultMessage(std::shared_ptr<LoginResultMessage> _LoginMessage);

	// 이 메세지를 처음 받았을때 실행하는 함수
	void Init(UClientGameInstance* _Inst, UWorld* _World);
	void Start();
};

