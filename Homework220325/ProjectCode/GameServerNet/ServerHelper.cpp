#include "PreCompile.h"
#include "ServerHelper.h"

void ServerHelper::StartEngineStartUp() 
{
	static bool Check = false;

	if (true == Check)
	{
		return;
	}

	WSAData wsaData;
	int errorCode = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (SOCKET_ERROR == errorCode)
	{
		GameServerDebug::GetLastErrorPrint();
		return;
	}

	Check = true;
}

ServerHelper::ServerHelper() 
{

}

ServerHelper::~ServerHelper() 
{

}

ServerHelper::ServerHelper(ServerHelper&& _Other) noexcept
{

}

