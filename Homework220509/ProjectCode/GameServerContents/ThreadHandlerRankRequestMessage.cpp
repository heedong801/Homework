#include "PreCompile.h"
#include "ThreadHandlerRankRequestMessage.h"
#include "ContentsSystemEnum.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerString.h>
#include <GameServerNet\DBConnecter.h>
#include <GameServerNet\RedisConnecter.h>
#include "UserTable.h"
#include "CharacterTable.h"
#include <GameServerCore\DBQueue.h>
#include <functional>
#include <GameServerCore\NetQueue.h>
#include <GameServerCore\GameServerSectionManager.h>
#include "ContentsUserData.h"

// DB에 접속하는일
// 검증하는일
// 마지막으로 결과 패킷을 보내는 일까지
// 전부다 이안에서 벌어져야 하고
// 절대로 외부로 새어나가서는 안됩니다.

// 모든 이렇게 하겠지라고 착각하면 큰일납니다.
// 외우는 것이 아니라 코드를 짠사람의 의도를 파악해라.
// 보통 경력자한테 원하는 겁니다.

// 레퍼런스 카운트는 항상 1인 상태야.
ThreadHandlerRankRequestMessage::ThreadHandlerRankRequestMessage()
{

}

ThreadHandlerRankRequestMessage::~ThreadHandlerRankRequestMessage()
{

}

void ThreadHandlerRankRequestMessage::Start()
{
	if (nullptr == Session_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	DBWork(&ThreadHandlerRankRequestMessage::DBCheck);
}

void ThreadHandlerRankRequestMessage::DBCheck(/*GameEngineThread* _Thread*/)
{
	RedisConnecter* Connecter = GameServerThread::GetLocalData<RedisConnecter>(1);

	RedisCommend::ZRANGE TopRange = RedisCommend::ZRANGE("UserRank", 0, 4, ZRANGEOPTION::GREATER, ZRANGESCOREOPTION::WITHSCORES);
	TopRange.Process(*Connecter);

	std::string MyNick = GameServerString::UTF8ToAnsi(Message_->NickName);

	RedisCommend::ZRANK MyRank = RedisCommend::ZRANK("UserRank", MyNick, ZRANGEOPTION::GREATER);
	MyRank.Process(*Connecter);

	if (MyRank.Rank == -1)
	{
		NetWork(&ThreadHandlerRankRequestMessage::ResultSend);
		return;
	}

	RedisCommend::ZRANGE MyRange = RedisCommend::ZRANGE("UserRank", MyRank.Rank - 2, MyRank.Rank + 2, ZRANGEOPTION::GREATER, ZRANGESCOREOPTION::WITHSCORES);
	MyRange.Process(*Connecter);

	Result.TopUserName = TopRange.Members;
	Result.TopUserScore = TopRange.Scores;

	Result.MyUserName = MyRange.Members;
	Result.MyUserScore = MyRange.Scores;


	NetWork(&ThreadHandlerRankRequestMessage::ResultSend);
}

void ThreadHandlerRankRequestMessage::ResultSend()
{
	GameServerSerializer Sr;
	Result.Serialize(Sr);
	Session_->Send(Sr.GetData());

}

