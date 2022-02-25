#include "PreCompile.h"
#include "GameServerObjectBase.h"

GameServerObjectBase::GameServerObjectBase() 
	: parent_(nullptr)
{
	// 벡터는 리저브를 사용하지 않고 쓰면 굉장히 비효율적일때가 많다.
	linkObject_.reserve(5);
}

GameServerObjectBase::~GameServerObjectBase() 
{

}

GameServerObjectBase::GameServerObjectBase(GameServerObjectBase&& _Other) noexcept
	: parent_(_Other.parent_)
{

}



bool GameServerObjectBase::IsLowLevelValid()
{
	if (nullptr == this)
	{
		return false;
	}

	return true;
}