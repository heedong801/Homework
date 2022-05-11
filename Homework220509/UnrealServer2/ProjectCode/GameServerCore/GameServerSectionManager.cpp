#include "PreCompile.h"
#include "GameServerSectionManager.h"

GameServerSectionManager* GameServerSectionManager::Inst_ = new GameServerSectionManager();

GameServerSectionManager::GameServerSectionManager() 
{
}

GameServerSectionManager::~GameServerSectionManager() 
{
	for (size_t i = 0; i < SecitonThread_.size(); i++)
	{
		SecitonThread_[i]->SectionThreadQueue.Destroy();
	}
}

void GameServerSectionManager::Init(int _Count, const std::string& _Name) 
{
	for (uint64_t i = 0; i < _Count; i++)
	{
		std::shared_ptr<GameServerSectionThread> NewThread = std::make_shared<GameServerSectionThread>();
		NewThread->StartSectionThread(static_cast<int>(i));
		NewThread->SetIndex(i);
		NewThread->SetName(_Name + std::to_string(i));
		SecitonThread_.push_back(NewThread);
	}

}

// 만들면서 쓰레드에 집어넣어야 하죠?
void GameServerSectionManager::InsertSection(int _ThreadIndex, uint64_t _Key, std::shared_ptr<GameServerSection> _Section)
{
	if (nullptr == _Section)
	{
		return;
	}

	{
		std::lock_guard<std::mutex> lock(SectionMutex_);
		_Section->SetIndex(_Key);
		_Section->SetThreadIndex(_ThreadIndex);
		_Section->Init();
		AllSection_.insert(std::unordered_map<uint64_t, std::shared_ptr<GameServerSection>>::value_type(_Key, _Section));
		SecitonThread_[_ThreadIndex]->AddSection(_Section);
	}

	return;
}

uint32_t GameServerSectionManager::RemoveSection(int _ThreadIndex, uint32_t _SectionNumber)
{
	std::lock_guard<std::mutex> lock(SectionMutex_);
	AllSection_.erase(_SectionNumber);
	return _SectionNumber;
}

std::shared_ptr<GameServerSection> GameServerSectionManager::FindSection(uint64_t _Key) 
{
	std::lock_guard<std::mutex> lock(SectionMutex_);
	std::unordered_map<uint64_t, std::shared_ptr<GameServerSection>>::iterator FindIter = AllSection_.find(_Key);
	if (FindIter == AllSection_.end())
	{
		return nullptr;
	}
	return FindIter->second;
}

// uint64_t ThreadIndex, uint64_t SectionIndex, uint64_t ObjectIndex, std::shared_ptr<GameServerMessage> _Message
// 그걸 애가 알리가 없죠.

void GameServerSectionManager::MessagePost(uint64_t ThreadIndex, std::function<void()> _CallBack)
{
	// 그게 잡 쓰레드일 뿐입니다.
	SecitonThread_[ThreadIndex]->SectionThreadQueue.EnQueue(_CallBack);
}

void GameServerSectionManager::ActorPost(uint64_t ThreadIndex, uint64_t SectionIndex, uint64_t ObjectId, std::shared_ptr<GameServerMessage> _Message)
{
	if (SecitonThread_.size() <= ThreadIndex)
	{
		GameServerDebug::AssertDebugMsg("존재하지 않는 섹션에 메세지를 보냈습니다.");
		return;
	}

	std::shared_ptr<GameServerSectionThread> Thread = SecitonThread_[ThreadIndex];
	SecitonThread_[ThreadIndex]->SectionThreadQueue.EnQueue(std::bind(&GameServerSectionThread::ActorPost, Thread.get(), SectionIndex, ObjectId, _Message));
}

void GameServerSectionManager::ActorPointPost(uint64_t ThreadIndex, uint64_t SectionIndex, uint64_t ObjectId, const IPEndPoint& _Point, std::shared_ptr<GameServerMessage> _Message)
{
	if (SecitonThread_.size() <= ThreadIndex)
	{
		GameServerDebug::AssertDebugMsg("존재하지 않는 섹션에 메세지를 보냈습니다.");
		return;
	}

	std::shared_ptr<GameServerSectionThread> Thread = SecitonThread_[ThreadIndex];
	SecitonThread_[ThreadIndex]->SectionThreadQueue.EnQueue(std::bind(&GameServerSectionThread::ActorPointPost, Thread.get(), SectionIndex, ObjectId, _Point, _Message));
}