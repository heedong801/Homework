#pragma once
#include <unordered_map>

// ���� :
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
	// �޸𸮴� �迭���ε�.
	// hash���� ����ؼ� �Ϲ����� map���� �� ������ ã���� �ְ�
	// hash��°� ����?
	// ��� ũ���� �޸𸮸� ������ ������.
	// �װ� Ű�� ��´ٸ� �װ� ������ �ٲ�����°̴ϴ�.
	// 20����Ʈ�� ������ �ִµ� 12854152
	// 12854152 % 10
	// 2������ ���� �Ǵ°̴ϴ�.
	// hash
	// ���� dbconnect�� �ַ��� �ϴ°̴ϴ�.
	// std::unordered_map<unsigned int, >
};

