#pragma once
#include <GameServerMessage\GameServerMessage.h>
#include "MessageIdEnum.h"
#include "ContentsEnum.h"
#include "ContentsStructure.h"

class ChatMessage : public GameServerMessage                    
{                                                               
public:                                                         
	std::string ID;
	std::string Message;
	int MessagaType;
                                                                
public:                                                         
    ChatMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::Chat))                    
        , ID()
        , Message()
        , MessagaType()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~ChatMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(ID) + DataSizeCheck(Message) + DataSizeCheck(MessagaType);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer << ID;
        _Serializer << Message;
        _Serializer << MessagaType;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer >> ID;
        _Serializer >> Message;
        _Serializer >> MessagaType;

    }                                                           
};                                                              

class PlayerUpdateMessage : public GameServerMessage                    
{                                                               
public:                                                         
	FPlayerUpdateData Data;
                                                                
public:                                                         
    PlayerUpdateMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::PlayerUpdate))                    
        , Data()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~PlayerUpdateMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(Data);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        Data.Serialize(_Serializer);

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        Data.DeSerialize(_Serializer);

    }                                                           
};                                                              

