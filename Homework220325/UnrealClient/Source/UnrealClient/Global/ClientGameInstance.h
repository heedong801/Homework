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
// 어떻게 코드를 변경시켜서 처리할지 예상할수 없죠?
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

	// 그냥 뭐든지 다 여기에다가 박아놔도 됩니다.
	// 첫번째로 이데이터는 어느 레벨에서만 필요하죠?
	// PlayLevel에서만 필요합니다.
	// 이걸 기점으로 모든
	// 모든 놈들을 다 이 instance에 넣기 시작할 겁니다.
	// 저는 별로라고 생각합니다.
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientData", meta = (AllowPrivateAccess = "true"))
	//TArray<TSubclassOf<AClientMonster>> ArrMonsterClass_;

	// Post
	// FNonAbandonableTask

	// Recv는 당연히 쓰레드에서 처리하게 될것이고
	// 언리얼의 쓰레드 방식은 2가지 쓰레드 방식을 지원한다.
	
	// 진짜 생쌩도는 나만의 쓰레드를 만드는 겁니다.
	// FRunnable // 을 상속받은 나만의 쓰레드 를 만드는것.
	// FNonAbandonableTask // 을 상속받은 나만의 쓰레드 를 만드는것.

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
