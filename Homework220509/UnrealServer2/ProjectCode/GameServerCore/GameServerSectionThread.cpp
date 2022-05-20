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

// ������ �����Լ�.
void GameServerSectionThread::ThreadFunction(int _Index)
{
	SetThreadOrder(_Index);

	SectionThreadQueue.Initialize(1);
	SectionThreadQueue.SetExecuteWorkType(GameServerQueue::WORK_TYPE::Default);
	Timer_.Reset();

	GameServerQueue::QUEUE_RETURN Result = GameServerQueue::QUEUE_RETURN::OK;

	while (GameServerQueue::QUEUE_RETURN::DESTROY != Result)
	{
		Result = GameServerQueue::QUEUE_RETURN::OK;

		// �̾����忡 ���� ���� ��ó���ϰ� ������ �̴ϴ�.

		while (Result == GameServerQueue::QUEUE_RETURN::OK)
		{
			Result = SectionThreadQueue.Execute(1);
		}

		if (GameServerQueue::QUEUE_RETURN::DESTROY == Result)
		{
			// ���� �����ϰų� ������ ������ ������ ���⼭ ó��.
			// ��Ʈ����
			return;
		}

		// ���⼭ �з��۾��� ���ļ� �� ���ǿ��� ���޵� �̴ϴ�.

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

		// Thread���� Ÿ�̸Ӹ� ������ ����ȭ ������ �ð� ������ ���ؼ� �Ű澲�� ������ �ִ�.
		float DelataTime =Timer_.Update();

		for (size_t i = 0; i < Sections_.size(); i++)
		{
			if (false == Sections_[i]->IsUpdate())
			{
				continue;
			}

			// �̰� ���������ΰ̴ϴ�.
			Sections_[i]->AccTimeUpdate(DelataTime);
			Sections_[i]->Update(DelataTime);
			Sections_[i]->Release();
		}

		// �ӽ��� �ھ���� �����ϰ� �������̰�
		// �ھ��� ������ ������ ������ �Ʒ��� ���� �ɰ� �˴ϴ�.
		// ������ �����ϴ�.
		// ������ ������� �ֽ��ϴ�.
		// 16 10���� Ǯ�� ������� �ߴ�. 
		Sleep(1);

		// ���� �ּ������� �ɰڽ��ϴ�.
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
	// ���°� ���� ����.
	// �̳༮�� ���� �ɾ�� �ϰڳ׿�.

	if (nullptr == _Section)
	{
		GameServerDebug::LogErrorAssert("Section Is null");
		return;
	}


	for (size_t i = 0; i < Sections_.size(); i++)
	{
		if (Sections_[i] == _Section)
		{
			// ���� �ɾ���ϴ� �޸𸮰� 
			// ���ѵ˴ϴ�.
			Sections_[i]->IsDeath();
		}
	}

	++DeleteSectionSize_;

}

void GameServerSectionThread::StartSectionThread(int _Index)
{
	Start("SectionThread", std::bind(&GameServerSectionThread::ThreadFunction, this, _Index), nullptr, nullptr);
}

void GameServerSectionThread::ActorPost(uint64_t SectionIndex, uint64_t _ObjectIndex, std::shared_ptr<GameServerMessage> _Message)
{
	if (KeySections_.end() == KeySections_.find(SectionIndex))
	{
		GameServerDebug::AssertDebugMsg("�������� �ʴ� ���ǿ� �޼����� ���½��ϴ�.");
		return;
	}

	KeySections_[SectionIndex]->ActorPost(_ObjectIndex, _Message);
}

void GameServerSectionThread::ActorPointPost(uint64_t SectionIndex, uint64_t _ObjectIndex, const IPEndPoint& _EndPoint, std::shared_ptr<GameServerMessage> _Message)
{
	if (KeySections_.end() == KeySections_.find(SectionIndex))
	{
		GameServerDebug::AssertDebugMsg("�������� �ʴ� ���ǿ� �޼����� ���½��ϴ�.");
		return;
	}

	KeySections_[SectionIndex]->ActorPointPost(_ObjectIndex, _EndPoint, _Message);
}