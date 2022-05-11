#include "PreCompile.h"
#include "Player.h"
#include "ClientToServer.h"
#include "ServerToClient.h"

#include <GameServerNet\TCPSession.h>
#include "ContentsSystemEnum.h"
#include "ContentsUserData.h"
#include "CharacterTable.h"
#include "GameServerBase\GameServerDebug.h"
#include <GameServerCore\GameServerSection.h>

void Player::MessageCheck()
{
	while (false == IsEmptyMessage())
	{
		std::shared_ptr<GameServerMessage> Message = PopMessage();

		MessageId Id = Message->GetId<MessageId>();

		switch (Id)
		{
		case MessageId::ClientToReady:
			ClientToReadyMessageProcess(std::dynamic_pointer_cast<ClientToReadyMessage>(Message));
			break;
		case MessageId::PlayerUpdate:
			PlayerUpdateMessageProcess(std::dynamic_pointer_cast<PlayerUpdateMessage>(Message));
			break;
		case MessageId::LevelMoveReply:
			LevelMoveReplyMessageProcess(std::dynamic_pointer_cast<LevelMoveReplyMessage>(Message));
			break;
		default:
			GameServerDebug::AssertDebugMsg("처리할수 없는 메세지를 받았습니다");
			break;
		}
	}
}
