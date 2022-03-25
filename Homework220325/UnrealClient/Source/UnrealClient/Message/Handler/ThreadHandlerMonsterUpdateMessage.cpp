#include "ThreadHandlerMonsterUpdateMessage.h"
#include "Kismet/GameplayStatics.h"
#include "../../Global/ClientGameInstance.h"
#include "../../Play/PlayGameMode.h"
#include "../../Play/ChatWindow.h"
#include "../../UnrealClient.h"
#include "../../Play/ClientMonster.h"
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

	// ������ ã�°̴ϴ�.
	// Ŭ���̾�Ʈ�� �� ��� ���� �̴ϴ�.
	TSubclassOf<AClientMonster> Monster = PGameMode->GetMonsterClass(Message_->MonsterType);

	if (nullptr == Monster
		|| false == Monster->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > Monster SubClass Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	// �� ���Ͱ� �������� �ʾ�.
	if (false == PGameMode->IsRegist(Message_->ObjectID))
	{
		FTransform Transform = FTransform(Message_->Pos);
		// ���������� ���忡 ����� ���������ִ� �Լ��� �����ؼ� ȣ���Ҽ� �ִ�.
		AClientMonster* NewMonster = World_->SpawnActorDeferred<AClientMonster>(Monster.Get(), Transform);
		// ������ �ְ� ���� ������� �� �������ش���
		NewMonster->FinishSpawning(Transform);
		NewMonster->SetId(Message_->ObjectID);
		NewMonster->SetObjectType(EGameObjectType::Monster);
		PGameMode->RegistObject(Message_->ObjectID, EGameObjectType::Monster, NewMonster);
		PGameMode->ObjectPushMessage(Message_->ObjectID, Message_);
		NewMonster->ObjectInit();
		return;
	}

	PGameMode->ObjectPushMessage(Message_->ObjectID, Message_);
}

