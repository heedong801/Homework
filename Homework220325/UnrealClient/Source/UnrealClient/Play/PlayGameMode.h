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
	// ���������δ� �� �õ带 ������ ��� �մϴ�.
	// ���� ���ߴ� �Ҷ� �õ带 ������ ���� ������
	// ���࿡ �� �õ尡 �ٲ���ٸ�
	// ���� ��ŷ�� �õ��ߴٰ� ���� �ִ�.
	// �ְ� ������ �õ�� ������ �Ȱ��� ������ �����ٸ� ���� ����� ���;� �Ѵ�.
	// 10���� ������ �ϴ°Ŷ�� Ĩ�ô�.

	// ���������� ������ ������Ʈ�� ���⿡ ��ϵǰ�
	TMap<int, ServerObject> AllObject_;

	TMap<EGameObjectType, TArray<AActor*>> TypeOfAllObject_;

	
	TArray<AActor*> CirCleCollisionGroup(const FVector& _Postion, float _Radius, EGameObjectType _Type);

	// �ڱ��ڽ��� ��ϵ� �༮���� �ƴ����� ���� ���� �˼� �ֽ��ϴ�.
	// � �ϳ��� ��ü�� ������ �ڱ��ڽ��� �ּҰ���
	// TSet<Monster*, ServerObject> AllObject_;
};
