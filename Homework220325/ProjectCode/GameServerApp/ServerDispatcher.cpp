#include "PreCompile.h"																																							
#include "ServerDispatcher.h"																																						
#include <GameServerBase\GameServerDebug.h>																																			
																																													
#include "ThreadHandlerLoginMessage.h"
#include "ThreadHandlerJoinMessage.h"
#include "ThreadHandlerChatMessage.h"
																																													
Dispatcher<TCPSession> Dis;																																							
																																													
template<typename MessageHandler, typename MessageType>																																
void OnMessageProcess(std::shared_ptr<TCPSession> _Session, std::shared_ptr<GameServerMessage> _Message)																			
{																																													
	std::shared_ptr<MessageType> ConvertMessage = std::dynamic_pointer_cast<MessageType>(_Message);																					
	if (nullptr == ConvertMessage)																																					
	{																																												
		GameServerDebug::LogError("ConvertError");																																
		return;																																										
	}																																												
																																													
	std::shared_ptr<MessageHandler> Cmd = std::make_shared<MessageHandler>(_Session, ConvertMessage);																				
	Cmd->Start();																																									
}																																													
																																													
void DispatcherRegistration()																																						
{																																													
	Dis.AddHandler(static_cast<uint32_t>(MessageId::Login), std::bind(&OnMessageProcess<ThreadHandlerLoginMessage, LoginMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::Join), std::bind(&OnMessageProcess<ThreadHandlerJoinMessage, JoinMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::Chat), std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, std::placeholders::_2));	
}																																													
