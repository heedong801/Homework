#pragma once
#include <queue>
#include <GameServerBase\GameServerNameBase.h>
#include <GameServerMessage\GameServerMessage.h>


// ���� : �� ���͸��� �����忡 �����ϰ� ����ų�
// ���;�����Ʈ ���
// �����尡 �ʿ��� ���͵��� �ʿ��Ҷ����� ������� �����ִ°�

// �����带 ������ 

// ���� : ���峪 ������� �����忡 �����ϰ� ����ų�
// ���� �ɰŶ��
// ���� ��忡 ������ ��û�ϴ� ���߿� ������ ������ ������ ���¾�
// ���� ������ ���� �Ǿ����忡�� ó���ȴ��� �� ����� �˷�����ϴ� ������ �޼����� �ٽú�������?
// ���ÿ� 5���� ���� 6���� ���� �˼��� ����?

class GameServerLevel;
class GameServerMessageObject : public GameServerNameBase
{
public:
	friend GameServerLevel;
	std::queue<std::shared_ptr<GameServerMessage>> Messages_;

public:
	// constrcuter destructer
	GameServerMessageObject();
	~GameServerMessageObject();

	// delete Function
	GameServerMessageObject(const GameServerMessageObject& _Other) = delete;
	GameServerMessageObject(GameServerMessageObject&& _Other) noexcept = delete;
	GameServerMessageObject& operator=(const GameServerMessageObject& _Other) = delete;
	GameServerMessageObject& operator=(GameServerMessageObject&& _Other) noexcept = delete;

protected:
	virtual void Update(float _DeltaTime);

private:

};

