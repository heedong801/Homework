// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <string>
#include <vector>
#include <Memory>
#include <functional>
#include "../Message/Messages.h"
#include "../Play/ChatWindow.h"
#include "ClientGameInstance.generated.h"

// std::thread
// ��� �ڵ带 ������Ѽ� ó������ �����Ҽ� ����?
class UnrealRecvThread : public FRunnable 
{
private:
	TAtomic<bool> IsAppClose_;
	FSocket* RecvSocket_;
	TQueue<std::shared_ptr<GameServerMessage>, EQueueMode::Spsc>* MessageQueue_;

public:
	UnrealRecvThread(FSocket* _RecvSocket, TQueue<std::shared_ptr<GameServerMessage>>* MessageQueue_);

	static bool FunctionTest();

	uint32 Run() override;

public:

	void Close();

};

class AClientMonster;
/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UClientGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	TQueue<std::shared_ptr<GameServerMessage>> MessageQueue_;

	UnrealRecvThread* RecvThread_;
	FRunnableThread* ThreadRunalbe_;

	ISocketSubsystem* SocketSubSystem_;
	FSocket* NewSocket_;

	// TQueue<TArray<char>>

	// �׳� ������ �� ���⿡�ٰ� �ھƳ��� �˴ϴ�.
	// ù��°�� �̵����ʹ� ��� ���������� �ʿ�����?
	// PlayLevel������ �ʿ��մϴ�.
	// �̰� �������� ���
	// ��� ����� �� �� instance�� �ֱ� ������ �̴ϴ�.
	// ���� ���ζ�� �����մϴ�.
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientData", meta = (AllowPrivateAccess = "true"))
	//TArray<TSubclassOf<AClientMonster>> ArrMonsterClass_;

	// Post
	// FNonAbandonableTask

	// Recv�� �翬�� �����忡�� ó���ϰ� �ɰ��̰�
	// �𸮾��� ������ ����� 2���� ������ ����� �����Ѵ�.
	
	// ��¥ ���ߵ��� ������ �����带 ����� �̴ϴ�.
	// FRunnable // �� ��ӹ��� ������ ������ �� ����°�.
	// FNonAbandonableTask // �� ��ӹ��� ������ ������ �� ����°�.

private:
	bool ClientMode_;

public:
	FORCEINLINE bool GetClientMode() 
	{
		return ClientMode_;
	}

	FORCEINLINE void SetClientMode(bool _Value)
	{
		ClientMode_ = _Value;
	}

public:
	FString ID;
	UChatWindow* ChatWindow_;

public:
	UClientGameInstance();
	~UClientGameInstance();

	void PushClientMessage(std::shared_ptr<GameServerMessage> _Message);

	std::shared_ptr<GameServerMessage> PopMessage();
	bool IsEmptyMessage();

	bool IsThreadCheck();
	bool IsGameCheck();

	bool ServerConnect(const FString& _IPString, const FString& _PORTString);
	void Close();

	bool Send(const std::vector<uint8>& _Data);
	//bool Recv();

	void FinishDestroy() override;
};
