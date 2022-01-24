#include "PreCompile.h"
#include "GameServerThread.h"

void GameServerThread::ThreadNameSetting(const std::string& _Name)
{
	std::wstring String;
	String.assign(_Name.begin(), _Name.end());
	HRESULT hr = SetThreadDescription(GetCurrentThread(), String.c_str());
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