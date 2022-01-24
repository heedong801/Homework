#include "PreCompile.h"
#include "GameServerObjectBase.h"

GameServerObjectBase::GameServerObjectBase() 
	: parent_(nullptr)
{
	// ���ʹ� �����긦 ������� �ʰ� ���� ������ ��ȿ�����϶��� ����.
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