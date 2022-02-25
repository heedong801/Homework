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
	// ���������δ� �� �õ带 ������ ��� �մϴ�.
	// ���� ���ߴ� �Ҷ� �õ带 ������ ���� ������
	// ���࿡ �� �õ尡 �ٲ���ٸ�
	// ���� ��ŷ�� �õ��ߴٰ� ���� �ִ�.
	// �ְ� ������ �õ�� ������ �Ȱ��� ������ �����ٸ� ���� ����� ���;� �Ѵ�.
	// 10���� ������ �ϴ°Ŷ�� Ĩ�ô�.

	// ���������� ������ ������Ʈ�� ���⿡ ��ϵǰ�
	TMap<int, ServerObject> AllObject_;
};
