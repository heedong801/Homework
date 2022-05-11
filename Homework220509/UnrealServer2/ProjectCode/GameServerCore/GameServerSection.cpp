#include "PreCompile.h"
#include "GameServerSection.h"
#include "GameServerActor.h"
#include <GameServerNet\TCPSession.h>
#include <GameServerNet\UDPSession.h>


GameServerSection::GameServerSection()
	: Index_(0)
{
	WaitActor_.reserve(100);
}

GameServerSection::~GameServerSection()
{
}

// �̰� ȣ�����ִ°� SectionThread�� ���� �̴ϴ�.
bool GameServerSection::Update(float _Time)
{
	// �����°� ��ȸ�� ������ ����Ʈ�� ����Ѵ�.
	//static float Time = 1 / 60.0f;
	//// 0.166667
	//static float FrameTime = 0.0f;

	//FrameTime += _Time;

	//if (Time > FrameTime)
	//{
	//	return;
	//}

	//FrameTime -= Time;

	UserUpdate();

	for (auto& Actor : PlayableActor_)
	{
		if (false == Actor->IsUpdate())
		{
			continue;
		}

		Actor->AccTimeUpdate(_Time);
		Actor->Update(_Time);
	}


	for (auto& Actor : AIActor_)
	{
		if (false == Actor->IsUpdate())
		{
			continue;
		}

		Actor->AccTimeUpdate(_Time);
		Actor->Update(_Time);
	}


	{
		for (size_t i = 0; i < MoveActors_.size(); i++)
		{
			KeyActor_.erase(MoveActors_[i].MoveActor->GetIndex());
			PlayableActor_.remove(MoveActors_[i].MoveActor);
			MoveActors_[i].NextSection->MoveActor(MoveActors_[i].MoveActor);
		}
		MoveActors_.clear();
		// PlayableActor_.begin();
	}

	// ���Ͱ� �����δ�.
	// ������ �� �ΰڽ��ϴ�.
	// ���� ���� ���� �ʰ�.
	// �̳༮ ��ü�� ���� �ƴϰ�.
	if (0 != WaitActorCount_)
	{
		std::lock_guard<std::mutex> lock(WaitLock);

		for (size_t i = 0; i < WaitActor_.size(); i++)
		{
			for (auto& Actor : PlayableActor_)
			{
				WaitActor_[i]->PlayerbleActorEvent(Actor.get());
			}

			for (auto& Actor : AIActor_)
			{
				WaitActor_[i]->AIActorEvent(Actor.get());
			}

			// �ܺο����� �÷��̾���� �־��ټ��� �ִ�.
			// �ܺο����� ���͸� ������� ����!
			if (nullptr != WaitActor_[i]->GetTCPSession())
			{
				PlayableActor_.push_back(WaitActor_[i]);
			}
			else 
			{
				AIActor_.push_back(WaitActor_[i]);
			}

			// �ھ�Լ� udp�ϳ� ���ͼ� �װ͵� �޾ƾ� �Ѵ�.
			// �׷��� �װɷ� send���Ҽ� �����ϱ�.
			WaitActor_[i]->SetSection(this);
			WaitActor_[i]->AccTimeReset();

			if (false == WaitActor_[i]->InsertSection())
			{
				// ���� ������. �α׸� �����ټ��� �������̴�.
				// �����˴ϴ�.
				continue;
			}
			KeyActor_.insert(std::make_pair(WaitActor_[i]->GetIndex(), WaitActor_[i]));



			WaitActor_[i]->SectionMoveEnd();
		}
		WaitActor_.clear();
		WaitActorCount_ = 0;
	}

	return true;
}

void GameServerSection::SectionMove(std::shared_ptr<GameServerActor> _MoveActor, GameServerSection* _MoveSection)
{
	MoveActors_.push_back({ _MoveActor, _MoveSection });
}

void GameServerSection::Release() 
{
	{
		// ���ǿ����� ������ �޸𸮰� ����
		std::list<std::shared_ptr<GameServerActor>>::iterator StartIter = PlayableActor_.begin();
		std::list<std::shared_ptr<GameServerActor>>::iterator EndIter = PlayableActor_.end();

		// �߰��� 
		// �ϳ� 
		for (; StartIter != EndIter; )
		{
			if (false == (*StartIter)->IsDeath())
			{
				++StartIter;
				continue;
			}


			(*StartIter)->DeathEvent();
			KeyActor_.erase((*StartIter)->GetIndex());
			StartIter = PlayableActor_.erase(StartIter);
		}
	}

	{
		// ���ǿ����� ������ �޸𸮰� ����
		std::list<std::shared_ptr<GameServerActor>>::iterator StartIter = AIActor_.begin();
		std::list<std::shared_ptr<GameServerActor>>::iterator EndIter = AIActor_.end();

		// �߰��� 
		// �ϳ� 
		for (; StartIter != EndIter; )
		{
			if (false == (*StartIter)->IsDeath())
			{
				++StartIter;
				continue;
			}

			(*StartIter)->DeathEvent();
			KeyActor_.erase((*StartIter)->GetIndex());
			StartIter = AIActor_.erase(StartIter);
		}
	}


	//for (auto& Actor : AIActor_)
	//{
	//	if (false == Actor->())
	//	{
	//		continue;
	//	}

	//	Actor->AccTimeUpdate(_Time);
	//	Actor->Update(_Time);
	//}
}


