#pragma once																									  
#include "CoreMinimal.h"																						  
#include <functional>																							 
																												  
#include "ThreadHandlerLoginResultMessage.h"
#include "ThreadHandlerJoinResultMessage.h"
#include "ThreadHandlerServerDestroyMessage.h"
#include "ThreadHandlerObjectDestroyMessage.h"
#include "ThreadHandlerMonsterUpdateMessage.h"
#include "ThreadHandlerChatMessage.h"
																												  
template<typename MessageHandler, typename MessageType>															  
void OnMessageProcess(std::shared_ptr<GameServerMessage> _Message, UClientGameInstance* _Inst, UWorld* _World)	  
{																												  
	std::shared_ptr<MessageType> ConvertMessage = std::static_pointer_cast<MessageType>(_Message);				  
	if (nullptr == ConvertMessage)																				  
	{																											  
		return;																									  
	}																											  
																												  
	MessageHandler Cmd = MessageHandler(ConvertMessage);														  
	Cmd.Init(_Inst, _World);																					  
	Cmd.Start();																								  
}																												  
																												  
void CheckHandler(UDispatcher& Dis, class UClientGameInstance* Inst, UWorld* World)								  
{														
	Dis.AddHandler(MessageId::LoginResult, std::bind(&OnMessageProcess<ThreadHandlerLoginResultMessage, LoginResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::JoinResult, std::bind(&OnMessageProcess<ThreadHandlerJoinResultMessage, JoinResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::ServerDestroy, std::bind(&OnMessageProcess<ThreadHandlerServerDestroyMessage, ServerDestroyMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::ObjectDestroy, std::bind(&OnMessageProcess<ThreadHandlerObjectDestroyMessage, ObjectDestroyMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::MonsterUpdate, std::bind(&OnMessageProcess<ThreadHandlerMonsterUpdateMessage, MonsterUpdateMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::Chat, std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, Inst, World));	
}																																													
