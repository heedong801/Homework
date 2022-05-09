#pragma once
#include <string>
#include <assert.h>
#include <list>
#include <atomic>
#include <memory>
// #include "GameServerIocp.h"

enum class LOGTYPE
{
	LOGTYPE_ERROR,
	LOGTYPE_WARNING,
	LOGTYPE_INFO,
	LOGTYPE_LASTERROR,
};

// 용도 : 
// 분류 :
// 첨언 : 
class GameServerIocp;
class GameServerIocpWorker;
class GameServerDebug
{
private:
	class LogJob
	{
	public:
		LOGTYPE Type_;
		std::string LogText_;
	};


	// 로그 쓰레드를 가지고
	// + 
private: // Member Var
	static const char* TypeText[4];

	static GameServerIocp* LogIocp;
	static std::atomic<int> LogCount;
	
public:
	static void Initialize();
	static void Destroy();

private: // Default
	GameServerDebug();
	virtual ~GameServerDebug() = 0;

	GameServerDebug(const GameServerDebug& _Other) = delete;
	GameServerDebug(GameServerDebug&& _Other) noexcept;

protected:
	GameServerDebug& operator=(const GameServerDebug& _Other) = delete;
	GameServerDebug& operator=(GameServerDebug&& _Other) = delete;

private:
	static void LogThread(std::shared_ptr<GameServerIocpWorker> _Work);

public: // Member Function
	
	static void Log(LOGTYPE _Type, const std::string& _Text);

	static void LogError(const std::string& _Text);
	static void LogWarning(const std::string& _Text);
	static void LogInfo(const std::string& _Text);
	static void LogLastError(const std::string& _Text);

	static void LogAssert(LOGTYPE _Type, const std::string& _Text);
	static void LogErrorAssert(const std::string& _Text);

	static void AssertDebug();
	static void AssertDebugMsg(const std::string& Msg);

	static void GetLastErrorPrint();

	
};

