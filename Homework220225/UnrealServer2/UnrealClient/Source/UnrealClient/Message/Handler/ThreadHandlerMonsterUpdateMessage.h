#pragma once
#include "CoreMinimal.h"
#include <Memory>
#include "../Messages.h"

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerMonsterUpdateMessage final
{
private: 
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<MonsterUpdateMessage> Message_;

public: // Default
	ThreadHandlerMonsterUpdateMessage(std::shared_ptr<MonsterUpdateMessage> _LoginMessage);

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Init(UClientGameInstance* _Inst, UWorld* _World);
	void Start();
};

