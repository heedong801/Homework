#pragma once
#include <GameServerCore\GameServerActor.h>
#include "ServerAndClient.h"
#include <GameServerNet\RedisConnecter.h>
// 설명 :
class ContentsUserData;
class Player : public GameServerActor
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

private:
	std::shared_ptr<RedisConnecter> GetBaseRankConntor() 
	{
		return RedisConnecter::GetConnector(0);
	}

	//std::shared_ptr<RedisConnecter> GetRegulerRankConntor()
	//{
	//	return RedisConnecter::GetConnector(1);
	//}

public:
	void MessageCheck();

	void ClientToReadyMessageProcess(std::shared_ptr<class ClientToReadyMessage> _Message);
	void PlayerUpdateMessageProcess(std::shared_ptr<class PlayerUpdateMessage> _Message);
	void LevelMoveReplyMessageProcess(std::shared_ptr<class LevelMoveReplyMessage> _Message);
	

protected:
	PlayerUpdateMessage& GetPlayerUpdateMessage();
	GameServerSerializer& GetSerializePlayerUpdateMessage();

	void SelfUpdateMessage();
	void BroadcastingPlayerUpdateMessage();

private:
	class Portal* PortalPtr;

	// std::shared_ptr<GameServerCollision> HitCollision;
	GameServerCollision* HitCollision;

	PlayerUpdateMessage Message_;
	GameServerSerializer Serializer_;

	std::shared_ptr<ContentsUserData> UserData;

	bool UDPReady_;

	void Update(float _Time) override;

	void SectionInitialize() override;
	void TCPSessionInitialize() override;
	void UDPSessionInitialize() override;

	bool InsertSection() override;

	// 객체로서 삭제되는 것
	void DeathEvent() override;

	// 이건 지금 섹션에서도 삭제되기 직전이고
	// 완전히 메모리가 정리되기 직전에 호출되는것
	void DisConnect();

};

