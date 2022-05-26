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

	
	std::string TId = GameServerString::UTF8ToAnsi(Message_->ID);
	std::string TMsg = GameServerString::UTF8ToAnsi(Message_->Message);
	EChatMessageType Type = static_cast<EChatMessageType>(Message_->MessagaType);


	GameServerSerializer Data;
	Message_->Serialize(Data);

	TCPListener* Parent = Session_->GetParent<TCPListener>();

	if (nullptr == Parent)
	{
		GameServerDebug::AssertDebugMsg("부모가 리스너가 아니라서 브로드캐스팅을 할수가 없습니다.");
		return;
	}

	if (Type == EChatMessageType::ALL)
		Parent->BroadCast(Data.GetData(), Session_);
	else if (Type == EChatMessageType::ONEPLAYER)
		ActorWork(Message_->ThreadIndex, Message_->SectionIndex, Message_->ObjectIndex, Message_);
	else if (Type == EChatMessageType::INSECTION)
		ActorsPost(Message_->ThreadIndex, Message_->SectionIndex, Message_->ObjectIndex, Message_);
	//TCPSession_->Send(Data.GetData());
}
