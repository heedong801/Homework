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
	uint64_t ObjectIndex;
	uint64_t ThreadIndex;
	uint64_t SectionIndex;
                                                                
public:                                                         
    ChatMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::Chat))                    
        , ID()
        , Message()
        , MessagaType()
        , ObjectIndex()
        , ThreadIndex()
        , SectionIndex()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~ChatMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(ID) + DataSizeCheck(Message) + DataSizeCheck(MessagaType) + DataSizeCheck(ObjectIndex) + DataSizeCheck(ThreadIndex) + DataSizeCheck(SectionIndex);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer << ID;
        _Serializer << Message;
        _Serializer << MessagaType;
        _Serializer << ObjectIndex;
        _Serializer << ThreadIndex;
        _Serializer << SectionIndex;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer >> ID;
        _Serializer >> Message;
        _Serializer >> MessagaType;
        _Serializer >> ObjectIndex;
        _Serializer >> ThreadIndex;
        _Serializer >> SectionIndex;

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

