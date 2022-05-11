#pragma once
#include <vector>
#include <mutex>
#include "GameServerSection.h"
#include <GameServerBase/GameServerQueue.h>
#include <GameServerBase/GameServerThread.h>
#include <GameServerNet\IPEndPoint.h>

// ���� :
class GameServerMessage;
class GameServerSectionThread : public GameServerThread
{
	friend class GameServerSectionManager;
public:
	// constrcuter destructer
	GameServerSectionThread();
	~GameServerSectionThread();

	// delete Function
	GameServerSectionThread(const GameServerSectionThread& _Other) = delete;
	GameServerSectionThread(GameServerSectionThread&& _Other) noexcept = delete;
	GameServerSectionThread& operator=(const GameServerSectionThread& _Other) = delete;
	GameServerSectionThread& operator=(GameServerSectionThread&& _Other) noexcept = delete;

	void AddSection(std::shared_ptr<GameServerSection> _Section);
	void RemoveSection(std::shared_ptr<GameServerSection> _Section);

	void StartSectionThread(int _Index);

	uint64_t GetIndex()
	{
		return Index_;
	}

protected:

private:
	void ThreadFunction(int _Index);

	uint64_t Index_;

	void SetIndex(uint64_t _Index)
	{
		Index_ = _Index;
	}

	GameServerQueue SectionThreadQueue;

	std::shared_ptr<std::thread> thread_;
	// �����尡 ����ϰԵ� ���ǵ�
	std::atomic<size_t> LastIndex_;

	// �̰� ��¥ ���� �ֵ�
	std::map<uint64_t, std::shared_ptr<GameServerSection>> KeySections_;
	std::vector<std::shared_ptr<GameServerSection>> Sections_;

	std::atomic<size_t> DeleteSectionSize_;

	std::mutex InsertLock_;
	std::atomic<size_t> InsertSectionSize_;
	std::vector<std::shared_ptr<GameServerSection>> InsertSections_;

	void ActorPost(uint64_t SectionIndex, uint64_t _ObjectIndex, std::shared_ptr<GameServerMessage> _Message);

	void ActorPointPost(uint64_t SectionIndex, uint64_t _ObjectIndex, const IPEndPoint& _EndPoint, std::shared_ptr<GameServerMessage> _Message);

};

