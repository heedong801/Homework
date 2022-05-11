#pragma once
#include <GameServerMessage\GameServerMessage.h>
#include "MessageIdEnum.h"
#include "ContentsEnum.h"
#include "ContentsStructure.h"

class LoginResultMessage : public GameServerMessage                    
{                                                               
public:                                                         
	EGameServerCode Code;
                                                                
public:                                                         
    LoginResultMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::LoginResult))                    
        , Code()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~LoginResultMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(Code);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer.WriteEnum(Code);

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer.ReadEnum(Code);

    }                                                           
};                                                              

class CharacterCreateResultMessage : public GameServerMessage                    
{                                                               
public:                                                         
	FCharacterInfo ResultCharacter;
	EGameServerCode Code;
                                                                
public:                                                         
    CharacterCreateResultMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::CharacterCreateResult))                    
        , ResultCharacter()
        , Code()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~CharacterCreateResultMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(ResultCharacter) + DataSizeCheck(Code);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        ResultCharacter.Serialize(_Serializer);
        _Serializer.WriteEnum(Code);

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        ResultCharacter.DeSerialize(_Serializer);
        _Serializer.ReadEnum(Code);

    }                                                           
};                                                              

class CharacterSelectResultMessage : public GameServerMessage                    
{                                                               
public:                                                         
	EGameServerCode Code;
	std::string NickName;
                                                                
public:                                                         
    CharacterSelectResultMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::CharacterSelectResult))                    
        , Code()
        , NickName()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~CharacterSelectResultMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(Code) + DataSizeCheck(NickName);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer.WriteEnum(Code);
        _Serializer << NickName;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer.ReadEnum(Code);
        _Serializer >> NickName;

    }                                                           
};                                                              

class LevelMoveMessage : public GameServerMessage                    
{                                                               
public:                                                         
	uint64_t ObjectIndex;
	uint64_t ThreadIndex;
	uint64_t SectionIndex;
	std::string MoveLevel;
                                                                
public:                                                         
    LevelMoveMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::LevelMove))                    
        , ObjectIndex()
        , ThreadIndex()
        , SectionIndex()
        , MoveLevel()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~LevelMoveMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(ObjectIndex) + DataSizeCheck(ThreadIndex) + DataSizeCheck(SectionIndex) + DataSizeCheck(MoveLevel);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer << ObjectIndex;
        _Serializer << ThreadIndex;
        _Serializer << SectionIndex;
        _Serializer << MoveLevel;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer >> ObjectIndex;
        _Serializer >> ThreadIndex;
        _Serializer >> SectionIndex;
        _Serializer >> MoveLevel;

    }                                                           
};                                                              

class UDPReadyOKMessage : public GameServerMessage                    
{                                                               
public:                                                         
	EGameServerCode Code;
	uint64_t ObjectIndex;
                                                                
public:                                                         
    UDPReadyOKMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::UDPReadyOK))                    
        , Code()
        , ObjectIndex()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~UDPReadyOKMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(Code) + DataSizeCheck(ObjectIndex);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer.WriteEnum(Code);
        _Serializer << ObjectIndex;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer.ReadEnum(Code);
        _Serializer >> ObjectIndex;

    }                                                           
};                                                              

class SectionInsertResultMessage : public GameServerMessage                    
{                                                               
public:                                                         
	EGameServerCode Code;
	uint64_t UDPPort;
	uint64_t ObjectIndex;
	uint64_t ThreadIndex;
	uint64_t SectionIndex;
	std::string MoveLevel;
                                                                
public:                                                         
    SectionInsertResultMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::SectionInsertResult))                    
        , Code()
        , UDPPort()
        , ObjectIndex()
        , ThreadIndex()
        , SectionIndex()
        , MoveLevel()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~SectionInsertResultMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(Code) + DataSizeCheck(UDPPort) + DataSizeCheck(ObjectIndex) + DataSizeCheck(ThreadIndex) + DataSizeCheck(SectionIndex) + DataSizeCheck(MoveLevel);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer.WriteEnum(Code);
        _Serializer << UDPPort;
        _Serializer << ObjectIndex;
        _Serializer << ThreadIndex;
        _Serializer << SectionIndex;
        _Serializer << MoveLevel;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer.ReadEnum(Code);
        _Serializer >> UDPPort;
        _Serializer >> ObjectIndex;
        _Serializer >> ThreadIndex;
        _Serializer >> SectionIndex;
        _Serializer >> MoveLevel;

    }                                                           
};                                                              

class ServerDestroyMessage : public GameServerMessage                    
{                                                               
public:                                                         
                                                                
public:                                                         
    ServerDestroyMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::ServerDestroy))                    
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~ServerDestroyMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return 0;    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            

    }                                                           
};                                                              

class PlayerDestroyMessage : public GameServerMessage                    
{                                                               
public:                                                         
                                                                
public:                                                         
    PlayerDestroyMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::PlayerDestroy))                    
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~PlayerDestroyMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return 0;    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            

    }                                                           
};                                                              

class ObjectDestroyMessage : public GameServerMessage                    
{                                                               
public:                                                         
	uint64_t ObjectID;
                                                                
public:                                                         
    ObjectDestroyMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::ObjectDestroy))                    
        , ObjectID()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~ObjectDestroyMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(ObjectID);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer << ObjectID;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer >> ObjectID;

    }                                                           
};                                                              

class CharacterListMessage : public GameServerMessage                    
{                                                               
public:                                                         
	std::vector<FCharacterInfo> Characters;
                                                                
public:                                                         
    CharacterListMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::CharacterList))                    
        , Characters()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~CharacterListMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(Characters);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer.WriteVector( Characters);

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer.ReadVector( Characters);

    }                                                           
};                                                              

class PlayersUpdateMessage : public GameServerMessage                    
{                                                               
public:                                                         
	std::vector<FPlayerUpdateData> Datas;
                                                                
public:                                                         
    PlayersUpdateMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::PlayersUpdate))                    
        , Datas()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~PlayersUpdateMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(Datas);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer.WriteVector( Datas);

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer.ReadVector( Datas);

    }                                                           
};                                                              

class MonsterUpdateMessage : public GameServerMessage                    
{                                                               
public:                                                         
	FMonsterUpdateData Data;
                                                                
public:                                                         
    MonsterUpdateMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::MonsterUpdate))                    
        , Data()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~MonsterUpdateMessage() {}                                   
                                                                
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

class UserRankWindowDataMessage : public GameServerMessage                    
{                                                               
public:                                                         
	std::vector<std::string> TopUserName;
	std::vector<int> TopUserScore;
	std::vector<std::string> MyUserName;
	std::vector<int> MyUserScore;
                                                                
public:                                                         
    UserRankWindowDataMessage()                                               
        : GameServerMessage(static_cast<uint32_t>(MessageId::UserRankWindowData))                    
        , TopUserName()
        , TopUserScore()
        , MyUserName()
        , MyUserScore()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~UserRankWindowDataMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(TopUserName) + DataSizeCheck(TopUserScore) + DataSizeCheck(MyUserName) + DataSizeCheck(MyUserScore);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer.WriteVector( TopUserName);
        _Serializer.WriteVector( TopUserScore);
        _Serializer.WriteVector( MyUserName);
        _Serializer.WriteVector( MyUserScore);

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer.ReadVector( TopUserName);
        _Serializer.ReadVector( TopUserScore);
        _Serializer.ReadVector( MyUserName);
        _Serializer.ReadVector( MyUserScore);

    }                                                           
};                                                              

