#include "ThreadHandlerMonsterUpdateMessage.h"
#include "Kismet/GameplayStatics.h"
#include "../../Global/ClientGameInstance.h"
#include "../../Play/PlayGameMode.h"
#include "../../Play/ChatWindow.h"
#include "../../UnrealClient.h"
#include "../../Play/ClientMonster.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "../../Play/ObjectMessageComponent.h"



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
	TSubclassOf<AClientMonster> Monster = PGameMode->GetMonsterClass(0);

	if (nullptr == Monster
		|| false == Monster->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > Monster SubClass Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	// 이 몬스터가 존재하지 않아.
	if (false == PGameMode->IsRegist(Message_->Data.ObjectIndex))
	{
		FTransform Transform = FTransform(Message_->Data.Pos);
		// 최종적으로 월드에 등록을 결정시켜주는 함수를 지연해서 호출할수 있다.
		AClientMonster* NewMonster = World_->SpawnActorDeferred<AClientMonster>(Monster.Get(), Transform);
		// 세팅해 주고 싶은 내용들을 다 세팅해준다음
		NewMonster->FinishSpawning(Transform);
		NewMonster->SetId(Message_->Data.ObjectIndex);
		NewMonster->SetObjectType(EGameObjectType::Monster);
		PGameMode->RegistObject(Message_->Data.ObjectIndex, EGameObjectType::Monster, NewMonster);
		PGameMode->ObjectPushMessage(Message_->Data.ObjectIndex, Message_);
		NewMonster->ObjectInit();
		return;
	}

	PGameMode->ObjectPushMessage(Message_->Data.ObjectIndex, Message_);
}

