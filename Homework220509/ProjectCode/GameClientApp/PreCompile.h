#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <conio.h>
#include <functional>
#include <assert.h>

#include <WinSock2.h>
#include <Windows.h> // 아래쪽에 놔야 합니다.
#include <WS2tcpip.h> // inet_pton 함수를 사용하기 위한 헤더
#include <thread>
#include <memory>
#include <vector>
#include <mutex>

#pragma comment (lib, "ws2_32") // 서버통신용 구현이 들어있는 라이브러리
