#include "PreCompile.h"																																							
#include "ServerDispatcher.h"																																						
#include <GameServerBase\GameServerDebug.h>																																			
																																													
#include "ThreadHandlerLoginMessage.h"
#include "ThreadHandlerCreateCharacterMessage.h"
#include "ThreadHandlerSelectCharacterMessage.h"
#include "ThreadHandlerClientToReadyMessage.h"
#include "ThreadHandlerUDPConnectResultMessage.h"
#include "ThreadHandlerLevelMoveReplyMessage.h"
#include "ThreadHandlerRankRequestMessage.h"
#include "ThreadHandlerChatMessage.h"
#include "ThreadHandlerPlayerUpdateMessage.h"
																																													
Dispatcher<TCPSession> Dis;																																							
Dispatcher<UDPSession> UDPDis;																																							
																																													
template<typename MessageHandler, typename MessageType, typename SessionType = TCPSession>																																
void OnMessageProcess(std::shared_ptr<SessionType> _Session, std::shared_ptr<GameServerMessage> _Message)																			
{																																													
	std::shared_ptr<MessageType> ConvertMessage = std::dynamic_pointer_cast<MessageType>(_Message);																					
	if (nullptr == ConvertMessage)																																					
	{																																												
		GameServerDebug::LogError("ConvertError");																																
		return;																																										
	}																																												
																																													
	std::shared_ptr<MessageHandler> Cmd = std::make_shared<MessageHandler>();																				
	Cmd->Init(std::dynamic_pointer_cast<MessageType>(_Message), _Session);																																							
	Cmd->Start();																																									
}																																													
																																													
void DispatcherRegistration()																																						
{																																													
	Dis.AddHandler(static_cast<uint32_t>(MessageId::Login), std::bind(&OnMessageProcess<ThreadHandlerLoginMessage, LoginMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::CreateCharacter), std::bind(&OnMessageProcess<ThreadHandlerCreateCharacterMessage, CreateCharacterMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::SelectCharacter), std::bind(&OnMessageProcess<ThreadHandlerSelectCharacterMessage, SelectCharacterMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::ClientToReady), std::bind(&OnMessageProcess<ThreadHandlerClientToReadyMessage, ClientToReadyMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::UDPConnectResult), std::bind(&OnMessageProcess<ThreadHandlerUDPConnectResultMessage, UDPConnectResultMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::LevelMoveReply), std::bind(&OnMessageProcess<ThreadHandlerLevelMoveReplyMessage, LevelMoveReplyMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::RankRequest), std::bind(&OnMessageProcess<ThreadHandlerRankRequestMessage, RankRequestMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::Chat), std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::PlayerUpdate), std::bind(&OnMessageProcess<ThreadHandlerPlayerUpdateMessage, PlayerUpdateMessage>, std::placeholders::_1, std::placeholders::_2));	
}																																													
