// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientMonster.h"
#include "ObjectMessageComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../Global/ClientGameInstance.h"
#include "../Play/PlayGameMode.h"
#include "../Global/ClientGameInstance.h"
#include "Animation/AnimMontage.h"
#include "ClientAnimInstance.h"
#include "DrawDebugHelpers.h"
#include "../UnrealClient.h"

#include "Kismet/KismetMathLibrary.h"



// FSM�� �����Դϴ�.
// ���¶�°��� �����մϴ�.
// �׸��� FSM�� �� ���°� ���ÿ� 1���� Ȱ���ɼ� �ִٶ�� �����Դϴ�.
// ȭ����. �����Ѵ�. �i�ư���. �̵��Ѵ�.

// void �������ִ´�()

// void ȭ����()

// void �����Ѵ�()

// void �i�ư���()

// void �̵��Ѵ�()

void AClientMonster::Att(float _DelataTime)
{
	// ������ ���������� �˾ƾ� �ϳ׿�?
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Attack);

	// �̼��� ���� üũ�Ҽ� �־�� �ϰ�
	// ������ �� ������ �մϴ�.
	// ������ ������ �ͱ���.
//
//	if ((Target->GetActorLocation() - GetActorLocation()).Size() < Info.AttRange)
//	{
//		// �ٽð����� �Ҽ� �ִ� ��Ȳ.
//		UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
//
//		Target = nullptr;
//
//#include "../Message/ServerToClient.h"
//		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
//		Message->ObjectID = GetObjectId();
//		Message->Pos = GetActorLocation();
//		Message->UpdateType = EMonsterState::MState_Att;
//		Inst->PushClientMessage(Message);
//		return;
//	}
}
//
//void AClientMonster::Idle(float _DelataTime)
//{
//	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Idle);
//
//	// GameMode�� ���´�.
//	APlayGameMode* GameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
//
//	if (nullptr == GameMode || false == GameMode->IsValidLowLevel())
//	{
//		return;
//	}
//
//	TArray<AActor*>& Players = GameMode->GetObjectGroupRef(EGameObjectType::Player);
//
//	Target = nullptr;
//	float Range = TNumericLimits<float>::Max();
//
//	for (auto& Player : Players)
//	{
//		float CheckLen = (Player->GetActorLocation() - GetActorLocation()).Size();
//
//		if (Range > CheckLen)
//		{
//			Range = CheckLen;
//			Target = Player;
//		}
//	}
//
//	if (nullptr == Target)
//	{
//		return;
//	}
//
//	// ������ ȸ���� 
//	if (Range > Info.LookRange)
//	{
//		return;
//	}
//
//	LookTargetZ(Target);
//
//	if (Range > Info.TraceRange)
//	{
//		return;
//	}
//
//	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
//
//#include "../Message/ServerToClient.h"
//	std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
//	Message->ObjectID = GetObjectId();
//	Message->Pos = GetActorLocation();
//	Message->UpdateType = EMonsterState::MState_Trace;
//	Inst->PushClientMessage(Message);
//}
//
//void AClientMonster::Trace(float _DelataTime)
//{
//	if (nullptr == Target)
//	{
//		UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
//
//		Target = nullptr;
//
//#include "../Message/ServerToClient.h"
//		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
//		Message->ObjectID = GetObjectId();
//		Message->Pos = GetActorLocation();
//		Message->UpdateType = EMonsterState::MState_Idle;
//		Inst->PushClientMessage(Message);
//		return;
//	}
//
//	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);
//
//	LookTargetZ(Target);
//
//	SetActorLocation(GetActorLocation() + GetActorForwardVector() * Info.Speed * _DelataTime);
//
//	if ((Target->GetActorLocation() - GetActorLocation()).Size() < Info.AttRange)
//	{
//		UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
//
//#include "../Message/ServerToClient.h"
//		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
//		Message->ObjectID = GetObjectId();
//		Message->Pos = GetActorLocation();
//		Message->UpdateType = EMonsterState::MState_Att;
//		Inst->PushClientMessage(Message);
//	}
//
//	if ((Target->GetActorLocation() - GetActorLocation()).Size() < Info.TraceRange)
//	{
//		return;
//	}
//
//	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
//
//	Target = nullptr;
//
//#include "../Message/ServerToClient.h"
//	std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
//	Message->ObjectID = GetObjectId();
//	Message->Pos = GetActorLocation();
//	Message->UpdateType = EMonsterState::MState_Idle;
//	Inst->PushClientMessage(Message);
//
//	// Lerp���� ����Ұ� ���ƿ�.
//	// LookTargetAddZ(Target, 0.1f);
//
//	//float Angle = LookZ((MeleePlayer->GetActorLocation() - GetActorLocation()).GetSafeNormal());
//	//FRotator NewRot = FRotator(0.0f, Angle, 0.0f);
//	//SetActorRotation(NewRot);
//}
//
//
//
void AClientMonster::AnimationStart(ClientAnimationType _Value) 
{
//#ifdef ENABLE_DRAW_DEBUG
//	if (_Value == ClientAnimationType::Attack)
//	{
//		DrawDebugSphere(GetWorld(), GetActorLocation() + (GetActorForwardVector() * 100.0f), 200.0f, 10, FColor::Red, false, 0.5f, 0, 5.0f);
//	}
//#endif
}

