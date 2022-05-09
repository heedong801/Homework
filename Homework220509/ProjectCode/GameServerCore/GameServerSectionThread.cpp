#include "PreCompile.h"
#include "GameServerSectionThread.h"
#include <GameServerBase\GameServerDebug.h>

GameServerSectionThread::GameServerSectionThread() 
{
	Sections_.reserve(100);
}

GameServerSectionThread::~GameServerSectionThread() 
{
}

// 쓰레드 실행함수.
void GameServerSectionThread::ThreadFunction(int _Index)
{
	ThreadNameSetting(GetNameCopy());
	SetThreadOrder(_Index);

	SectionThreadQueue.Initialize(1);
	SectionThreadQueue.SetExecuteWorkType(GameServerQueue::WORK_TYPE::Default);
	Timer_.Reset();

	GameServerQueue::QUEUE_RETURN Result = GameServerQueue::QUEUE_RETURN::OK;

	while (GameServerQueue::QUEUE_RETURN::DESTROY != Result)
	{
		Result = GameServerQueue::QUEUE_RETURN::OK;

		// 이쓰레드에 들어온 일을 다처리하고 나가는 겁니다.

		while (Result == GameServerQueue::QUEUE_RETURN::OK)
		{
			Result = SectionThreadQueue.Execute(1);
		}

		if (GameServerQueue::QUEUE_RETURN::DESTROY == Result)
		{
			// 뭔가 삭제하거나 해제할 뭔가가 있으면 여기서 처리.
			// 디스트로이
			return;
		}

		// 여기서 분류작업을 거쳐서 각 섹션에게 전달된 겁니다.

		if (0 != InsertSectionSize_)
		{
			std::lock_guard Lock(InsertLock_);
			for (size_t i = 0; i < InsertSections_.size(); i++)
			{
				InsertSections_[i]->AccTimeReset();
				Sections_.push_back(InsertSections_[i]);
				KeySections_.insert(std::make_pair(InsertSections_[i]->GetIndex(), InsertSections_[i]));
			}
			InsertSections_.clear();
			InsertSectionSize_ = 0;
		}

		// Thread마다 타이머를 가져야 동기화 문제와 시간 문제에 대해서 신경쓰지 않을수 있다.
		float DelataTime =Timer_.Update();

		for (size_t i = 0; i < Sections_.size(); i++)
		{
			if (false == Sections_[i]->IsUpdate())
			{
				continue;
			}

			// 이게 한프레임인겁니다.
			Sections_[i]->AccTimeUpdate(DelataTime);
			Sections_[i]->Update(DelataTime);
			Sections_[i]->Release();
		}

		// 머신의 코어개수를 인지하고 있을것이고
		// 코어대비 쓰레드 개수가 많을때 아래와 같이 걸게 됩니다.
		// 정답이 없습니다.
		// 전략을 세울수도 있습니다.
		// 16 10개를 풀로 돌리기로 했다. 
		Sleep(1);

		// 락을 최소한으로 걸겠습니다.
	}
}

void GameServerSectionThread::AddSection(std::shared_ptr<GameServerSection> _Section) 
{
	++InsertSectionSize_;
	_Section->SetThread(this);
	InsertSections_.push_back(_Section);
}

void GameServerSectionThread::RemoveSection(std::shared_ptr<GameServerSection> _Section)
{
	// 빼는게 답이 없다.
	// 이녀석은 락을 걸어야 하겠네요.

	if (nullptr == _Section)
	{
		GameServerDebug::LogErrorAssert("Section Is null");
		return;
	}


	for (size_t i = 0; i < Sections_.size(); i++)
	{
		if (Sections_[i] == _Section)
		{
			// 락을 걸어야하는 메모리가 
			// 국한됩니다.
			Sections_[i]->IsDeath();
		}
	}

	++DeleteSectionSize_;

}

void GameServerSectionThread::StartSectionThread(int _Index)
{
	Start(std::bind(& GameServerSectionThread::ThreadFunction, this, _Index));
}

void GameServerSectionThread::ActorPost(uint64_t SectionIndex, uint64_t _ObjectIndex, std::shared_ptr<GameServerMessage> _Message)
{
	if (KeySections_.end() == KeySections_.find(SectionIndex))
	{
		GameServerDebug::AssertDebugMsg("존재하지 않는 섹션에 메세지를 보냈습니다.");
		return;
	}

	KeySections_[SectionIndex]->ActorPost(_ObjectIndex, _Message);
}

void GameServerSectionThread::ActorPointPost(uint64_t SectionIndex, uint64_t _ObjectIndex, const IPEndPoint& _EndPoint, std::shared_ptr<GameServerMessage> _Message)
{
	if (KeySections_.end() == KeySections_.find(SectionIndex))
	{
		GameServerDebug::AssertDebugMsg("존재하지 않는 섹션에 메세지를 보냈습니다.");
		return;
	}

	KeySections_[SectionIndex]->ActorPointPost(_ObjectIndex, _EndPoint, _Message);
}