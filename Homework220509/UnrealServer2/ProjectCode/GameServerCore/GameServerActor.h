#pragma once
#include <GameServerBase\GameServerObjectBase.h>
#include <GameServerBase\GameServerMath.h>
#include <GameServerNet\IPEndPoint.h>
#include "GameServerCollision.h"

// 내가 주 배정쓰레드 2번인데. 1번쓰레드
//if (GetThreadIndex() != GameServerThread::GetThreadOrder())
//{
//   이런 예외처리도 굉장히 많이 볼수 있는데 사람들이 코드를 짜다가
//   어떤 객체를 어떤 쓰레드가 책임지겠다고 했는데 다른쓰레드에서 접근해서 무슨짓을 하려고 하면
//	 return;
//}

// 설명 :
class UDPSession;
class TCPSession;
class GameServerSection;
class GameServerMessage;
class GameServerActor : public GameServerObjectBase, public GameServerNameBase
{
	friend GameServerSection;

public:
	uint64_t GetIndex()
	{
		return Index_;
	}

	uint64_t GetThreadIndex()
	{
		return ThreadIndex_;
	}

	uint64_t GetSectionIndex()
	{
		return SectionIndex_;
	}

	bool IsEmptyMessage() 
	{
		return Messagequeue_.empty();
	}

	std::shared_ptr<GameServerMessage> PopMessage() 
	{
		if (true == Messagequeue_.empty())
		{
			return nullptr;
		}

		std::shared_ptr<GameServerMessage> Message = Messagequeue_.front();
		Messagequeue_.pop();
		return Message;
	}

	bool GetSectionCompare(GameServerSection* _Value)
	{
		return Section_ == _Value;
	}

	inline bool IsSectionMove()
	{
		return IsSectionMove_;
	}

	// constrcuter destructer
	GameServerActor();
	~GameServerActor();

	// delete Function
	GameServerActor(const GameServerActor& _Other) = delete;
	GameServerActor(GameServerActor&& _Other) noexcept = delete;
	GameServerActor& operator=(const GameServerActor& _Other) = delete;
	GameServerActor& operator=(GameServerActor&& _Other) noexcept = delete;

protected:
	GameServerSection* GetSection()
	{
		return Section_;
	}

	std::shared_ptr<TCPSession> GetTCPSession()
	{
		return TCPSession_;
	}

	std::shared_ptr<UDPSession> GetUDPSession()
	{
		return UDPSession_;
	}

	int GetUDPPort()
	{
		return UDPPort_;
	}

	virtual void SectionInitialize() = 0;
	virtual void TCPSessionInitialize() = 0;
	virtual void UDPSessionInitialize() = 0;


private:
	GameServerSection* Section_;

	void SetSection(GameServerSection* _Section)
	{
		Section_ = _Section;
		if (nullptr != Section_)
		{
			SectionInitialize();
		}
	}

	std::shared_ptr<TCPSession> TCPSession_;

	void SetTCPSession(std::shared_ptr<TCPSession> _Session)
	{
		TCPSession_ = _Session;
		TCPSessionInitialize();
	}

	std::shared_ptr<UDPSession> UDPSession_;
	int UDPPort_;

	bool IsFirstUDPMessage = false;

	std::atomic<bool> IsSectionMove_;

	inline void SectionMoveEnd()
	{
		IsSectionMove_ = false;
	}

	// 유저의 ip와 port
	IPEndPoint UDPEndPoint;

	IPEndPoint GetUDPEndPoint()
	{
		return UDPEndPoint;
	}

	const IPEndPoint& GetUDPEndPointConstRef() const
	{
		return UDPEndPoint;
	}


	void SetUDPEndPoint(const IPEndPoint& _UDPEndPoint)
	{
		UDPEndPoint = _UDPEndPoint;
	}

	void SetUDPSession();



	uint64_t Index_;
	uint64_t ThreadIndex_;
	uint64_t SectionIndex_;




	void SetIndex(uint64_t _Index)
	{
		Index_ = _Index;
	}

	void SetSectionIndex(uint64_t _Index)
	{
		SectionIndex_ = _Index;
	}

	void SetThreadIndex(uint64_t _Index)
	{
		ThreadIndex_ = _Index;
	}

	virtual void Update(float _Time) = 0;

	virtual bool InsertSection() = 0;

	virtual void DeathEvent() = 0;

	virtual void PlayerbleActorEvent(GameServerActor* _Actor) {}
	virtual void AIActorEvent(GameServerActor* _Actor) {}


	std::queue<std::shared_ptr<GameServerMessage>> Messagequeue_;

///////////////////////////////////////////
private:
	// 클라이언트 적으로 봤을때는 위치가 
	// ??? 말이 되???
	// 위치 어쩌라고?????
	// 기하 서버가 지원해준다?
	// 오히려 도움이 안되는겁니다.
	FVector4 Pos_;
	FVector4 Scale_;
	FVector4 Dir_;

public:
	FVector4 GetPos()
	{
		return Pos_;
	}

	// 서버의 메모리
	FVector4 GetDir()
	{
		return Dir_;
	}

	void SetPos(const FVector4& _Value)
	{
		Pos_ = _Value;
	}

	void SetScale(const FVector4& _Value)
	{
		Scale_ = _Value;
	}

	void SetDir(const FVector4& _Value)
	{
		Dir_ = _Value;
	}

	void Move(const FVector4& _Value)
	{
		Pos_ += _Value;
	}
};
