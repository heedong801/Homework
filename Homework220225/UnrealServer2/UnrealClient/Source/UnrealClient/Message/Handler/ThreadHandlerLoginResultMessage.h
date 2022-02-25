#pragma once
#include "CoreMinimal.h"
#include <Memory>
#include "../Messages.h"

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerLoginResultMessage final
{
private: 
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<LoginResultMessage> LoginResultMessage_;


public: // Default
	ThreadHandlerLoginResultMessage(std::shared_ptr<LoginResultMessage> _LoginMessage);

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Init(UClientGameInstance* _Inst, UWorld* _World);
	void Start();
};

