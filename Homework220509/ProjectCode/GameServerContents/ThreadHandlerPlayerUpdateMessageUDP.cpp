#include "PreCompile.h"
#include "ThreadHandlerPlayerUpdateMessageUDP.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerString.h>
#include <GameServerNet\DBConnecter.h>
#include <GameServerCore\DBQueue.h>
#include <GameServerCore\NetQueue.h>
#include <GameServerCore\GameServerSectionManager.h>
#include <GameServerCore\GameServerSectionManager.h>
#include "ContentsSystemEnum.h"
#include "ContentsUserData.h"
#include "CharacterTable.h"
#include <functional>
#include "Player.h"

ThreadHandlerPlayerUpdateMessageUDP::ThreadHandlerPlayerUpdateMessageUDP()
{
}

ThreadHandlerPlayerUpdateMessageUDP::~ThreadHandlerPlayerUpdateMessageUDP()
{
}

void ThreadHandlerPlayerUpdateMessageUDP::Start()
{
	if (nullptr == Session_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	// 이액터가 처음 받았다면
	ActorPointWork(Message_->Data.ThreadIndex, Message_->Data.SectionIndex, Message_->Data.ObjectIndex, Point, Message_);
}