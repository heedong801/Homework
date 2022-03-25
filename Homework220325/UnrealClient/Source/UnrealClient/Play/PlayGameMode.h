// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include <Memory>
#include <functional>
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
	APlayGameMode();

	TSubclassOf<AClientMonster> GetMonsterClass(int _MonsterType);

	AActor* GetGameObject(int _ObjectID);

	bool UnRegistObject(int _ObjectID, EGameObjectType _Type, AActor* _Actor);
	bool RegistObject(int _ObjectID, EGameObjectType _Type, AActor* _Actor);

	bool ObjectPushMessage(int _ObjectID, std::shared_ptr<GameServerMessage> _Message);

	bool IsRegist(int _ObjectID);

	int GetClientUniqueId();

	TArray<AActor*> GetObjectGroup(EGameObjectType _Type);

	TArray<AClientMonster*> GetObjectGroupMonster();

	void MonsterCollisionCallBack(const AActor* _Actor, float _Radius, float _Angle, std::function<void(AClientMonster*)> _CallBack);

	TArray<AActor*>& GetObjectGroupRef(EGameObjectType _Type);

private:
	int ClientUniqueId_;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientData", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<AClientMonster>> ArrMonsterClass_;
	// TMap<FString, TSubclassOf<AClientMonster>> ArrMonsterClass_;
	// int Seed;
	// 실제적으로는 이 시드를 서버가 줘야 합니다.
	// 내가 뭘했다 할때 시드를 서버로 같이 보내서
	// 만약에 이 시드가 바뀌었다면
	// 뭔가 해킹을 시도했다고 볼수 있다.
	// 애가 보내준 시드로 서버로 똑같이 랜덤을 돌린다면 같은 결과가 나와야 한다.
	// 10만번 돌려야 하는거라고 칩시다.

	// 정상적으로 생성된 오브젝트는 여기에 등록되고
	TMap<int, ServerObject> AllObject_;

	TMap<EGameObjectType, TArray<AActor*>> TypeOfAllObject_;

	
	TArray<AActor*> CirCleCollisionGroup(const FVector& _Postion, float _Radius, EGameObjectType _Type);

	// 자기자신이 등록된 녀석인지 아닌지를 정말 쉽게 알수 있습니다.
	// 어떤 하나의 객체가 있을때 자기자신의 주소값은
	// TSet<Monster*, ServerObject> AllObject_;
};
