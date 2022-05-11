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
// ��� �ڵ带 ������Ѽ� ó������ �����Ҽ� ����?
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

	// ���� �������� �´ٰ� ġ�ڽ��ϴ�.
	bool ServerUDPConnect(const FString& _PORTString, uint64 _ServerSendUDP);
	void Close();

	bool Send(const std::vector<uint8>& _Data);

	bool SendTo(const std::vector<uint8>& _Data);
	//bool Recv();

	void FinishDestroy() override;
};
