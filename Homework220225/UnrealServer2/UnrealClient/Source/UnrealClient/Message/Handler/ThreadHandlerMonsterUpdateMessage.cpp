#include "ThreadHandlerMonsterUpdateMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../Play/ChatWindow.h"
#include "../../UnrealClient.h"
#include "../../Play/ClientMonster.h"
#include "../../Play/PlayGameMode.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "../../Play/ObjectMessageComponent.h"

// DB�� �����ϴ���
// �����ϴ���
// ���������� ��� ��Ŷ�� ������ �ϱ���
// ���δ� �̾ȿ��� �������� �ϰ�
// ����� �ܺη� ��������� �ȵ˴ϴ�.

// ��� �̷��� �ϰ������ �����ϸ� ū�ϳ��ϴ�.
// �ܿ�� ���� �ƴ϶� �ڵ带 §����� �ǵ��� �ľ��ض�.
// ���� ��������� ���ϴ� �̴ϴ�.
ThreadHandlerMonsterUpdateMessage::ThreadHandlerMonsterUpdateMessage(std::shared_ptr<MonsterUpdateMessage> _Message)
	: Message_(_Message)
{
}

void ThreadHandlerMonsterUpdateMessage::Init(UClientGameInstance* _Inst, UWorld* _World)
{
	Inst_ = _Inst;
	World_ = _World;
}


void ThreadHandlerMonsterUpdateMessage::Start()
{
	APlayGameMode* PGameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(World_));

	if (nullptr == PGameMode
		|| false == PGameMode->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > GameMode Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	TSubclassOf<AClientMonster> Monster = PGameMode->GetMonsterClass(Message_->MonsterType);

	if (nullptr == Monster
		|| false == Monster->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > Monster SubClass Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	AClientMonster* NewMonster = nullptr;

	// �� ���Ͱ� �������� �ʾ�.
	if (false == PGameMode->IsRegist(Message_->ObjectID))
	{
		FTransform Transform = FTransform(Message_->Pos);
		// ���������� ���忡 ����� ���������ִ� �Լ��� �����ؼ� ȣ���Ҽ� �ִ�.
		NewMonster = World_->SpawnActorDeferred<AClientMonster>(Monster.Get(), Transform);
		// ������ �ְ� ���� ������� �� �������ش���
		NewMonster->FinishSpawning(Transform);
		PGameMode->RegistObject(Message_->ObjectID, NewMonster);
	}

	PGameMode->ObjectPushMessage(Message_->ObjectID, Message_);
}

