// GameClientApp.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#include "PreCompile.h"
#include <iostream>
#include <GameServerBase/GameServerDebug.h>

#pragma comment (lib, "GameServerBase.lib")


std::mutex Lock;

std::thread RecvThread;

bool Check = true;

void RecvFunc(SOCKET _SessionSocket)
{
	while (Check)
	{
		char Buffer[1024];

		int Result = recv(_SessionSocket, Buffer, sizeof(Buffer), 0);

		if (SOCKET_ERROR == Result)
		{
			return;
		}

		static std::vector<char> charArr;
		static int cnt = 0;
		charArr.reserve(50);
		for (int i = 0; i < 1024; ++i)
		{
			if (Buffer[i] != 0)
			{
				charArr.push_back(Buffer[i]);
				if (Buffer[i] == '!')
				{
					std::string resultStr = "";
					cnt++;
					for (int j = 0; j < charArr.size(); ++j)
						resultStr += charArr[j];

					if (cnt == 2)
						std::cout << resultStr << std::endl;
				}
				else
					cnt = 0;
			}
			else
				break;
		}
	}
}

int main()
{
	WSADATA wsa;

	if (0 != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		std::cout << "WSAStartup Error" << std::endl;
	}

	SOCKET SessionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (INVALID_SOCKET == SessionSocket)
	{
		return 0;
	}

	std::cout << "IP�ּҸ� �Է����ּ���" << std::endl;
	std::string Ip;
	std::string Port;
	std::cin >> Ip;

	if ("Q" == Ip
		|| "q" == Ip)
	{
		Ip = "127.0.0.1";
	}
	else if ("w" == Ip
		|| "W" == Ip)
	{
		Ip = "58.150.30.210";
	}

	SOCKADDR_IN Add = { 0, };
	Add.sin_family = AF_INET;
	Add.sin_port = htons(30001);
	if (SOCKET_ERROR == inet_pton(AF_INET, Ip.c_str(), &Add.sin_addr))
	{
		return 0;
	}
	int Len = sizeof(SOCKADDR_IN);

	if (SOCKET_ERROR == connect(SessionSocket, (const sockaddr*)&Add, Len))
	{
		GameServerDebug::GetLastErrorPrint();
		return 0;
	}

	std::cout << "Ŀ��Ʈ ����." << std::endl;

	RecvThread = std::thread(RecvFunc, SessionSocket);

	while (true)
	{
		std::string In;

		// Lock.lock();

		std::cin >> In;

		if (In == "q" || In == "Q")
		{
			//TCP�� ���ڵ� ����ũ�� �� ����ϰ� �����ݴϴ�.
			closesocket(SessionSocket);
			Check = false;
			RecvThread.join();
			Sleep(1);
			return 0;
		}

		char Buffer[1024] = { "" };

		Sleep(1);

		memcpy_s(Buffer, sizeof(Buffer), In.c_str(), In.size());

		int Result = send(SessionSocket, Buffer, sizeof(Buffer), 0);


	}

	_getch();
}
