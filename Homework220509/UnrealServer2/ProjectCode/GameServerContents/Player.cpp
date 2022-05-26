#include "PreCompile.h"
#include "Player.h"
#include "Portal.h"
#include "ClientToServer.h"
#include "ServerToClient.h"
#include "GameServerCore\GameServerCore.h"
#include "GameServerBase\GameServerThread.h"
#include "Monster.h"
#include <GameServerNet\TCPSession.h>
#include "ContentsSystemEnum.h"
#include "ContentsUserData.h"
#include "CharacterTable.h"
#include "ContentsEnum.h"
#include "GameServerBase\GameServerDebug.h"
#include <GameServerCore\GameServerSection.h>
#include <GameServerCore\DBQueue.h>


Player::Player()
	: UDPReady_(false)
	, PortalPtr(nullptr)
	, HitCollision(nullptr)
	, AttackCollision(nullptr)
	, IsAttack(false)
{
}

Player::~Player() 
{

	if (nullptr != HitCollision)
	{
		HitCollision->Death();
		HitCollision = nullptr;
	}
	if (nullptr != AttackCollision)
	{
		AttackCollision->Death();
		AttackCollision = nullptr;
	}
}

void Player::AttackCollisionCheck()
{
	std::vector<GameServerCollision*> Result;

	if (true == AttackCollision->CollisionCheckResult(CollisionCheckType::SPHERE, ECollisionGroup::MONSTER, CollisionCheckType::SPHERE, Result))
	{
		Monster* MonsterPtr = Result[0]->GetOwnerActorConvert<Monster>();

		if (nullptr == MonsterPtr)
		{
			GameServerDebug::AssertDebugMsg("���Ϳ� �߸��� ��ü�� �� �־����ϴ�.");
			return;
		}

		// ������ �ִ� �ٸ� ���͵鿡�� �������ϴ� �޼����� �˴ϴ�.
		MonsterPtr->ChangeState(EMonsterState::MState_Death);
		
	}
}

void Player::PlayerUpdateMessageProcess(std::shared_ptr<class PlayerUpdateMessage> _Message)
{
	// �̰� ���� ó������ ���ƿ� �޼������.
	// ������ ��� �ְ� �Ǿ���.

	if (false == UDPReady_)
	{
		UDPReady_ = true;
		UDPReadyOKMessage Msg;
		Msg.Code = EGameServerCode::OK;
		Msg.ObjectIndex = GetIndex();
		GameServerSerializer Sr;
		Msg.Serialize(Sr);

		// "SELECT Idx, NickName, UserIndex, ATT, HP, LastSectionid, LastSectionPosx, LastSectionPosy, LastSectionPosz FROM userver2.characterinfo WHERE NickName = ? LIMIT 1"
		GetTCPSession()->Send(Sr.GetData());

		// GetTCPSession()->Send("SELECT Idx, NickName, UserIndex, ATT, HP, LastSectionid, LastSectionPosx, LastSectionPosy, LastSectionPosz FROM userver2.characterinfo WHERE NickName = ? LIMIT 1");
		return;
	}

	Message_.Data = _Message->Data;
	SetPos(_Message->Data.Pos);
	SetDir(_Message->Data.Dir);
	
	// (_Message->Data.Pos - _Message->Data.Pos).Length2D();

	if (Message_.Data.GetState<EPlayerState>() == EPlayerState::PState_Att && IsAttack == false)
	{
		AttTime = GetAccTime();
		IsAttack = true;
		/*GetSection()->TCPBroadcasting(GetSerializePlayerUpdateMessage().GetData(), GetIndex());
		return;*/
	}
	BroadcastingPlayerUpdateMessage();
}

