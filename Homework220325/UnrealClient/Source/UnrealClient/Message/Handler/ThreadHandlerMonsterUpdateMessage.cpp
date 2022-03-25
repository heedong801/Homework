#include "ThreadHandlerMonsterUpdateMessage.h"
#include "Kismet/GameplayStatics.h"
#include "../../Global/ClientGameInstance.h"
#include "../../Play/PlayGameMode.h"
#include "../../Play/ChatWindow.h"
#include "../../UnrealClient.h"
#include "../../Play/ClientMonster.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "../../Play/ObjectMessageComponent.h"

// DB에 접속하는일
// 검증하는일
// 마지막으로 결과 패킷을 보내는 일까지
// 전부다 이안에서 벌어져야 하고
// 절대로 외부로 새어나가서는 안됩니다.

// 모든 이렇게 하겠지라고 착각하면 큰일납니다.
// 외우는 것이 아니라 코드를 짠사람의 의도를 파악해라.
// 보통 경력자한테 원하는 겁니다.
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

	// 프리팹 찾는겁니다.
	// 클라이언트가 다 들고 있을 겁니다.
	TSubclassOf<AClientMonster> Monster = PGameMode->GetMonsterClass(Message_->MonsterType);

	if (nullptr == Monster
		|| false == Monster->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > Monster SubClass Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	// 이 몬스터가 존재하지 않아.
	if (false == PGameMode->IsRegist(Message_->ObjectID))
	{
		FTransform Transform = FTransform(Message_->Pos);
		// 최종적으로 월드에 등록을 결정시켜주는 함수를 지연해서 호출할수 있다.
		AClientMonster* NewMonster = World_->SpawnActorDeferred<AClientMonster>(Monster.Get(), Transform);
		// 세팅해 주고 싶은 내용들을 다 세팅해준다음
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

