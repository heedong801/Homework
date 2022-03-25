#include "PreCompile.h"
#include "GameServerUnique.h"
#include "DateTime.h"


// C#에는 기본지원
// C++은 지원을 해주지 않아서 비슷하게 

// 현재시간을 기준으로 한 타임을 구해내고
// 프로그램이 켜질때 결정난다.
std::atomic<__int64> GameServerUnique::UniqueId = (DateTime::UtcNow().Ticks() - DateTime(2020, 1, 1, DateTimeKind::Utc).Ticks());

GameServerUnique::GameServerUnique() 
{

}

GameServerUnique::~GameServerUnique() 
{

}

GameServerUnique::GameServerUnique(GameServerUnique&& _Other) noexcept
{

}



__int64 GameServerUnique::GetNextUniqueId()
{
	++UniqueId;
	return UniqueId;
}