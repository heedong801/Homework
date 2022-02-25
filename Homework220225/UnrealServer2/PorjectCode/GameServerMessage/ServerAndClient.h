#pragma once
#include "GameServerMessage.h"

class ChatMessage : public GameServerMessage                    
{                                                               
public:                                                         
	std::string ID;
	std::string Message;
                                                                
public:                                                         
    ChatMessage()                                               
        : GameServerMessage(MessageId::Chat)                    
        , ID()
        , Message()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~ChatMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(ID) + DataSizeCheck(Message);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer << ID;
        _Serializer << Message;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer >> ID;
        _Serializer >> Message;

    }                                                           
};                                                              

