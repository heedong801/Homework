// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include <Memory>
#include "../Message/Messages.h"
#include "PlayGameMode.generated.h"

struct ServerObject
{
	class AActor* Actor;
	class UObjectMessageComponent* Message;
};

class AClientMonster;
/**
 * 
 */
UCLASS()
class UNREALCLIENT_API APlayGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	TSubclassOf<AClientMonster> GetMonsterClass(int _MonsterType);

	bool RegistObject(int _ObjectID, AActor* _Actor);

	bool ObjectPushMessage(int _ObjectID, std::shared_ptr<GameServerMessage> _Message);

	bool IsRegist(int _ObjectID);


private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientData", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<AClientMonster>> ArrMonsterClass_;

	// int Seed;
	// 실제적으로는 이 시드를 서버가 줘야 합니다.
	// 내가 뭘했다 할때 시드를 서버로 같이 보내서
	// 만약에 이 시드가 바뀌었다면
	// 뭔가 해킹을 시도했다고 볼수 있다.
	// 애가 보내준 시드로 서버로 똑같이 랜덤을 돌린다면 같은 결과가 나와야 한다.
	// 10만번 돌려야 하는거라고 칩시다.

	// 정상적으로 생성된 오브젝트는 여기에 등록되고
	TMap<int, ServerObject> AllObject_;
};
