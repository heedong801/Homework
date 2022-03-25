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


// FSM은 개념입니다.
// 상태라는것이 존재합니다.
// 그리고 FSM은 그 상태가 동시에 1개만 활성될수 있다라는 개념입니다.
// 화났다. 공격한다. 쫒아간다. 이동한다.

// void 가만히있는다()

// void 화났다()

// void 공격한다()

// void 쫒아간다()

// void 이동한다()

void AClientMonster::Att(float _DelataTime)
{
	// 공격이 끝났을때를 알아야 하네요?
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Attack);

	// 이순간 순간 체크할수 있어야 하고
	// 완전히 다 끝내야 합니다.
	// 데미지 입히는 것까지.
//
//	if ((Target->GetActorLocation() - GetActorLocation()).Size() < Info.AttRange)
//	{
//		// 다시공격을 할수 있는 상황.
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

void AClientMonster::Idle(float _DelataTime)
{
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Idle);

	// GameMode를 얻어온다.
	APlayGameMode* GameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (nullptr == GameMode || false == GameMode->IsValidLowLevel())
	{
		return;
	}

	TArray<AActor*>& Players = GameMode->GetObjectGroupRef(EGameObjectType::Player);

	Target = nullptr;
	float Range = TNumericLimits<float>::Max();

	for (auto& Player : Players)
	{
		float CheckLen = (Player->GetActorLocation() - GetActorLocation()).Size();

		if (Range > CheckLen)
		{
			Range = CheckLen;
			Target = Player;
		}
	}

	if (nullptr == Target)
	{
		return;
	}

	// 서버는 회전을 
	if (Range > Info.LookRange)
	{
		return;
	}

	LookTargetZ(Target);

	if (Range > Info.TraceRange)
	{
		return;
	}

	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

#include "../Message/ServerToClient.h"
	std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
	Message->ObjectID = GetObjectId();
	Message->Pos = GetActorLocation();
	Message->UpdateType = EMonsterState::MState_Trace;
	Inst->PushClientMessage(Message);
}

void AClientMonster::Trace(float _DelataTime)
{
	if (nullptr == Target)
	{
		UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

		Target = nullptr;

#include "../Message/ServerToClient.h"
		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
		Message->ObjectID = GetObjectId();
		Message->Pos = GetActorLocation();
		Message->UpdateType = EMonsterState::MState_Idle;
		Inst->PushClientMessage(Message);
		return;
	}

	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);

	LookTargetZ(Target);

	SetActorLocation(GetActorLocation() + GetActorForwardVector() * Info.Speed * _DelataTime);

	if ((Target->GetActorLocation() - GetActorLocation()).Size() < Info.AttRange)
	{
		UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

#include "../Message/ServerToClient.h"
		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
		Message->ObjectID = GetObjectId();
		Message->Pos = GetActorLocation();
		Message->UpdateType = EMonsterState::MState_Att;
		Inst->PushClientMessage(Message);
	}

	if ((Target->GetActorLocation() - GetActorLocation()).Size() < Info.TraceRange)
	{
		return;
	}

	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

	Target = nullptr;

#include "../Message/ServerToClient.h"
	std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
	Message->ObjectID = GetObjectId();
	Message->Pos = GetActorLocation();
	Message->UpdateType = EMonsterState::MState_Idle;
	Inst->PushClientMessage(Message);

	// Lerp까지 써야할거 같아요.
	// LookTargetAddZ(Target, 0.1f);

	//float Angle = LookZ((MeleePlayer->GetActorLocation() - GetActorLocation()).GetSafeNormal());
	//FRotator NewRot = FRotator(0.0f, Angle, 0.0f);
	//SetActorRotation(NewRot);
}



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
		UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

		Target = nullptr;

#include "../Message/ServerToClient.h"
		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
		Message->ObjectID = GetObjectId();
		Message->Pos = GetActorLocation();
		Message->UpdateType = EMonsterState::MState_Idle;
		Inst->PushClientMessage(Message);
	}
}

void AClientMonster::BeginPlay() 
{
	Super::BeginPlay();

	State_ = EMonsterState::NONE;

	GetClientAnimInstance()->AddEndFunctionBind(std::bind(&AClientMonster::AnimationEnd, this, std::placeholders::_1));

	GetClientAnimInstance()->AddStartFunctionBind(std::bind(&AClientMonster::AnimationStart, this, std::placeholders::_1));
}

void AClientMonster::ObjectInit() 
{
	ClientObjectInit();
}

void AClientMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UClientGameInstance* GameInst = Cast<UClientGameInstance>(GetGameInstance());

	if (true == GameInst->GetClientMode())
	{
		// 클라이언트에서 만든 인공지능으로 돌아가는 겁니다.
		ClientUpdate(DeltaTime);
	}

	// 5개가 들어왔는데
	// 3번째가 디스트로이라고 봅시다.
	while (false == GetMessage()->IsEmpty())
	{
		std::shared_ptr<GameServerMessage> Message = GetMessage()->Dequeue();

		if (MessageId::MonsterUpdate == Message->GetId())
		{
			std::shared_ptr<MonsterUpdateMessage> UpdateMessage = std::static_pointer_cast<MonsterUpdateMessage>(Message);

			if (nullptr == UpdateMessage)
			{
				continue;
			}

			State_ = UpdateMessage->UpdateType;

			SetActorLocation(UpdateMessage->Pos);
		}
		else if (MessageId::ObjectDestroy == Message->GetId())
		{
			Destroy();
		}
		//else if (MessageId::ObjectDestroy == Message->GetId())
		//{
		//	int a = 0;
		//}
	}
}



void AClientMonster::SetClientDamage(float _Damage)
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

	// UI로 보여줘야 하잖아요.
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
	switch (State_)
	{
	case EMonsterState::MState_Idle:
		Idle(_DelataTime);
		break;
	case EMonsterState::MState_Trace:
		Trace(_DelataTime);
		break;
	case EMonsterState::MState_Att:
		Att(_DelataTime);
		break;
	default:
		break;
	}
}


void AClientMonster::ClientObjectInit() 
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());

	if (true == Inst->GetClientMode())
	{
		// 클라이언트에서 만든 인공지능으로 돌아가는 겁니다.
		Info.Att = 10;
		Info.Hp = 100;
		Info.LookRange = 1500;
		Info.TraceRange = 800;
		Info.AttRange = 150;
		Info.Speed = 200;


#include "../Message/ServerToClient.h"
		std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
		Message->ObjectID = GetObjectId();
		Message->Pos = GetActorLocation();
		Message->UpdateType = EMonsterState::MState_Idle;
		Inst->PushClientMessage(Message);
	}
}