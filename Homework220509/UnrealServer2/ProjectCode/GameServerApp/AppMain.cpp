#include "PreCompile.h"
#include <GameServerContents\StudyGameServerCore.h>
#include <GameServerNet\RedisConnecter.h>
#include <GameServerBase\GameServerString.h>
#include <GameServerBase\GameServerSerializer.h>

// 해결안됨.
// 1. 두번째 접속자가 터지고 있죠.
// 2. 굳이 모든 포인터를 들고 있다가 삭제되게 할거냐.

// 리시브로 갑니다.

int main() 
{
	//GameServerSerializer Inst;

	//std::vector<std::string> Name;
	//Name.push_back("하하하");
	//Name.push_back("하하하1");
	//Name.push_back("하하하2");
	//Name.push_back("하하하3");
	//Name.push_back("하하하4");

	//Inst.WriteVector(Name);

	//std::vector<std::string> ReadName;

	//Inst.OffsetReset();

	//Inst.ReadVector(ReadName);

	//int a = 0;

	//RedisConnecter Con;
	//Con.Connect("127.0.0.1", 6379);

	//for (int i = 0; i < 2000; i++)
	//{
	//	RedisCommend::ZADD Commend = RedisCommend::ZADD("UserRank", 100 * i, "Test" + std::to_string(i));
	//	Con.Query(Commend);
	//}

	//return 0;
	// Con.Query(RedisCommend::ZADD("UserRank", 200, "b"));
	////Con.Query(RedisCommend::ZADD("UserRank", 300, "c"));
	////Con.Query(RedisCommend::ZADD("UserRank", 400, "d"));
	////Con.Query(RedisCommend::ZADD("UserRank", 500, "e"));

	//// Con.Query(RedisCommend::ZRANGE("UserRank", 0, -1, ZRANGEOPTION::GREATER, ZRANGESCOREOPTION::WITHSCORES));

	//RedisCommend::ZRANK Rank = RedisCommend::ZRANK("UserRank", "c", ZRANGEOPTION::GREATER);
	//Rank.Process(Con);


	//{
	//	if (Rank.Rank != -1)
	//	{
	//		RedisCommend::ZRANGE RangeRank = RedisCommend::ZRANGE("UserRank", Rank.Rank - 1, Rank.Rank + 1, ZRANGEOPTION::GREATER, ZRANGESCOREOPTION::WITHSCORES);
	//		RangeRank.Process(Con);
	//	}
	//}

	//RedisCommend::ZRANK ErrorRank = RedisCommend::ZRANK("UserRank", "cccc", ZRANGEOPTION::GREATER);
	//ErrorRank.Process(Con);

	//{
	//	if (ErrorRank.Rank != -1)
	//	{
	//		RedisCommend::ZRANGE RangeRank = RedisCommend::ZRANGE("UserRank", ErrorRank.Rank - 2, ErrorRank.Rank + 2, ZRANGEOPTION::GREATER, ZRANGESCOREOPTION::WITHSCORES);
	//		RangeRank.Process(Con);
	//	}
	//}

	//RedisCommend::ZRANGE AllRange = RedisCommend::ZRANGE("UserRank", 0, -1, ZRANGEOPTION::GREATER, ZRANGESCOREOPTION::WITHSCORES);
	//AllRange.Process(Con);

	// Con.Query(Rank);

	// Con.Query(RedisCommend::ZRANGE("UserRank", 0, -1, ZRANGEOPTION::GREATER, ZRANGESCOREOPTION::WITHSCORES));

	//Con.Query("ZRANK UserRank aaaa\r\n");
	//Con.Query("ZREVRANGE UserRank 0 -1 WITHSCORES\r\n");
	//Con.Query("ZREVRANGE UserRank 0 -1 WITHSCORES\r\n");
	// ZREVRANGE 0 -1 WITHSCORES\r\n



	// Con.Query("ZADD ajklfdj fjklda");


	// Con.Close();

	// return 0;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 내 게임에서는 몬스터가 있을거야
	// 월드가 5개 있을거야.

	GameServerCore::Start<StudyGameServerCore>();
}