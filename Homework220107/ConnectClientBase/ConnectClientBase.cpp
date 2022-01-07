// ConnectClientBase.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

#include <WinSock2.h>
#include <Windows.h> // 아래쪽에 놔야 합니다.
#include <WS2tcpip.h> // inet_pton 함수를 사용하기 위한 헤더
#include <cctype>
#include <string>
#pragma comment (lib, "ws2_32") // 서버통신용 구현이 들어있는 라이브러리


int main()
{
	WSADATA wsa;

	// 윈도우에서 우리 프로그램이 소켓통신을 하겠다고 미리 알려주는 함수
	// MAKEWORD(2, 2) 소켓 통신 방식 버전을 알려준다.
	// 대부분 2.2 버전이기 때문에 아래와 같이 입력해주면 된다.
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		std::cout << "WSAStartup Error" << std::endl;
	}


	// 소켓통신을 위한 주소정보를 담는 구조체

	//         연결지속           종료
	// 프로토콜  SYN ACK
	// TCP 3 Way-Handshake & 4 Way-Handshake
	SOCKET SessionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 릴레이어블 UDP 
	// UDP 보냈어 상대인 서버가 받든 안받는 그건 상관 없는일.
	// SOCKET ServerConnectSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (INVALID_SOCKET == SessionSocket)
	{
		return 0;
	}

	// 클라는 바인드를 할필요가 없습니다.

	//std::cout << "접속 준비 키를 누르면 접속합니다" << std::endl;
	//_getch();


	std::string Ip;
	std::string Port;
	bool resetFlag = false;
	while (true)
	{
		std::cout << "IP주소를 입력해주세요" << std::endl;
		std::cin >> Ip;

		if ("Q" == Ip || "q" == Ip)
		{
			Ip = "127.0.0.1";
		}

		//ipv6 는 : 2개이상 or :: 연속 등장 or 영문자로 판별 가능
		char DotDelimiter = '.';
		char Delimiter = ':';
		int DelimiterCnt = 0;
		int DotDelimiterCnt = 0;
		resetFlag = false;
		std::string numStr = "";
		for (int i = 0; i < Ip.length(); ++i)
		{
			if (Delimiter == Ip[i])
			{
				DelimiterCnt++;
				if (DelimiterCnt >= 2)
				{
					resetFlag = true;
					break;
				}
			}
			else if(DotDelimiter == Ip[i])
			{
				DotDelimiterCnt++;
				int num = stoi(numStr);
				numStr = "";
				if( num >= 256)
				{
					resetFlag = true;
					break;
				}
			}
			else if (isdigit(Ip[i]) == 0 ) // 영문자
			{
				resetFlag = true;
				break;
			}
			else if (isdigit(Ip[i]) != 0)
			{
				numStr += Ip[i];
			}
			
		}

		if (DotDelimiterCnt > 3)
			resetFlag = true;
		else if (DotDelimiterCnt < 3)
			resetFlag = true;


		if (resetFlag)
			continue;
		/////////////////////////////////////////////////////////

		//포트번호 입력 되어있나?
		size_t findIdx = Ip.find(':');
		if (findIdx != std::string::npos)
		{
			Port = Ip.substr(findIdx + 1);
		}
		else
		{
			std::cout << "포트번호를 입력해주세요" << std::endl;
			std::cin >> Port;
		}
		Ip = Ip.substr(0, findIdx);
		// if(포트번호를 안넣었다면)
		// {
		//   std::cout << "포트 번호를 입력해주세요" << std::endl;
		// }

		// IP 주소 4가 확실하다면
		// 여기를 이탈

		break;
	}

	int a = 0;


	SOCKADDR_IN Add = { 0, };
	Add.sin_family = AF_INET;
	Add.sin_port = htons(stoi(Port));
	if (SOCKET_ERROR == inet_pton(AF_INET, Ip.c_str(), &Add.sin_addr))
	{
		return 0;
	}
	int Len = sizeof(SOCKADDR_IN);

	// 세션(session)은 컴퓨터 과학에서, 
	// 특히 네트워크 분야에서 반영구적이고 상호작용적인 
	// 정보 교환을 전제하는 둘 이상의 통신 장치나 컴퓨터와 
	// 사용자 간의 대화나 송수신 연결상태를 의미하는 보안적인 
	// 다이얼로그(dialogue) 및 시간대를 가리킨다. 
	// 따라서 세션은 연결상태를 유지하는것보다 
	// 연결상태의 안정성을 더 중요시 하게된다.



	if (SOCKET_ERROR == connect(SessionSocket, (const sockaddr*)&Add, Len))
	{
		return 0;
	}

	char Buffer[1024] = {0};

	// 어떤 특정상황이 올때까지 기다려주는 함수를
	// 동기함수

	// 비동기는 

	
	// SYNC         ASYNC
	// 동기리시브와 비동기 
	// 기다리는것도 포함한다.
	int Result = recv(SessionSocket, Buffer, sizeof(Buffer), 0);

	if (SOCKET_ERROR == Result)
	{
		return 0;
	}


	// 이 소켓은 이제 서버와 연결된거에요.
	// ServerConnectSocket

	std::cout << "접속에 성공했습니다." << std::endl;

	_getch();

}
