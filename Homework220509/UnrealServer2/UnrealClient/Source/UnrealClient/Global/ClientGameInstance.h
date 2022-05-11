// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <string>
#include <vector>
#include <Memory>
#include <functional>
#include "../Message/Messages.h"
#include "../Message/ContentsStructure.h"
#include "../Play/ChatWindow.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "ClientGameInstance.generated.h"

// std::thread
// 어떻게 코드를 변경시켜서 처리할지 예상할수 없죠?
class UnrealRecvThread : public FRunnable 
{
private:
	ISocketSubsystem* SocketSubSystem_;
	TAtomic<bool> IsAppClose_;
	FSocket* RecvSocket_;
	TQueue<std::shared_ptr<GameServerMessage>, EQueueMode::Spsc>* MessageQueue_;

public:
	UnrealRecvThread(ISocketSubsystem* SocketSubSystem_, FSocket* _RecvSocket, TQueue<std::shared_ptr<GameServerMessage>>* MessageQueue_);

	static bool FunctionTest();

	uint32 Run() override;

public:

	void Close();

};

class UnrealUDPRecvThread : public FRunnable
{
private:
	ISocketSubsystem* SocketSubSystem_;
	TAtomic<bool> IsAppClose_;
	FSocket* RecvSocket_;
	TQueue<std::shared_ptr<GameServerMessage>, EQueueMode::Spsc>* MessageQueue_;

public:
	UnrealUDPRecvThread(ISocketSubsystem* SocketSubSystem_, FSocket* _RecvSocket, TQueue<std::shared_ptr<GameServerMessage>>* MessageQueue_);

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

	UnrealUDPRecvThread* UDPRecvThread_;
	FRunnableThread* UDPThreadRunalbe_;

	ISocketSubsystem* SocketSubSystem_;
	FSocket* TCPSocket_;
	FSocket* UDPSocket_;

	FIPv4Address ConnectAddress_;
	int Port_;
	FIPv4Endpoint EndPoint_;

	int ClientRecvUDPPort_; // 35000
	int ServerSendUDPPort_; // 30001
	FIPv4Endpoint ClientRecvUDPEndPoint_;
	FIPv4Endpoint ServerSendUDPEndPoint_;

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
	UFUNCTION(BlueprintCallable, Category = "Instance")
	FORCEINLINE int GetClientIndex()
	{
		return ObjectIndex;
	}

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
	FString NickName;
	std::string NickNameUTF8;
	UChatWindow* ChatWindow_;
	TAtomic<bool> LoginProcess_;
	std::vector<FCharacterInfo> Characters_;
	class UListView* CharacterListView_;
	class UListView* TopRankListView_;
	class UListView* MyRankListView_;
	FCharacterInfo SelectCharacter;
	uint64_t ObjectIndex;
	uint64_t ThreadIndex;
	uint64_t SectionIndex;

public:
	UClientGameInstance();
	~UClientGameInstance();

	void PushClientMessage(std::shared_ptr<GameServerMessage> _Message);

	std::shared_ptr<GameServerMessage> PopMessage();
	bool IsEmptyMessage();

	bool IsThreadCheck();

	bool ServerConnect(const FString& _IPString, const FString& _PORTString);

	// 같은 서버에서 온다고 치겠습니다.
	bool ServerUDPConnect(const FString& _PORTString, uint64 _ServerSendUDP);
	void Close();

	bool Send(const std::vector<uint8>& _Data);

	bool SendTo(const std::vector<uint8>& _Data);
	//bool Recv();

	void FinishDestroy() override;
};
