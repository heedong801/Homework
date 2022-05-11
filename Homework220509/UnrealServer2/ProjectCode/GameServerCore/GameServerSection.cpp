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

// 이걸 호출해주는게 SectionThread가 해줄 겁니다.
bool GameServerSection::Update(float _Time)
{
	// 돌리는건 순회에 적합한 리스트를 사용한다.
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

	// 몬스터가 움직인다.
	// 조건을 다 두겠습니다.
	// 먼저 락을 걸지 않고.
	// 이녀석 자체는 락이 아니고.
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

			// 외부에서는 플레이어블을 넣어줄수만 있다.
			// 외부에서는 몬스터를 만들수가 없다!
			if (nullptr != WaitActor_[i]->GetTCPSession())
			{
				PlayableActor_.push_back(WaitActor_[i]);
			}
			else 
			{
				AIActor_.push_back(WaitActor_[i]);
			}

			// 코어에게서 udp하나 얻어와서 그것도 받아야 한다.
			// 그래야 그걸로 send를할수 있으니까.
			WaitActor_[i]->SetSection(this);
			WaitActor_[i]->AccTimeReset();

			if (false == WaitActor_[i]->InsertSection())
			{
				// 뭔가 실패함. 로그를 남겨줄수는 있을것이다.
				// 삭제됩니다.
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
		// 섹션에서는 완전히 메모리가 정리
		std::list<std::shared_ptr<GameServerActor>>::iterator StartIter = PlayableActor_.begin();
		std::list<std::shared_ptr<GameServerActor>>::iterator EndIter = PlayableActor_.end();

		// 중간에 
		// 하나 
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
		// 섹션에서는 완전히 메모리가 정리
		std::list<std::shared_ptr<GameServerActor>>::iterator StartIter = AIActor_.begin();
		std::list<std::shared_ptr<GameServerActor>>::iterator EndIter = AIActor_.end();

		// 중간에 
		// 하나 
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
	// 옮기는 과정이 완료되기 전까지
	_Actor->SetSection(nullptr);
	// 이놈으로 무슨짓거리를 하려고 하면 터트릴 생각입니다.

	// 언젠 다륵섹션으로 완벽하게 넘어갈지 알수가 없다.
	// 그때 이제는 내가 없어야 하는 섹션에 이녀석가지고 무슨 일을 하려고 하면
	// 터지게 만들려고 한다.
	InsertActor(_Actor->GetIndex(), _Actor);
}

// 쓰레드에서 언제든지 날아올수 있는 명령이다.
void GameServerSection::InsertActor(uint64_t _ID, std::shared_ptr<GameServerActor> _Actor)
{
	if (_ID == -1)
	{
		GameServerDebug::AssertDebugMsg("actor index is -1 Fuck you !!!!!!");
		// GameServerDebug::AssertDebugMsg("조해근 대리님한테 오세요!!!!!!");
		return;
	}

	std::lock_guard<std::mutex> lock(WaitLock);
	_Actor->SetSectionIndex(GetIndex());
	_Actor->SetThreadIndex(GetThreadIndex());
	WaitActor_.push_back(_Actor);
	WaitActorCount_ = WaitActor_.size();

}

// 범위충돌체크를 한번 하고 보낼거냐?
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

// ObjectMessageComponent.cpp 메세지 40번이 문제.

void GameServerSection::UDPBroadcasting(const std::vector<unsigned char>& _Buffer, uint64_t _IgnoreIndex/* = -1*/)
{
	for (auto& Actors : PlayableActor_)
	{
		if (_IgnoreIndex == Actors->GetIndex())
		{
			continue;
		}

		// UDP통신을 한번도 서버에 날린적이 없는 녀석이다.

		int Port = Actors->GetUDPEndPointConstRef().GetPort();

		if (0 == Port)
		{
			continue;
		}

		// 나랑 연결된 클라이언트의 앤드포인트를 이미 알고 있어야 하고
		Actors->GetUDPSession()->Send(_Buffer, Actors->GetUDPEndPointConstRef());
	}
}

void GameServerSection::ActorPost(uint64_t _ObjectIndex, std::shared_ptr<GameServerMessage> _Message)
{
	// std::lock_guard<std::mutex> lock(WaitLock);

	// 지역static은 1번만 초기화 되죠?
	std::map<uint64_t, std::shared_ptr<GameServerActor>>::iterator FindIter;

	FindIter = KeyActor_.find(_ObjectIndex);

	if (KeyActor_.end() == FindIter)
	{
		GameServerDebug::AssertDebugMsg("존재하지 않는 액터에 메세지를 보냈습니다.");
		return;
	}

	if (nullptr == FindIter->second)
	{
		GameServerDebug::AssertDebugMsg("존재하지 않는 액터에 메세지를 보냈습니다.");
		return;
	}

	// 이동중이다.
	if (true == FindIter->second->IsSectionMove_)
	{
		return;
	}
	


	FindIter->second->Messagequeue_.push(_Message);

}

void GameServerSection::ActorPointPost(uint64_t _ObjectIndex, const IPEndPoint& _EndPoint, std::shared_ptr<GameServerMessage> _Message) 
{
	// std::lock_guard<std::mutex> lock(WaitLock);

	// 지역static은 1번만 초기화 되죠?
	std::map<uint64_t, std::shared_ptr<GameServerActor>>::iterator FindIter;

	FindIter = KeyActor_.find(_ObjectIndex);

	if (KeyActor_.end() == FindIter)
	{
		GameServerDebug::AssertDebugMsg("존재하지 않는 액터에 메세지를 보냈습니다.");
		return;
	}

	if (nullptr == FindIter->second)
	{
		GameServerDebug::AssertDebugMsg("존재하지 않는 액터에 메세지를 보냈습니다.");
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
