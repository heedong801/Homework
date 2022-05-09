#include "PreCompile.h"
#include "ThreadHandlerChatMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerString.h>
#include <GameServerNet/TCPListener.h>
//#include "DBQueue.h"
//#include "NetQueue.h"

ThreadHandlerChatMessage::ThreadHandlerChatMessage()
{

}

ThreadHandlerChatMessage::~ThreadHandlerChatMessage()
{

}

void ThreadHandlerChatMessage::Start()
{
	if (nullptr == Session_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	{
		std::string TId = GameServerString::UTF8ToAnsi(Message_->ID);
		std::string TMsg = GameServerString::UTF8ToAnsi(Message_->Message);

		int a = 0;
	}

	GameServerSerializer Data;
	Message_->Serialize(Data);

	TCPListener* Parent = Session_->GetParent<TCPListener>();

	if (nullptr == Parent)
	{
		GameServerDebug::AssertDebugMsg("부모가 리스너가 아니라서 브로드캐스팅을 할수가 없습니다.");
		return;
	}

	Parent->BroadCast(Data.GetData(), Session_);

	//TCPSession_->Send(Data.GetData());
}
