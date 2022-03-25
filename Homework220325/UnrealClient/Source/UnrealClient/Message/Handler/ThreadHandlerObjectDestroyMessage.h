#pragma once
#include "CoreMinimal.h"
#include <Memory>
#include "../Messages.h"

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerObjectDestroyMessage final
{
private: 
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<ObjectDestroyMessage> Message_;

public: // Default
	ThreadHandlerObjectDestroyMessage(std::shared_ptr<ObjectDestroyMessage> _LoginMessage);

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Init(UClientGameInstance* _Inst, UWorld* _World);
	void Start();
};