// Ŭ���̾�Ʈ���׼� ������ �Դ�.
void Player::ClientToReadyMessageProcess(std::shared_ptr<ClientToReadyMessage> _Message)
{
	// �ʹ� �߿��ؼ� tcp�� ������.
	//// ���� �÷��̾� ��Ŷ ����
	{
		const std::list<std::shared_ptr<GameServerActor>>& AllOtherPlayer = GetSection()->GetPlayableActor();

		PlayersUpdateMessage Message;
		GameServerSerializer Sr;

		for (auto& OtherActor : AllOtherPlayer)
		{
			// ���� ����
			if (GetIndex() == OtherActor->GetIndex())
			{
				continue;
			}

			std::shared_ptr<Player> OtherPlayer = std::dynamic_pointer_cast<Player>(OtherActor);

			OtherPlayer->GetSerializePlayerUpdateMessage();
			Message.Datas.push_back(OtherPlayer->Message_.Data);
		}

		// �ֺ� ĳ���͵� ���δ� ������ ���.
		Message.Serialize(Sr);
		GetTCPSession()->Send(Sr.GetData());
		BroadcastingPlayerUpdateMessage();
	}

	SelfTCPMessage(GetSerializePlayerUpdateMessage().GetData());
}


void Player::ChatMessageProcess(std::shared_ptr<class ChatMessage> _Message)
{
	GameServerSerializer Sr;
	_Message->Serialize(Sr);

	SelfTCPMessage(Sr.GetData());
}

void Player::LevelMoveReplyMessageProcess(std::shared_ptr<class LevelMoveReplyMessage> _Message)
{
	if (nullptr == PortalPtr)
	{
		GameServerDebug::AssertDebugMsg("��Ż�� �߸��� ��ü�� �� �־����ϴ�.");
		return;
	}

	LevelMoveMessage Msg;
	Msg.ObjectIndex = GetIndex();
	Msg.SectionIndex = GetSectionIndex();
	Msg.ThreadIndex = GetThreadIndex();
	Msg.MoveLevel = PortalPtr->LinkSection->GetNameCopy();
	GameServerSerializer Sr;
	Msg.Serialize(Sr);
	GetSection()->TCPBroadcasting(Sr.GetData(), GetIndex());

	GetSection()->SectionMove(DynamicCast<GameServerActor>(), PortalPtr->LinkSection);
	PortalPtr = nullptr;
}

void Player::Update(float _DeltaTime) 
{
	MessageCheck();

	if (nullptr == AttackCollision)
	{
		return;
	}

	AttackCollision->SetPivot(GetDir() * 105.f);

	//Attack Check
	if (IsAttack && GetAccTime() - AttTime >= 0.5f)
	{
		AttackCollisionCheck();
		AttTime = 0;
		IsAttack = false;
	}

	if (0 == (static_cast<int>(GetAccTime()) % 10) )
	{
		// DBQueue::Queue(std::bind(_ChildFunction, std::dynamic_pointer_cast<ChildThreadHandler>(this->shared_from_this())));

		std::string Name = UserData->SelectData.NickName;

		DBQueue::Queue([=]
		{
			std::shared_ptr<RedisConnecter> Connecter = GetBaseRankConntor();
			RedisCommend::ZADD MyAdd = RedisCommend::ZADD("UserRank", 10000, Name);
			MyAdd.Process(*Connecter);
		});
		// dbqueue
	}

	if (IsFrame(10))
	{
		if (nullptr == HitCollision)
		{
			return;
		}

		static std::vector<GameServerCollision*> Result;
		// �浹 �߾� ���߾�?

		if (true == HitCollision->CollisionCheckResult(CollisionCheckType::SPHERE, ECollisionGroup::POTAL, CollisionCheckType::SPHERE, Result))
		{
			PortalPtr = Result[0]->GetOwnerActorConvert<Portal>();

			if (nullptr == PortalPtr)
			{
				GameServerDebug::AssertDebugMsg("��Ż�� �߸��� ��ü�� �� �־����ϴ�.");
				return;
			}

			// ���ƿ��� ��Ŷ�鵵 �� �����ؾ���.


			// ������ �ִ� �ٸ� ���͵鿡�� �������ϴ� �޼����� �˴ϴ�.
			LevelMoveMessage Msg;
			Msg.ObjectIndex = GetIndex();
			Msg.SectionIndex = GetSectionIndex();
			Msg.ThreadIndex = GetThreadIndex();
			Msg.MoveLevel = PortalPtr->LinkSection->GetNameCopy();
			GameServerSerializer Sr;
			Msg.Serialize(Sr);
			// GetSection()->TCPBroadcasting(Sr.GetData(), GetIndex());

			// Off();

			GetTCPSession()->Send(Sr.GetData());


			HitCollision->Death();
			HitCollision = nullptr;
			AttackCollision->Death();
			AttackCollision = nullptr;


		}

		Result.clear();

	}

	// ���� �����

}

