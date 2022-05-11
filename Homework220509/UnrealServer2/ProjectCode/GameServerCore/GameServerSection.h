#pragma once
#include <GameServerBase\GameServerObjectBase.h>
#include <GameServerBase\GameServerUnique.h>
#include <GameServerNet\IPEndPoint.h>

// 설명 :
class GameServerCollision;
class TCPSession;
class GameServerActor;
class GameServerMessage;
class GameServerSection : public GameServerObjectBase, public GameServerNameBase
{
	friend class GameServerSectionThread;
	friend class GameServerSectionManager;
	friend class GameServerCollision;

private:
	class MoveActorData
	{
	public:
		std::shared_ptr<GameServerActor> MoveActor;
		GameServerSection* NextSection;
	};

public:
	// constrcuter destructer
	GameServerSection();
	virtual ~GameServerSection();

	// delete Function
	GameServerSection(const GameServerSection& _Other) = delete;
	GameServerSection(GameServerSection&& _Other) noexcept = delete;
	GameServerSection& operator=(const GameServerSection& _Other) = delete;
	GameServerSection& operator=(GameServerSection&& _Other) noexcept = delete;

	// std::vector<GameServerActor>
	virtual bool Init() = 0;

	bool Update(float _Time);
	void Release();

	inline uint64_t GetIndex()
	{
		return Index_;
	}

	uint64_t GetThreadIndex()
	{
		return ThreadIndex_;
	}

	template<typename ActorType, typename ... Parameter>
	std::shared_ptr<ActorType> CreateActor(Parameter ... Arg)
	{
		uint64_t ReturnId = GameServerUnique::GetNextUniqueId();
		std::shared_ptr<ActorType> NewActor = CreateActor<ActorType>(ReturnId, Arg...);
		return NewActor;
	}

	template<typename ActorType, typename ... Parameter>
	std::shared_ptr<ActorType> CreateActor(std::shared_ptr<TCPSession> _Session, Parameter ... Arg)
	{
		uint64_t ReturnId = GameServerUnique::GetNextUniqueId();
		std::shared_ptr<ActorType> NewActor = CreateActor<ActorType>(_Session, ReturnId, Arg...);
		return NewActor;
	}


	// 룸의 인덱스가 자동배치냐.
	// 키를 우리가 직접 넣어줘야 하면.
	// 더 세부로 해서 이녀석을 완전히 온리 1개의 쓰레드에게 맡기겠다.
	template<typename ActorType, typename ... Parameter>
	std::shared_ptr<ActorType> CreateActor(uint64_t _ID, Parameter ... Arg)
	{
		std::shared_ptr<ActorType> NewActor = std::make_shared<ActorType>(Arg...);
		NewActor->SetIndex(_ID);
		InsertActor(_ID, std::dynamic_pointer_cast<GameServerActor>(NewActor));
		return NewActor;
	}

	template<typename ActorType, typename ... Parameter>
	std::shared_ptr<ActorType> CreateActor(std::shared_ptr<TCPSession> _Session, uint64_t _ID, Parameter ... Arg)
	{
		std::shared_ptr<ActorType> NewActor = std::make_shared<ActorType>(Arg...);
		NewActor->SetIndex(_ID);
		NewActor->SetTCPSession(_Session);
		NewActor->SetUDPSession();
		InsertActor(_ID, std::dynamic_pointer_cast<GameServerActor>(NewActor));
		return NewActor;
	}

	void TCPBroadcasting(const std::vector<unsigned char>& _Buffer, uint64_t _IgnoreIndex = -1);

	void UDPBroadcasting(const std::vector<unsigned char>& _Buffer, uint64_t _IgnoreIndex = -1);

	const std::list<std::shared_ptr<GameServerActor>>& GetPlayableActor()
	{
		return PlayableActor_;
	}

	void MoveActor(std::shared_ptr<GameServerActor> _Actor);

	/*DynamicCast<GameServerActor>(), PortalPtr->LinkSection*/
	void SectionMove(std::shared_ptr<GameServerActor> _MoveActor, GameServerSection* _MoveSection );

protected:




private:
	// 1번맵의 2번채널
	inline void SetIndex(uint64_t _Index)
	{
		Index_ = _Index;
	}

	// 내가 5번째 쓰레드에 있다.
	// 5번째 쓰레드에있는 xx 룸에 이 메세지를 전달해줘.
	inline void SetThreadIndex(uint64_t _Index)
	{
		ThreadIndex_ = _Index;
	}

	// 플레이어는 자기가 들어가 룸을 이 번호로 알아낼 것이다.
	// 이 룸이 어떤 룸인지에 대한 보관용 
	uint64_t Index_; // 유저들이 인식하는 키와


	// 5번째 쓰레드에 있다는 
	uint64_t ThreadIndex_; // 

	GameServerSectionThread*  GetThread()
	{
		return Thread_;
	}

	////////////////// 액터관리
private:
	virtual void UserUpdate() = 0;

	void InsertActor(uint64_t _ID, std::shared_ptr<GameServerActor> _Actor);

	GameServerSectionThread* Thread_;

	void SetThread(GameServerSectionThread* _Thread)
	{
		Thread_ = _Thread;
	}

	// 모든 액터는 고유의 키를 가지게 되고.
	// 1
	std::map<uint64_t, std::shared_ptr<GameServerActor>> KeyActor_;

	std::list<std::shared_ptr<GameServerActor>> AIActor_;
	std::list<std::shared_ptr<GameServerActor>> PlayableActor_;

	std::atomic<size_t> WaitActorCount_;
	std::mutex WaitLock;
	std::vector<std::shared_ptr<GameServerActor>> WaitActor_;

	std::vector<MoveActorData> MoveActors_;

public:
	void ActorPost(uint64_t _ObjectIndex, std::shared_ptr<GameServerMessage> _Message);
	void ActorPointPost(uint64_t _ObjectIndex, const IPEndPoint& _EndPoint, std::shared_ptr<GameServerMessage> _Message);

	const std::list<std::shared_ptr<GameServerActor>>& GetAiActors() 
	{
		return AIActor_;
	}

private:
	// 느린데 리스트로 하겠습니다.
	// 벡터로 했을때 처리를 잘 해줄수 있을거 같지가 않아요.
	std::map<int, std::list<GameServerCollision*>> CollisionList;
	///////////////////

public:
	// int Order 이 충돌체가 어떤 그룹에 속했는지 처리합니다.
	// 이 콜리전의 주인이 누구인지 처리합니다.
	template<typename EnumType>
	GameServerCollision* CreateCollision(EnumType _Order, GameServerActor* _Owner)
	{
		return CreateCollision(static_cast<int>(_Order), _Owner);
	}
	GameServerCollision* CreateCollision(int Order, GameServerActor* _Owner);
};

