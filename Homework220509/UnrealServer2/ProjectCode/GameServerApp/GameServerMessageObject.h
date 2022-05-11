#pragma once
#include <queue>
#include <GameServerBase\GameServerNameBase.h>
#include <GameServerMessage\GameServerMessage.h>


// 설명 : 각 액터마다 쓰레드에 안전하게 만들거냐
// 액터업데이트 기반
// 쓰레드가 필요한 액터들을 필요할때마다 쓰레드로 돌려주는것

// 쓰레드를 돌릴때 

// 설명 : 월드나 룸단위로 쓰레드에 안전하게 만들거냐
// 락을 걸거라는
// 내가 길드에 뭔가를 요청하는 도중에 누군가 나에게 우편을 보냈어
// 길드와 우편은 각각 의쓰레드에서 처리된다음 그 결과를 알려줘야하는 나에게 메세지를 다시보내겠죠?
// 동시에 5개가 될지 6개가 될지 알수가 없죠?

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

