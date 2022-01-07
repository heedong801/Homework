// AccpetServerBase.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// #include <WinSock2.h> 윈도우에서는 서버통신을 하려면 이녀석을 사용해야 한다.
// 윈도우에서 소켓통신에 관련된 함수와 구조체들을 모아 놓은 헤더
// 주의사항
// window와 충돌이 날수가 있어서 언제나 
// window.h를 이 헤더 아래쪽에 놔야 한다.
#include <WinSock2.h>
#include <Windows.h> // 아래쪽에 놔야 합니다.
#include <WS2tcpip.h> // inet_pton 함수를 사용하기 위한 헤더

#pragma comment (lib, "ws2_32") // 서버통신용 구현이 들어있는 라이브러리

int main()
{
	// 1
	
	// 00000001 00000000 00000000 00000000

	WSADATA wsa;

	// 윈도우에서 우리 프로그램이 소켓통신을 하겠다고 미리 알려주는 함수
	// MAKEWORD(2, 2) 소켓 통신 방식 버전을 알려준다.
	// 대부분 2.2 버전이기 때문에 아래와 같이 입력해주면 된다.
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		std::cout << "WSAStartup Error" << std::endl;
	}

	// 소켓통신을 위한 주소정보를 담는 구조체
	SOCKADDR_IN Add = { 0, };
	Add.sin_family = AF_INET; // ip버전 4로 주소체계를 잡겠다.

	// port는
	// ip주소로 내 컴퓨터까지는 올수 있다.
	// 내 컴퓨터까지 와서
	// 여러개의 프로그램들이 뭔가 통신을 하고 있다면
	// 그중에서 어디로 게임패킷을 보내야 하지?
	// 온라인 게임 3개 켜놨으면 그중 어디로 가야하지?
	// 특정 번호를 정해서 패킷이 도착할 위치를 정할수 있다.
	Add.sin_port = htons(30001);

	// 리틀에디안 빅에디안을 몰라도 됩니다.
	// 주소값을 각 컴퓨터 사양과 칩셋 사양에 맞게 알아서 만들어 줍니다.

	// "127.0.0.1"

	if (SOCKET_ERROR == inet_pton(AF_INET, "0.0.0.0", &Add.sin_addr))
	{
		return 0;
	}

	std::cout << "server start" << std::endl;

	// SOCK_STREAM 연결지속을 하겠다는 옵션
	SOCKET ServerAccpetSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (INVALID_SOCKET == ServerAccpetSocket)
	{
		return 0;
	}


	if (SOCKET_ERROR == bind(ServerAccpetSocket, (const sockaddr*)&Add, sizeof(SOCKADDR_IN)))
	{
		return 0;
	}


	// 동시에 접속요청이 오면 몇명까지 처리할거냐?

	if (SOCKET_ERROR == listen(ServerAccpetSocket, 512))
	{
		return 0;
	}

	SOCKADDR_IN UserAdd = { 0, };
	int Len = sizeof(SOCKADDR_IN);
	// 접속을 기다리겠다.

	// 이게 리턴되면 기본적으로 2가지 경우중 하나
	// 유저가 진짜 접속했다.
	// 프로그램에 문제가 생겼다.
	std::cout << "서버 접속 함수 실행" << std::endl;

	SOCKET SessionSocket = accept(ServerAccpetSocket, (sockaddr*)&UserAdd, &Len);

	// 바이트를 보내는데
	// 필요한 모든 것들을 프로토콜이라고 부르는게 맞느냐.

	// "<HEAD>"


	// "https://www.google.com/search?q=%EC%9C%A0%ED%8A%9C%EB%B8%8C&oq=%EC%9C%A0%ED%8A%9C%EB%B8%8C&aqs=chrome.0.0i131i355i433i512j46i131i199i433i465i512j0i512j0i433i512j0i512j0i433i512j0i131i433i512j0i433i512j0i512l2.1737j0j4&sourceid=chrome&ie=UTF-8"
	// 브라우저?

	// 클라의 184 소켓은 <=> 서버의 196 소켓과

	// 서버에서는 바이트를 날리고 바이트를 받는게 전부인데.
	// 그 바이트를 날리는 빈도 수준 방법 프로토콜

	// 10바이트를 보내는데 무조건 앞에 4바이트에는 이게 저 사람과 몇번째 패킷인지 보낸다.

	if (INVALID_SOCKET == SessionSocket)
	{
		return 0;
	}

	std::cout << "패킷 보내기 전 대기" << std::endl;
	_getch();

	int Result = send(SessionSocket, "hi", sizeof("hi"), 0);

	if (SOCKET_ERROR == Result)
	{
		return 0;
	}

	// 동기 리시브를 쓴다는게 말이 안된다.
	// recv(SessionSocket, "hi", sizeof("hi"), 0);

	std::cout << "접속자가 있습니다" << std::endl;

	_getch();

}