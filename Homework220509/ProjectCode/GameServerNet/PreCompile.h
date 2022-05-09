#pragma once


// OS �⺻
#include <WS2tcpip.h> // inet_pton �Լ��� ����ϱ� ���� ���
#include <WinSock2.h>
#include <Windows.h> // �Ʒ��ʿ� ���� �մϴ�.
#include <MSWSock.h>

// ������
#include <thread>
#include <mutex>
#include <memory>
#include <process.h>
#include <atomic>

// ����
#include <math.h>
#include <random>

// �ڷᱸ��
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <deque>

// �����
#include <functional>
#include <assert.h>
#include <crtdbg.h>


#pragma comment (lib, "ws2_32") // ������ſ� ������ ����ִ� ���̺귯��
#pragma comment (lib, "mswsock.lib")

#include <GameServerBase/GameServerObjectBase.h>
#include <GameServerBase/GameServerNameBase.h>
#include <GameServerBase/GameServerQueue.h>
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerUnique.h>
#include <GameServerBase/GameServerObjectPool.h>
#include <GameServerBase/GameServerObjectPool.h>

#include "Enums.h"
#include "TypeDefine.h"

// �̾ȿ� dll�� ����ϰڴٴ� �ڵ尡 ���ִ°̴ϴ�.
// �׷��� lib��? ������ exe���Ͽ� ���� ���յǼ� ���� �˴ϴ�.
// exe���Ͽ��� �̹� libcrypto-1_1-x64.dll�� exe������ ����ɶ� �ε��ϰڴٴ�
#pragma comment (lib, "..\\Thirdparty\\Lib\\libmysql.lib")



// #pragma comment (lib, "libmysql.lib")
// #include <mysql\mysql.h>