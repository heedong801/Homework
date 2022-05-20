#include "PreCompile.h"
#include "GameServerThread.h"
#include "GameServerString.h"


thread_local std::string GameServerThread::name_;
thread_local unsigned int GameServerThread::Order_;
thread_local std::map<size_t, const std::type_info*> GameServerThread::LocalDataType_;
thread_local std::map<size_t, std::vector<char>> GameServerThread::Data_;
thread_local GameServerTime GameServerThread::Timer_;

void GameServerThread::ThreadNameSetting(const std::string& _Name)
{
	name_ = _Name;
	std::wstring String;
	GameServerString::AnsiToUnicode(name_, String);
	HRESULT hr = SetThreadDescription(GetCurrentThread(), String.c_str());
}

std::string GameServerThread::GetThreadName() {
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

