
#include "ThreadHandlerPlayersUpdateMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../CharacterSelect/CharacterListItemObject.h"
#include "../../CharacterSelect/CharacterListItem.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "Components/ListView.h"
#include "../../UnrealClient.h"
#include "../../Play/PlayGameMode.h"
#include "../../Play/ClientCharacter.h"

void ThreadHandlerPlayersUpdateMessage::Start()
{
	APlayGameMode* PGameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(World_));

	if (nullptr == PGameMode
		|| false == PGameMode->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > GameMode Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	// 공통우리는 딱 하나의 로직만을 사용해서 그 규칙을 어기지 않는다
	// 어길 경우가 생기면 그건 무조건 예외로서 우리 모두가 알아야 한다.
	
	// 클라이언트가 다 들고 있을 겁니다.
	TSubclassOf<AClientCharacter> CharacterSubClass = PGameMode->GetOtherPlayerClass();

	if (nullptr == CharacterSubClass
		|| false == CharacterSubClass->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > Character SubClass Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	for (size_t i = 0; i < Message_->Datas.size(); i++)
	{
		std::shared_ptr<PlayerUpdateMessage> PlayerMessage = std::make_shared<PlayerUpdateMessage>();

		PlayerMessage->Data = Message_->Datas[i];

		// 이 몬스터가 존재하지 않아.
		if (false == PGameMode->IsRegist(PlayerMessage->Data.ObjectIndex))
		{
			FTransform Transform = FTransform(PlayerMessage->Data.Pos);
			// 최종적으로 월드에 등록을 결정시켜주는 함수를 지연해서 호출할수 있다.
			AClientCharacter* NewCharacter = World_->SpawnActorDeferred<AClientCharacter>(CharacterSubClass.Get(), Transform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
			// 세팅해 주고 싶은 내용들을 다 세팅해준다음
			NewCharacter->FinishSpawning(Transform);
			NewCharacter->SetId(PlayerMessage->Data.ObjectIndex);
			NewCharacter->SetObjectType(EGameObjectType::Player);
			PGameMode->RegistObject(PlayerMessage->Data.ObjectIndex, EGameObjectType::Player, NewCharacter);
			NewCharacter->ObjectInit();
		}

		PGameMode->ObjectPushMessage(PlayerMessage->Data.ObjectIndex, Message_);

	}
	// 로딩이 있다면 


}

