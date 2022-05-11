#include "PreCompile.h"
#include "ThreadHandlerClientToReadyMessage.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerString.h>
#include <GameServerNet\DBConnecter.h>
#include "UserTable.h"
#include <GameServerCore\DBQueue.h>
#include <functional>
#include <GameServerCore\NetQueue.h>
#include <GameServerCore\GameServerSectionManager.h>
#include "ContentsSystemEnum.h"
#include "ContentsUserData.h"
#include "CharacterTable.h"
#include <GameServerCore\GameServerSectionManager.h>
#include "Player.h"

ThreadHandlerClientToReadyMessage::ThreadHandlerClientToReadyMessage()
{
}

ThreadHandlerClientToReadyMessage::~ThreadHandlerClientToReadyMessage()
{
}

void ThreadHandlerClientToReadyMessage::Start()
{
	if (nullptr == Session_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	// DB찾아오는 일이 있거나
	ActorWork(Message_->ThreadIndex, Message_->SectionIndex, Message_->ObjectIndex, Message_);
}