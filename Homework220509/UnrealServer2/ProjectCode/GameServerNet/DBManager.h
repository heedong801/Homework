#pragma once
#include <unordered_map>

// 설명 :
class DBManager
{
public:
	// constrcuter destructer
	DBManager();
	~DBManager();

	// delete Function
	DBManager(const DBManager& _Other) = delete;
	DBManager(DBManager&& _Other) noexcept = delete;
	DBManager& operator=(const DBManager& _Other) = delete;
	DBManager& operator=(DBManager&& _Other) noexcept = delete;

protected:

private:
	// 메모리는 배열형인데.
	// hash값을 사용해서 일반적인 map보다 더 빠르게 찾을수 있게
	// hash라는건 뭐죠?
	// 어떠한 크기의 메모리를 가지고 있을때.
	// 그걸 키로 삼는다면 그걸 정수로 바꿔버리는겁니다.
	// 20바이트를 가지고 있는데 12854152
	// 12854152 % 10
	// 2번으로 들어가게 되는겁니다.
	// hash
	// 전담 dbconnect를 주려고 하는겁니다.
	// std::unordered_map<unsigned int, >
};

