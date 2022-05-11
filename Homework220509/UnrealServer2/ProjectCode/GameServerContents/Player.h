#pragma once
#include <GameServerCore\GameServerActor.h>
#include "ServerAndClient.h"

// ���� :
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

	bool IsAttack;
	// std::shared_ptr<GameServerCollision> HitCollision;
	GameServerCollision* HitCollision;
	GameServerCollision* AttackCollision;
	PlayerUpdateMessage Message_;
	GameServerSerializer Serializer_;

	std::shared_ptr<ContentsUserData> UserData;

	bool UDPReady_;

	void Update(float _Time) override;

	void SectionInitialize() override;
	void TCPSessionInitialize() override;
	void UDPSessionInitialize() override;

	bool InsertSection() override;

	// ��ü�μ� �����Ǵ� ��
	void DeathEvent() override;

	// �̰� ���� ���ǿ����� �����Ǳ� �����̰�
	// ������ �޸𸮰� �����Ǳ� ������ ȣ��Ǵ°�
	void DisConnect();

};

