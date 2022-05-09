#include "PreCompile.h"
#include "GameServerUnique.h"
#include "DateTime.h"


// C#���� �⺻����
// C++�� ������ ������ �ʾƼ� ����ϰ� 

// ����ð��� �������� �� Ÿ���� ���س���
// ���α׷��� ������ ��������.
// std::atomic<uint64_t> GameServerUnique::UniqueId = (DateTime::UtcNow().Ticks() - DateTime(2020, 1, 1, DateTimeKind::Utc).Ticks());

std::atomic<uint64_t> GameServerUnique::UniqueId = 0;

GameServerUnique::GameServerUnique() 
{

}

GameServerUnique::~GameServerUnique() 
{

}

GameServerUnique::GameServerUnique(GameServerUnique&& _Other) noexcept
{

}



uint64_t GameServerUnique::GetNextUniqueId()
{
	++UniqueId;
	return UniqueId;
}