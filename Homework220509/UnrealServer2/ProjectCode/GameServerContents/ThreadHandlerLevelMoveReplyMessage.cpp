#include "PreCompile.h"
#include "ThreadHandlerLevelMoveReplyMessage.h"
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

ThreadHandlerLevelMoveReplyMessage::ThreadHandlerLevelMoveReplyMessage()
{
}

ThreadHandlerLevelMoveReplyMessage::~ThreadHandlerLevelMoveReplyMessage()
{
}

void ThreadHandlerLevelMoveReplyMessage::Start()
{
	if (nullptr == Session_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	ActorWork(Message_->ThreadIndex, Message_->SectionIndex, Message_->ObjectIndex, Message_);
}