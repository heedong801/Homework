#pragma once

// �뵵 : 
// �з� :
// ÷�� : 
class ServerHelper
{
public: // Member Var
	static void StartEngineStartUp();

private: // Default
	ServerHelper();
	~ServerHelper();

	ServerHelper(const ServerHelper& _Other) = delete;
	ServerHelper(ServerHelper&& _Other) noexcept;

protected:
	ServerHelper& operator=(const ServerHelper& _Other) = delete;
	ServerHelper& operator=(ServerHelper&& _Other) = delete;

private:

public: // Member Function
};

