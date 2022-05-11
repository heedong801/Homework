#include "PreCompile.h"
#include "GameServerActor.h"
#include "GameServerCore.h"

// ����� ������ ���� id�� �ϳ� ������ ���°� �����ϴ�.
GameServerActor::GameServerActor() 
	: Index_(-1)
	, ThreadIndex_(-1)
	, SectionIndex_(-1)
	, IsFirstUDPMessage(true)
	, Pos_(FVector4::ZeroVector)
	, Dir_(FVector4::ZeroVector)
	, IsSectionMove_(true)
	, Section_(nullptr)
{
}

GameServerActor::~GameServerActor() 
{
}

void GameServerActor::SetUDPSession(/*std::shared_ptr<UDPSession> _Session, int _UDPPort*/)
{
	UDPSession_ = GameServerCore::GetUDPPort(UDPPort_);
	UDPSessionInitialize();
}