void AClientMonster::AnimationEnd(ClientAnimationType _Value) 
{
	if (_Value == ClientAnimationType::Attack)
	{
		//UE_LOG(ClientLog, Error, TEXT("ATTACK"), __FUNCTION__, __LINE__);

		GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Idle);

//#include "../Message/ServerToClient.h"
//		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
//		Message->ObjectID = GetObjectId();
//		Message->Pos = GetActorLocation();
//		Message->UpdateType = EMonsterState::MState_Idle;
//		Inst->PushClientMessage(Message);
	}
	else if (_Value == ClientAnimationType::Death)
	{
		UE_LOG(ClientLog, Error, TEXT("DIE"), __FUNCTION__, __LINE__);
		Destroy();
	}
}

void AClientMonster::BeginPlay() 
{
	Super::BeginPlay();

	State_ = EMonsterState::NONE;

	GetClientAnimInstance()->AddEndFunctionBind(std::bind(&AClientMonster::AnimationEnd, this, std::placeholders::_1));

	GetClientAnimInstance()->AddStartFunctionBind(std::bind(&AClientMonster::AnimationStart, this, std::placeholders::_1));
	Ratio = 0.0f;
	DestinationPos = GetActorLocation();
}

void AClientMonster::ObjectInit() 
{


	CurrentUpdateData.Pos = GetActorLocation();
	
	ClientObjectInit();
}

void AClientMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UClientGameInstance* GameInst = Cast<UClientGameInstance>(GetGameInstance());

	//if (true == GameInst->GetClientMode())
	//{
	//	// Ŭ���̾�Ʈ���� ���� �ΰ��������� ���ư��� �̴ϴ�.
	//	ClientUpdate(DeltaTime);
	//	return;
	//}

	// 5���� ���Դµ�
	// 3��°�� ��Ʈ���̶�� ���ô�.
	FVector4 LookDir = FVector4{ 0.f, 0.f, 0.f, 0.f };
	//UE_LOG(LogTemp, Log, TEXT("%f %f %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);

	while (false == GetMessage()->IsEmpty())
	{
		std::shared_ptr<GameServerMessage> Message = GetMessage()->Dequeue();

		if (MessageId::MonsterUpdate == Message->GetId<MessageId>())
		{
			std::shared_ptr<MonsterUpdateMessage> UpdateMessage = std::static_pointer_cast<MonsterUpdateMessage>(Message);

			if (nullptr == UpdateMessage)
			{
				continue;
			}

			State_ = static_cast<EMonsterState>(UpdateMessage->Data.State);

			switch (State_)
			{
			case EMonsterState::NONE:
				break;
			case EMonsterState::MState_Idle:
				GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Idle);
				break;
			case EMonsterState::MState_Trace:
				//UE_LOG(ClientLog, Error, TEXT("TRACE"), __FUNCTION__, __LINE__);

				GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);
				break;
			case EMonsterState::MState_Att:
				GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Attack);
				break;
			case EMonsterState::MState_Death:
				GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Death);

				break;
			case EMonsterState::MAX:
				break;
			default:
				break;
			}

			if (State_ != EMonsterState::MState_Idle)
			{
				UpDataData.Add(UpdateMessage->Data);
				LookDir = UpdateMessage->Data.Dir;
			}
			//FVector4 Dir = UpdateMessage->Data.Dir;
			//LookTargetZ(Dir);
			//UpDataData.Add(UpdateMessage->Data.Pos);

			// SetActorLocation(UpdateMessage->Data.Pos, false, nullptr, ETeleportType::ResetPhysics);
		}
		else if (MessageId::ObjectDestroy == Message->GetId<MessageId>())
		{
			Destroy();
		}
		//else if (MessageId::ObjectDestroy == Message->GetId())
		//{
		//	int a = 0;
		//}
	}


	FVector Pos = GetActorLocation();
	Ratio += DeltaTime * 1.5f;

	/*if (LookDir.Size() == 0)
		LookDir = DestinationPos - Pos;*/

	LookTargetZ(DestinationPos - Pos);

	Pos = FMath::Lerp(CurrentUpdateData.Pos, DestinationPos, Ratio);

	if (Ratio >= 1.f)
	{
		if (UpDataData.Num() != 0)
		{	
			if (UpDataData[0].GetState<EMonsterState>() == EMonsterState::MState_Att)
			{
				SetActorLocation(UpDataData[0].Pos, false, nullptr, ETeleportType::None);
				UpDataData.Pop();
				return;
			}
			UE_LOG(ClientLog, Error, TEXT("POP"), __FUNCTION__, __LINE__);

			Ratio = 0.f;
			CurrentUpdateData.Pos = DestinationPos;
			DestinationPos = UpDataData[0].Pos;
			UpDataData.Pop();
		}
		else
		{
			//UE_LOG(ClientLog, Error, TEXT("FUCK"), __FUNCTION__, __LINE__);
			Ratio = 1.f;

		}
	}

	SetActorLocation(Pos, false, nullptr, ETeleportType::None);

}



void AClientMonster::SetClientDamage(float _Damage)
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

	// UI�� ������� ���ݾƿ�.
	Info.Hp -= _Damage;

	if (false == Inst->GetClientMode())
	{
		return;
	}

	if (0 >= Info.Hp)
	{
#include "../Message/ServerToClient.h"
		std::shared_ptr<ObjectDestroyMessage> Message = std::make_shared<ObjectDestroyMessage>();
		Message->ObjectID = GetObjectId();
		Inst->PushClientMessage(Message);
	}
}


void AClientMonster::ClientUpdate(float _DelataTime)
{
	//switch (State_)
	//{
	//case EMonsterState::MState_Idle:
	//	Idle(_DelataTime);
	//	break;
	//case EMonsterState::MState_Trace:
	//	Trace(_DelataTime);
	//	break;
	//case EMonsterState::MState_Att:
	//	Att(_DelataTime);
	//	break;
	//default:
	//	break;
	//}
}


void AClientMonster::ClientObjectInit() 
{
//	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
//
//	if (true == Inst->GetClientMode())
//	{
//		// Ŭ���̾�Ʈ���� ���� �ΰ��������� ���ư��� �̴ϴ�.
//		Info.Att = 10;
//		Info.Hp = 100;
//		Info.LookRange = 1500;
//		Info.TraceRange = 800;
//		Info.AttRange = 150;
//		Info.Speed = 200;
//
//
//#include "../Message/ServerToClient.h"
//		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
//		Message->ObjectID = GetObjectId();
//		Message->Pos = GetActorLocation();
//		Message->UpdateType = EMonsterState::MState_Idle;
//		Inst->PushClientMessage(Message);
//	}
}