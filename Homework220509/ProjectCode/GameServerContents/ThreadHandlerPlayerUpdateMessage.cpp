#include "PreCompile.h"
#include "ThreadHandlerPlayerUpdateMessage.h"
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

ThreadHandlerPlayerUpdateMessage::ThreadHandlerPlayerUpdateMessage()
{
}

ThreadHandlerPlayerUpdateMessage::~ThreadHandlerPlayerUpdateMessage()
{
}

void ThreadHandlerPlayerUpdateMessage::Start()
{
	if (nullptr == Session_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	ActorWork(Message_->Data.ThreadIndex, Message_->Data.SectionIndex, Message_->Data.ObjectIndex, Message_);
}