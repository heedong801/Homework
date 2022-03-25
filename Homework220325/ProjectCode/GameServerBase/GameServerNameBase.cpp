#include "PreCompile.h"
#include "GameServerNameBase.h"

GameServerNameBase::GameServerNameBase() 
{

}

GameServerNameBase::~GameServerNameBase() 
{

}

GameServerNameBase::GameServerNameBase(GameServerNameBase&& _Other) noexcept
{

}

void GameServerNameBase::SetName(const std::string& _name)
{
	name_ = _name;
}

std::string_view GameServerNameBase::GetNameView() 
{
	// 스트링 뷰는 string의 버퍼복사가 일어나지 않는다.
	return name_;
}

std::string GameServerNameBase::GetNameCopy()
{
	return name_;
}

const char* GameServerNameBase::GetNamePtr()
{
	return name_.c_str();
}