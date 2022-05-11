#pragma once																									  
#include "CoreMinimal.h"																						  
#include <functional>																							 
																												  
#include "ThreadHandlerLoginResultMessage.h"
#include "ThreadHandlerCharacterCreateResultMessage.h"
#include "ThreadHandlerCharacterSelectResultMessage.h"
#include "ThreadHandlerLevelMoveMessage.h"
#include "ThreadHandlerUDPReadyOKMessage.h"
#include "ThreadHandlerSectionInsertResultMessage.h"
#include "ThreadHandlerServerDestroyMessage.h"
#include "ThreadHandlerPlayerDestroyMessage.h"
#include "ThreadHandlerObjectDestroyMessage.h"
#include "ThreadHandlerCharacterListMessage.h"
#include "ThreadHandlerPlayersUpdateMessage.h"
#include "ThreadHandlerMonsterUpdateMessage.h"
#include "ThreadHandlerUserRankWindowDataMessage.h"
#include "ThreadHandlerChatMessage.h"
#include "ThreadHandlerPlayerUpdateMessage.h"
																												  
template<typename MessageHandler, typename MessageType>															  
void OnMessageProcess(std::shared_ptr<GameServerMessage> _Message, UClientGameInstance* _Inst, UWorld* _World)	  
{																												  
	std::shared_ptr<MessageType> ConvertMessage = std::static_pointer_cast<MessageType>(_Message);				  
	if (nullptr == ConvertMessage)																				  
	{																											  
		return;																									  
	}																											  
																												  
	MessageHandler Cmd = MessageHandler();														  
	Cmd.Init(ConvertMessage, _Inst, _World);																					  
	Cmd.Start();																								  
}																												  
																												  
void CheckHandler(UDispatcher& Dis, class UClientGameInstance* Inst, UWorld* World)								  
{														
	Dis.AddHandler(MessageId::LoginResult, std::bind(&OnMessageProcess<ThreadHandlerLoginResultMessage, LoginResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::CharacterCreateResult, std::bind(&OnMessageProcess<ThreadHandlerCharacterCreateResultMessage, CharacterCreateResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::CharacterSelectResult, std::bind(&OnMessageProcess<ThreadHandlerCharacterSelectResultMessage, CharacterSelectResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::LevelMove, std::bind(&OnMessageProcess<ThreadHandlerLevelMoveMessage, LevelMoveMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::UDPReadyOK, std::bind(&OnMessageProcess<ThreadHandlerUDPReadyOKMessage, UDPReadyOKMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::SectionInsertResult, std::bind(&OnMessageProcess<ThreadHandlerSectionInsertResultMessage, SectionInsertResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::ServerDestroy, std::bind(&OnMessageProcess<ThreadHandlerServerDestroyMessage, ServerDestroyMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::PlayerDestroy, std::bind(&OnMessageProcess<ThreadHandlerPlayerDestroyMessage, PlayerDestroyMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::ObjectDestroy, std::bind(&OnMessageProcess<ThreadHandlerObjectDestroyMessage, ObjectDestroyMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::CharacterList, std::bind(&OnMessageProcess<ThreadHandlerCharacterListMessage, CharacterListMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::PlayersUpdate, std::bind(&OnMessageProcess<ThreadHandlerPlayersUpdateMessage, PlayersUpdateMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::MonsterUpdate, std::bind(&OnMessageProcess<ThreadHandlerMonsterUpdateMessage, MonsterUpdateMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::UserRankWindowData, std::bind(&OnMessageProcess<ThreadHandlerUserRankWindowDataMessage, UserRankWindowDataMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::Chat, std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::PlayerUpdate, std::bind(&OnMessageProcess<ThreadHandlerPlayerUpdateMessage, PlayerUpdateMessage>, std::placeholders::_1, Inst, World));	
}																																													
