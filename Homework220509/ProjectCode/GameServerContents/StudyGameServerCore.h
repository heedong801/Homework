#pragma once
#include <GameServerCore\GameServerCore.h>

// Ό³Έν :
class StudyGameServerCore : public GameServerCore
{
public:

	// constrcuter destructer
	StudyGameServerCore();
	~StudyGameServerCore();

	// delete Function
	StudyGameServerCore(const StudyGameServerCore& _Other) = delete;
	StudyGameServerCore(StudyGameServerCore&& _Other) noexcept = delete;
	StudyGameServerCore& operator=(const StudyGameServerCore& _Other) = delete;
	StudyGameServerCore& operator=(StudyGameServerCore&& _Other) noexcept = delete;

	void UserStart();

protected:
	static void AcceptEvent(std::shared_ptr<TCPSession> _User);
	static void RecvEvent(std::shared_ptr<TCPSession>, const std::vector<unsigned char>&);
	static void CloseEvent(std::shared_ptr<TCPSession>);

	static void UDPRecvEvent(std::shared_ptr<UDPSession>, const std::vector<unsigned char>&, IPEndPoint&);

private:

};

