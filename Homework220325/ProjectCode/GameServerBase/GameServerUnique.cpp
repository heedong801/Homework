#include "PreCompile.h"
#include "GameServerUnique.h"
#include "DateTime.h"


// C#���� �⺻����
// C++�� ������ ������ �ʾƼ� ����ϰ� 

// ����ð��� �������� �� Ÿ���� ���س���
// ���α׷��� ������ ��������.
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