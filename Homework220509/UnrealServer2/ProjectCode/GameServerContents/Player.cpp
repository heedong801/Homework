#include "PreCompile.h"
#include "Player.h"
#include "Portal.h"
#include "ClientToServer.h"
#include "ServerToClient.h"
#include "GameServerCore\GameServerCore.h"
#include "GameServerBase\GameServerThread.h"

#include <GameServerNet\TCPSession.h>
#include "ContentsSystemEnum.h"
#include "ContentsUserData.h"
#include "CharacterTable.h"
#include "GameServerBase\GameServerDebug.h"
#include <GameServerCore\GameServerSection.h>
#include <GameServerCore\DBQueue.h>


Player::Player()
	: UDPReady_(false)
	, PortalPtr(nullptr)
	, HitCollision(nullptr)
{
}

Player::~Player() 
{

	if (nullptr != HitCollision)
	{
		HitCollision->Death();
		HitCollision = nullptr;
	}
}

void Player::PlayerUpdateMessageProcess(std::shared_ptr<class PlayerUpdateMessage> _Message)
{
	// 이게 만약 처음으로 날아온 메세지라면.
	// 너한테 쏠수 있게 되었다.

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

	// (_Message->Data.Pos - _Message->Data.Pos).Length2D();

	SetPos(_Message->Data.Pos);
	BroadcastingPlayerUpdateMessage();
}

// 클라이언트한테서 연락이 왔다.
void Player::ClientToReadyMessageProcess(std::shared_ptr<ClientToReadyMessage> _Message)
{
	// 너무 중요해서 tcp로 날린다.
	//// 주위 플레이어 패킷 보냄
	{
		const std::list<std::shared_ptr<GameServerActor>>& AllOtherPlayer = GetSection()->GetPlayableActor();

		PlayersUpdateMessage Message;
		GameServerSerializer Sr;

		for (auto& OtherActor : AllOtherPlayer)
		{
			// 나는 제외
			if (GetIndex() == OtherActor->GetIndex())
			{
				continue;
			}

			std::shared_ptr<Player> OtherPlayer = std::dynamic_pointer_cast<Player>(OtherActor);

			OtherPlayer->GetSerializePlayerUpdateMessage();
			Message.Datas.push_back(OtherPlayer->Message_.Data);
		}

		// 주변 캐릭터들 전부다 나한테 쏜다.
		Message.Serialize(Sr);
		GetTCPSession()->Send(Sr.GetData());
		BroadcastingPlayerUpdateMessage();
	}

	SelfUpdateMessage();
}

void Player::LevelMoveReplyMessageProcess(std::shared_ptr<class LevelMoveReplyMessage> _Message)
{
	if (nullptr == PortalPtr)
	{
		GameServerDebug::AssertDebugMsg("포탈에 잘못된 객체가 들어가 있었습니다.");
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
		// 충돌 했어 안했어?

		if (true == HitCollision->CollisionCheckResult(CollisionCheckType::SPHERE, ECollisionGroup::POTAL, CollisionCheckType::SPHERE, Result))
		{
			PortalPtr = Result[0]->GetOwnerActorConvert<Portal>();

			if (nullptr == PortalPtr)
			{
				GameServerDebug::AssertDebugMsg("포탈에 잘못된 객체가 들어가 있었습니다.");
				return;
			}

			// 날아오는 패킷들도 다 무시해야죠.


			// 주위에 있는 다른 액터들에게 보내야하는 메세지가 됩니다.
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

		}

		Result.clear();

	}

	// 버프 디버프

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

void Player::SelfUpdateMessage()
{
	GetTCPSession()->Send(GetSerializePlayerUpdateMessage().GetData());
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

	// 섹션 입장 패킷 보냄
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

	// 클라이언트가 나는 준비가 됐다.



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
			// 나는 제외
			if (GetIndex() == OtherActor->GetIndex())
			{
				continue;
			}

			std::shared_ptr<Player> OtherPlayer = std::dynamic_pointer_cast<Player>(OtherActor);
			OtherPlayer->GetTCPSession()->Send(Sr.GetData());
		}
	}

	PlayerDestroyMessage Message;
	GameServerSerializer Sr;
	Message.Serialize(Sr);
	GetTCPSession()->Send(Sr.GetData());
}

void Player::DisConnect()
{
	//// 주위 플레이어 패킷 보냄

}