PlayerUpdateMessage& Player::GetPlayerUpdateMessage()
{
	Message_.Data.Dir = GetDir();
	Message_.Data.Pos = GetPos();

	return Message_;
}

GameServerSerializer& Player::GetSerializePlayerUpdateMessage()
{
	Message_.Data.Dir = GetDir();
	Message_.Data.Pos = GetPos();

	Serializer_.Reset();

	Message_.Serialize(Serializer_);

	return Serializer_;
}

void Player::BroadcastingPlayerUpdateMessage() 
{
	GetSection()->UDPBroadcasting(GetSerializePlayerUpdateMessage().GetData(), GetIndex());
}

//void Player::SelfUpdateMessage(std::vector<unsigned char> data)
//{
//	GetTCPSession()->Send(data);
//}

void Player::SelfTCPMessage(std::vector<unsigned char> data)
{
	GetTCPSession()->Send(data);
}

bool Player::InsertSection() 
{
	if (nullptr == UserData)
	{
		GameServerDebug::AssertDebugMsg("UserData Setting Is Nullptr");
		return false;
	}

	Message_.Data.ObjectIndex = GetIndex();
	Message_.Data.SectionIndex = GetSectionIndex();
	Message_.Data.ThreadIndex = GetThreadIndex();
	
	// SetPos({200, 0.0f, 0.0f});

	// ���� ���� ��Ŷ ����
	{
		SectionInsertResultMessage Msg;
		Msg.Code = EGameServerCode::OK;
		Msg.UDPPort = GetUDPPort();
		Msg.ObjectIndex = GetIndex();
		Msg.SectionIndex = GetSectionIndex();
		Msg.ThreadIndex = GetThreadIndex();
		Msg.MoveLevel = GetSection()->GetNameCopy();
		GameServerSerializer Sr;
		Msg.Serialize(Sr);
		GetTCPSession()->Send(Sr.GetData());
	}

	SetPos(FVector4::ZeroVector);

	// Ŭ���̾�Ʈ�� ���� �غ� �ƴ�.



	GameServerDebug::LogInfo("Select Result OK Send");

	return true;
}

void Player::SectionInitialize() 
{
	// GetSection();
	if (nullptr == HitCollision)
	{
		HitCollision = GetSection()->CreateCollision(ECollisionGroup::PLAYER, this);
		HitCollision->SetScale({ 50.0f, 50.0f, 50.0f });
	}
	if (nullptr == AttackCollision)
	{
		AttackCollision = GetSection()->CreateCollision(ECollisionGroup::PLAYER, this);
		AttackCollision->SetScale({ 125.0f, 125.0f, 100.0f });
	}
	UDPReady_ = false;
}

void Player::TCPSessionInitialize() 
{
	UserData = GetTCPSession()->GetLink<ContentsUserData>(EDataIndex::USERDATA);

	if (nullptr == UserData)
	{
		GameServerDebug::AssertDebugMsg("UserData Setting Is Nullptr");
		return;
	}
}

void Player::UDPSessionInitialize()
{

	int a = 0;
}

void Player::DeathEvent()
{
	// GetSession()->UnregisterSession();
	{
		const std::list<std::shared_ptr<GameServerActor>>& AllOtherPlayer = GetSection()->GetPlayableActor();

		ObjectDestroyMessage Message;
		Message.ObjectID = GetIndex();

		GameServerSerializer Sr;
		Message.Serialize(Sr);

		for (auto& OtherActor : AllOtherPlayer)
		{
			// ���� ����
			if (GetIndex() == OtherActor->GetIndex())
			{
				continue;
			}
			std::shared_ptr<Player> OtherPlayer = std::dynamic_pointer_cast<Player>(OtherActor);
			OtherPlayer->GetTCPSession()->Send(Sr.GetData());
		}
	}
	
	/*PlayerDestroyMessage Message;
	GameServerSerializer Sr;
	Message.Serialize(Sr);
	GetTCPSession()->Send(Sr.GetData());*/
}

void Player::DisConnect()
{
	//// ���� �÷��̾� ��Ŷ ����

}