#include "PreCompile.h"
#include "GameServerThread.h"

thread_local std::string GameServerThread::name_;
thread_local unsigned int GameServerThread::Order_;
thread_local const std::type_info* GameServerThread::LocalDataType_ = nullptr;
thread_local std::vector<char> GameServerThread::Data_;


void GameServerThread::ThreadNameSetting(const std::string& _Name)
{
	name_ = _Name;

	std::wstring String;
	String.assign(_Name.begin(), _Name.end());
	HRESULT hr = SetThreadDescription(GetCurrentThread(), String.c_str());
}

std::string GameServerThread::GetName() {
	return name_;
}

GameServerThread::~GameServerThread() 
{

}

GameServerThread::GameServerThread(GameServerThread&& _Other) noexcept
{

}

void GameServerThread::join() 
{
	thread_.join();
}

