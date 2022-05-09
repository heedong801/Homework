#include "PreCompile.h"
#include "ThreadHandlerSelectCharacterMessage.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerString.h>
#include <GameServerNet\DBConnecter.h>
#include "UserTable.h"
#include <GameServerCore\DBQueue.h>
#include <functional>
#include <GameServerCore\NetQueue.h>
#include <GameServerCore\GameServerSectionManager.h>
#include "ContentsSystemEnum.h"
#include "ContentsUserData.h"
#include "ContentsPlayerData.h"
#include "CharacterTable.h"
#include <GameServerCore\GameServerSectionManager.h>
#include "Player.h"
#include "ContentsGlobalValue.h"

ThreadHandlerSelectCharacterMessage::ThreadHandlerSelectCharacterMessage() 
{
}

ThreadHandlerSelectCharacterMessage::~ThreadHandlerSelectCharacterMessage() 
{
}

void ThreadHandlerSelectCharacterMessage::Start() 
{
	if (nullptr == Session_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	{
	}



	DBWork(&ThreadHandlerSelectCharacterMessage::DBCheck);
}


void ThreadHandlerSelectCharacterMessage::DBCheck() 
{
	CharacterTable_SelectNickName SelectQuery = CharacterTable_SelectNickName(Message_->NickName);

	if (false == SelectQuery.DoQuery())
	{
		// ContentsGlobalValue::UnRegistPlayable(SelectQuery.RowData->Index);

		ResultMessage.Code = EGameServerCode::FAIL;
		NetWork(&ThreadHandlerSelectCharacterMessage::SelectResult);
		return;
	}

	//if (false == ContentsGlobalValue::RegistPlayable(SelectQuery.RowData->Index))
	//{
	//	ResultMessage.Code = EGameServerCode::FAIL;
	//	NetWork(&ThreadHandlerSelectCharacterMessage::SelectResult);
	//	return;
	//}

	ResultMessage.Code = EGameServerCode::OK;
	NetWork(&ThreadHandlerSelectCharacterMessage::SelectResult);
}

void ThreadHandlerSelectCharacterMessage::SelectResult()
{
	std::shared_ptr<ContentsUserData> UserData = Session_->GetLink<ContentsUserData>(EDataIndex::USERDATA);

	if (ResultMessage.Code == EGameServerCode::OK)
	{
		for (size_t i = 0; i < UserData->Characters.size(); i++)
		{
			if (UserData->Characters[i].NickName == Message_->NickName)
			{
				// 룸으로 보낸다는 생각하지 않겠습니다.
				GameServerSerializer Sr;
				ResultMessage.NickName = Message_->NickName;
				ResultMessage.Serialize(Sr);
				Session_->Send(Sr.GetData());
				GameServerDebug::LogInfo("Select Result OK Send");
				UserData->SelectData = UserData->Characters[i];
				NetWork(&ThreadHandlerSelectCharacterMessage::SectionInsert);

				return;
			}
		}
	}

	ResultMessage.Code = EGameServerCode::FAIL;
	GameServerSerializer Sr;
	ResultMessage.Serialize(Sr);
	Session_->Send(Sr.GetData());

	GameServerDebug::LogInfo("Select Result FAIL Send");
	// 실패했는데 캐릭터를 만들필요가 없으니까 그냥 여기서 끝낸다.
	// NetWork(&ThreadHandlerSelectCharacterMessage::SectionInsert);
}

void ThreadHandlerSelectCharacterMessage::SectionInsert()
{
	std::shared_ptr<ContentsUserData> UserData = Session_->GetLink<ContentsUserData>(EDataIndex::USERDATA);


	// 섹션이란 우리가 알고 있는 마을 맵 이런애들입니다.
	// ok?
	// 거기에 뚱하고 캐릭터가 생성되는거죠?

	// 이게 몬스터일수도 있고
	// 플레이어 일수도 있다.
	// 액터를 상속받는 캐릭터도 들어갈수 있고 액터

	size_t Key = UserData->SelectData.LastSectionID;

	if (Key == -1)
	{
		Key = static_cast<int>(ESectionType::NONEFIGHT);
	}


	std::shared_ptr<GameServerSection> LastSection = GameServerSectionManager::GetInst()->FindSection(Key);
	std::shared_ptr<Player> NewPlayer = LastSection->CreateActor<Player>(Session_);

	if (nullptr == NewPlayer)
	{
		// 액터를 못만들었으니까 그에 대한 정보를 클라이언트한테 보내줘야 한다.
	}

	std::shared_ptr<ContentsPlayerData> NewPlayableData = Session_->CreateLink<ContentsPlayerData>(EDataIndex::PLAYABLE);
	// 순환참조 때문에 그냥 포인터로 처리
	NewPlayableData->ConnectPlayer = NewPlayer.get();


	//std::shared_ptr<GameServerSection> LastSection = GameServerSectionManager::GetInst()->FindSection(Key);
	//LastSection->CreateActor<Monster>();
	 // TCPSession_
	
}