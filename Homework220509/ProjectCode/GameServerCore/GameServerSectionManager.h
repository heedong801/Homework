#pragma once
#include <vector>
#include <GameServerBase\GameServerThread.h>
#include <unordered_map>
#include "GameServerSection.h"
#include "GameServerSectionThread.h"
#include <GameServerMessage\GameServerMessage.h>

// 룸에게 직접 쏴주는 방식과
// 쓰레드에게 직접 쏴주는 방식이 있을겁니다.
// 쓰레드가 큐를 가집니다.
// #include <GameServerBase\GameServerQueue.h>

// 아무리 서로 쓰레드가 다르고 각자 처리하는 일이 있다고 하더라도
// A 룸에서 혹은 아예 다른 쓰레드에서 돌아가고있는 X룸
// 되도록이면 최대한 없으면
// EX 귓속말은 서버를 따로 틉니다.
// 선생님 서버에서는 채팅용 서버를 따로 두지는 않겠지만.
// 채팅용 서버라도 
// 디아블로는? 

// 설명 : 모든 룸을 다 들고 있습니다.
class GameServerSectionManager
{
private:
	static GameServerSectionManager* Inst_;

public:
	static GameServerSectionManager* GetInst() 
	{
		return Inst_;
	}

	static void Destroy() 
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}

	// 아무것도 안넣어주면 우리의 쓰레드 처리 방식을 따르겠다는 것이고
	// 넣어주면. 너희가 직접 쓰레드들을 지정하겠다는 이야기가 되죠?
	// 쓰레드들을 지정하려면 귀찮아지게 됩니다.
	template<typename SectionType, typename EnumType, typename ... Parameter>
	std::shared_ptr<SectionType> CreateSection(int _ThreadIndex, EnumType _Index, Parameter ... Arg)
	{
		return CreateSection<SectionType>(_ThreadIndex, static_cast<uint64_t>(_Index), Arg...);
	}

	// 룸의 인덱스가 자동배치냐.
	// 키를 우리가 직접 넣어줘야 하면.
	// 더 세부로 해서 이녀석을 완전히 온리 1개의 쓰레드에게 맡기겠다.
	template<typename SectionType, typename ... Parameter>
	std::shared_ptr<SectionType> CreateSection(int _ThreadIndex, uint64_t _Index, Parameter ... Arg)
	{
		std::shared_ptr<SectionType> NewSection = std::make_shared<SectionType>(Arg...);
		InsertSection(_ThreadIndex, _Index, NewSection);
		return NewSection;
	}

	void InsertSection(int _ThreadIndex, uint64_t Key, std::shared_ptr<GameServerSection> _Section);

	uint32_t RemoveSection(int _ThreadIndex, uint32_t _SectionNumber);

	std::shared_ptr<GameServerSection> FindSection(uint64_t Key);

	// delete Function
	GameServerSectionManager(const GameServerSectionManager& _Other) = delete;
	GameServerSectionManager(GameServerSectionManager&& _Other) noexcept = delete;
	GameServerSectionManager& operator=(const GameServerSectionManager& _Other) = delete;
	GameServerSectionManager& operator=(GameServerSectionManager&& _Other) noexcept = delete;

	void Init(int _Count, const std::string& _Name);

	//void SectionAddMessage(int _QueueIndex, 메세지);
	//std::vector<GameServerQueue*> SecitonThread_;

	// 각 쓰레드에게 메세지를 쏴준다.
	// 섹션한테 바로 쏴주면 안되나요?
	// 섹션은 하나의 자료구조로 관리하고 있기 때문에
	// 곧바로 섹션에게 쏘는 순간 언제나 락을 걸어줘야 하게 된다.
	// 그럴거면 애초에 이렇게 안만들었다.
	// 그냥 다 락걸고 사용하고 말지
	void MessagePost(uint64_t ThreadIndex, std::function<void()> _CallBack);

	void ActorPost(uint64_t ThreadIndex, uint64_t SectionIndex, uint64_t ObjectId, std::shared_ptr<GameServerMessage> _Message);

	void ActorPointPost(uint64_t ThreadIndex, uint64_t SectionIndex, uint64_t ObjectId, const IPEndPoint& _Point, std::shared_ptr<GameServerMessage> _Message);

protected:

private:
	std::vector<std::shared_ptr<GameServerSectionThread>> SecitonThread_;

	std::mutex SectionMutex_;
	std::unordered_map<uint64_t, std::shared_ptr<GameServerSection>> AllSection_;

	GameServerSectionManager();
	~GameServerSectionManager();
};

