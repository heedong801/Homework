// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientGameInstance.h"
#include "Sockets.h"
#include "SocketSubSystem.h"
#include "Networking.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "../Message/MessageConverter.h"
#include "../Message/Handler/ThreadHandlerServerDestroyMessage.h"

UnrealRecvThread::UnrealRecvThread(FSocket* _RecvSocket, TQueue<std::shared_ptr<GameServerMessage>>* _MessageQueue)
{
	if (nullptr == _RecvSocket)
	{
		UE_LOG(LogTemp, Error, TEXT("RecvSocket Error"));
	}

	RecvSocket_ = _RecvSocket;
	MessageQueue_ = _MessageQueue;
	IsAppClose_ = true;
}

bool UnrealRecvThread::FunctionTest() 
{
	return false;
}

uint32 UnrealRecvThread::Run() 
{
	UE_LOG(LogTemp, Log, TEXT("Recv Start"));

	while (IsAppClose_)
	{
		std::vector<uint8> RecvData;
		RecvData.resize(1024);
		int32 RecvDataSize_ = 0;

		if (false == RecvSocket_->Recv(&RecvData[0], RecvData.size(), RecvDataSize_))
		{
			auto Result = RecvSocket_->GetConnectionState();

			switch (Result)
			{
			case SCS_NotConnected:
				break;
			case SCS_Connected:
				// 서버가 종료되었을때
				// 에러는 분명하지만
				// 아직 소켓이 커넥트 상태라고 처리된다.
				// ThreadHandlerServerDestroy
			{
				ServerDestroyMessage SDM;
				GameServerSerializer Sr;
				SDM.Serialize(Sr);
				MessageConverter Converter = MessageConverter(Sr.GetData());
				MessageQueue_->Enqueue(Converter.GetServerMessage());
				return 0;
			}
			case SCS_ConnectionError:
				// 내가 직접 종료했을때
				// 아무것도 할필요가 없다.
				break;
			default:
				break;
			}

			break;
		}

		MessageConverter Converter = MessageConverter(RecvData);
		MessageQueue_->Enqueue(Converter.GetServerMessage());
	}

	return 0;
}

void UnrealRecvThread::Close() 
{
	IsAppClose_ = false;
}

// 언리얼을 사용한다는것은
// 기능을 찾아본다.
// 95%는 있어
// 5% 조합하면 있어요.
// 100% 있어
// 다른 사람들의 기준으로는
// 떼쓰는것 <= 자동

UClientGameInstance::UClientGameInstance()
{
	ClientMode_ = false;
}

UClientGameInstance::~UClientGameInstance() 
{
	if (nullptr != RecvThread_)
	{
		RecvThread_->Exit();
		RecvThread_ = nullptr;
	}
	int a = 0;
}

void UClientGameInstance::Close() 
{
	if (nullptr != RecvThread_)
	{
		RecvThread_->Close();
	}

	if (nullptr == NewSocket_)
	{
		return;
	}

	NewSocket_->Close();
	NewSocket_ = nullptr;
}

bool UClientGameInstance::ServerConnect(const FString& _IPString, const FString& _PORTString)
{
	if (false == IsThreadCheck())
	{
		return false;
	}

	Close();

	SocketSubSystem_ = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

	// 이 Level Login Level에서 만들어졌다고 치고

	NewSocket_ = SocketSubSystem_->CreateSocket(NAME_Stream, TEXT("Test"), false);

	if (nullptr == NewSocket_)
	{
		UE_LOG(LogTemp, Error, TEXT("if (nullptr == NewSocket)"));
		return false;
	}

	NewSocket_->SetNoDelay(true);

	FIPv4Address ConnectAddress;
	FIPv4Address::Parse(_IPString, ConnectAddress);
	int Port = static_cast<uint16>(FCString::Atoi(*_PORTString));
	FIPv4Endpoint EndPoint = FIPv4Endpoint(ConnectAddress, Port);
	// 주소까지 만들어냈다면

	if (false == NewSocket_->Connect(EndPoint.ToInternetAddr().Get()))
	{
		SocketSubSystem_ = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
		FString ErrorText = SocketSubSystem_->GetSocketError(SocketSubSystem_->GetLastErrorCode());
		// 빨간색으로 로그에 띄우고 싶다면 Error
		UE_LOG(LogTemp, Error, TEXT("Server Error : %s"), *ErrorText);
		NewSocket_->Close();
		NewSocket_ = nullptr;
		return false;
	}

	RecvThread_ = new UnrealRecvThread(NewSocket_, &MessageQueue_);

	ThreadRunalbe_ = FRunnableThread::Create(RecvThread_, TEXT("Recv Thread"));




	return true;
}

bool UClientGameInstance::IsThreadCheck() 
{
	// 이런 환경에서 사용한다는걸 생각조차 하지 않는다.
	// 아예 멀티 쓰레드가 불가능
	// 운영체제 기능이겠죠.
	if (false == FPlatformProcess::SupportsMultithreading())
	{
		UE_LOG(LogTemp, Error, TEXT("Is Not Support Multithreading"));
		return false;
	}

	return true;
}

bool UClientGameInstance::Send(const std::vector<uint8>& _Data)
{
	if (nullptr == NewSocket_)
	{
		return false;
	}

	if (0 == _Data.size())
	{
		return false;
	}

	int32 DataSendSize = 0;

	return NewSocket_->Send(&_Data[0], _Data.size(), DataSendSize);
}

void UClientGameInstance::FinishDestroy()
{
	Close();

	Super::FinishDestroy();

	int a = 0;

	
}


void UClientGameInstance::PushClientMessage(std::shared_ptr<GameServerMessage> _Message) 
{
	if (false == ClientMode_)
	{
		return;
	}

	MessageQueue_.Enqueue(_Message);
}

std::shared_ptr<GameServerMessage> UClientGameInstance::PopMessage()
{
	std::shared_ptr<GameServerMessage> _Message;
	MessageQueue_.Dequeue(_Message);

	return _Message;
}

bool UClientGameInstance::IsEmptyMessage() 
{
	return MessageQueue_.IsEmpty();
}