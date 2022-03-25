#include "PreCompile.h"
#include <iostream>
#include <process.h>
#include <Windows.h>
#include <thread>
#include <conio.h>
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerIocp.h>
#include <GameServerBase/GameServerQueue.h>
#include <GameServerNet/TCPListener.h>
#include <GameServerNet/TCPSession.h>
#include <GameServerNet/ServerHelper.h>
#include <GameServerBase/GameServerDebug.h>
#include "DBQueue.h"
#include "NetQueue.h"
#include <GameServerBase\GameServerFile.h>

#include <GameServerBase/GameServerString.h>
#include <GameServerMessage/MessageConverter.h>
#include <GameServerMessage/Messages.h>
#include <GameServerBase\GameServerMath.h>
#include "ServerDispatcher.h"

// #include <..\ProjectCode\Thirdparty\Mysql\include\mysql.h>
#include <GameServerNet\DBConnecter.h>

// 해결안됨.
// 1. 두번째 접속자가 터지고 있죠.
// 2. 굳이 모든 포인터를 들고 있다가 삭제되게 할거냐.

// 리시브로 갑니다.

int main() 
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DBQueue::Init();
	NetQueue::Init();

	DispatcherRegistration();

	ServerHelper::StartEngineStartUp();
	GameServerDebug::Initialize();

	PtrSTCPListener NewListener = std::make_shared<TCPListener>();

	NewListener->Initialize(IPEndPoint(IPAddress::Parse("0.0.0.0"), 30001), [](PtrSTCPSession _S)
		{
			_S->SetCallBack([&](PtrSTCPSession _S, const std::vector<unsigned char>& _Value)
				{
					MessageConverter Converter = MessageConverter(_Value);

					if (false == Converter.IsVailed())
					{
						// 자연스럽게 커넥션이 끊어지게 유도해야 한다.
						// 서버가 클라이언트를 끊어주면 된다.
						GameServerDebug::AssertDebugMsg("Convert Error");
						return;
					}

					// n초동안 연락이 완전히 두절된 커넥션도 좀비 커넥션이라고 보고 잘라내야 한다.

					// 메세지 처리한 시간을 기록해줘야 한다.
					// 여기까지 왔다는것은 메세지가 있다는 이야기가 되므로
					MessageHandler<TCPSession> Handler;
					// 이경우에는 프로그래머가 실수했다는 소리
					std::string MessageCode = std::to_string(Converter.GetMessageIdUint());
					GameServerDebug::LogInfo(MessageCode + " Message In");
					if (false == Dis.GetHandler(Converter.GetMessageIdUint(), Handler))
					{
						// 여기서는 메세지를 잘못처리한 시간을 
						GameServerDebug::AssertDebugMsg("Message Error");
						return;
					}
					;
					// 이 핸들러가 유효하다면 이 핸들러를 가지고 패킷을 처리할 겁니다.
					// Handler
					Handler(_S, Converter.GetServerMessage());
					
				},
				[](PtrSTCPSession _S)
				{
					std::string LogText = std::to_string(static_cast<int>(_S->GetSocket()));
					GameServerDebug::LogInfo(LogText + "Connect End.");
				});


			std::string LogText = std::to_string(static_cast<int>(_S->GetSocket()));

			GameServerDebug::LogInfo(LogText + "Connect.");
		}
	);


	NewListener->BindQueue(NetQueue::GetQueue());
	NewListener->StartAccept(10);

	GameServerDebug::LogInfo("Server Start.");

	_getch();

	DBQueue::Destroy();
	NetQueue::Destroy();

	GameServerDebug::Destroy();

}