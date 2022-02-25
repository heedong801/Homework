#include "PreCompile.h"
#include "ThreadHandlerChatMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerString.h>
#include <GameServerNet/TCPListener.h>
#include "DBQueue.h"
#include "NetQueue.h"

ThreadHandlerChatMessage::ThreadHandlerChatMessage(std::shared_ptr<TCPSession> _TCPSession, std::shared_ptr<ChatMessage> _Message)
	:TCPSession_(_TCPSession), Message_(_Message)
{

}

ThreadHandlerChatMessage::~ThreadHandlerChatMessage()
{

}

void ThreadHandlerChatMessage::Start()
{
	if (nullptr == TCPSession_)
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

	TCPListener* Parent = TCPSession_->GetParent<TCPListener>();

	if (nullptr == Parent)
	{
		GameServerDebug::AssertDebugMsg("부모가 리스너가 아니라서 브로드캐스팅을 할수가 없습니다.");
		return;
	}

	Parent->BroadCast(Data.GetData(), TCPSession_);

	//TCPSession_->Send(Data.GetData());
}