void GameServerSection::MoveActor(std::shared_ptr<GameServerActor> _Actor)
{
	// �ű�� ������ �Ϸ�Ǳ� ������
	_Actor->SetSection(nullptr);
	// �̳����� �������Ÿ��� �Ϸ��� �ϸ� ��Ʈ�� �����Դϴ�.

	// ���� �ٸ��������� �Ϻ��ϰ� �Ѿ�� �˼��� ����.
	// �׶� ������ ���� ����� �ϴ� ���ǿ� �̳༮������ ���� ���� �Ϸ��� �ϸ�
	// ������ ������� �Ѵ�.
	InsertActor(_Actor->GetIndex(), _Actor);
}

// �����忡�� �������� ���ƿü� �ִ� ����̴�.
void GameServerSection::InsertActor(uint64_t _ID, std::shared_ptr<GameServerActor> _Actor)
{
	if (_ID == -1)
	{
		GameServerDebug::AssertDebugMsg("actor index is -1 Fuck you !!!!!!");
		// GameServerDebug::AssertDebugMsg("���ر� �븮������ ������!!!!!!");
		return;
	}

	std::lock_guard<std::mutex> lock(WaitLock);
	_Actor->SetSectionIndex(GetIndex());
	_Actor->SetThreadIndex(GetThreadIndex());
	WaitActor_.push_back(_Actor);
	WaitActorCount_ = WaitActor_.size();

}

// �����浹üũ�� �ѹ� �ϰ� �����ų�?
void GameServerSection::TCPBroadcasting(const std::vector<unsigned char>& _Buffer, uint64_t _IgnoreIndex /*= -1*/)
{
	std::string Text;
	for (auto& Actors : PlayableActor_)
	{
		if (_IgnoreIndex == Actors->GetIndex())
		{
			continue;
		}

		Text += std::to_string(Actors->GetIndex()) + " ";

		if (false == Actors->GetTCPSession()->Send(_Buffer))
		{
			GameServerDebug::AssertDebugMsg("Broadcasting Error " + std::to_string(Actors->GetIndex()));
		}
		;
	}

	GameServerDebug::Log(LOGTYPE::LOGTYPE_INFO, Text);
}

// ObjectMessageComponent.cpp �޼��� 40���� ����.

void GameServerSection::UDPBroadcasting(const std::vector<unsigned char>& _Buffer, uint64_t _IgnoreIndex/* = -1*/)
{
	for (auto& Actors : PlayableActor_)
	{
		if (_IgnoreIndex == Actors->GetIndex())
		{
			continue;
		}

		// UDP����� �ѹ��� ������ �������� ���� �༮�̴�.

		int Port = Actors->GetUDPEndPointConstRef().GetPort();

		if (0 == Port)
		{
			continue;
		}

		// ���� ����� Ŭ���̾�Ʈ�� �ص�����Ʈ�� �̹� �˰� �־�� �ϰ�
		Actors->GetUDPSession()->Send(_Buffer, Actors->GetUDPEndPointConstRef());
	}
}

void GameServerSection::ActorPost(uint64_t _ObjectIndex, std::shared_ptr<GameServerMessage> _Message)
{
	// std::lock_guard<std::mutex> lock(WaitLock);

	// ����static�� 1���� �ʱ�ȭ ����?
	std::map<uint64_t, std::shared_ptr<GameServerActor>>::iterator FindIter;

	FindIter = KeyActor_.find(_ObjectIndex);

	if (KeyActor_.end() == FindIter)
	{
		GameServerDebug::AssertDebugMsg("�������� �ʴ� ���Ϳ� �޼����� ���½��ϴ�.");
		return;
	}

	if (nullptr == FindIter->second)
	{
		GameServerDebug::AssertDebugMsg("�������� �ʴ� ���Ϳ� �޼����� ���½��ϴ�.");
		return;
	}

	// �̵����̴�.
	if (true == FindIter->second->IsSectionMove_)
	{
		return;
	}
	


	FindIter->second->Messagequeue_.push(_Message);

}

void GameServerSection::ActorPointPost(uint64_t _ObjectIndex, const IPEndPoint& _EndPoint, std::shared_ptr<GameServerMessage> _Message) 
{
	// std::lock_guard<std::mutex> lock(WaitLock);

	// ����static�� 1���� �ʱ�ȭ ����?
	std::map<uint64_t, std::shared_ptr<GameServerActor>>::iterator FindIter;

	FindIter = KeyActor_.find(_ObjectIndex);

	if (KeyActor_.end() == FindIter)
	{
		GameServerDebug::AssertDebugMsg("�������� �ʴ� ���Ϳ� �޼����� ���½��ϴ�.");
		return;
	}

	if (nullptr == FindIter->second)
	{
		GameServerDebug::AssertDebugMsg("�������� �ʴ� ���Ϳ� �޼����� ���½��ϴ�.");
		return;
	}

	FindIter->second->UDPEndPoint = _EndPoint;

	FindIter->second->Messagequeue_.push(_Message);

}

bool GameServerSection::Init()
{
	return true;
}

GameServerCollision* GameServerSection::CreateCollision(int _Order, GameServerActor* _Owner)
{
	GameServerCollision* NewCollision = new GameServerCollision();
	NewCollision->SetGroupIndex(_Order);
	NewCollision->OwnerSection = this;
	NewCollision->OwnerActor = _Owner;
	CollisionList[_Order].push_back(NewCollision);

	return NewCollision;
}
