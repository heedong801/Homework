#pragma once
#include "GameServerPath.h"
// �з� :
// �뵵 :
// ���� :

class GameServerFile;
class GameServerDirectory : public GameServerPath
{
public:
	GameServerDirectory(); // default constructer ����Ʈ ������
	~GameServerDirectory(); // default destructer ����Ʈ �Ҹ���

public:		// delete constructer
	GameServerDirectory(const GameServerDirectory& _other); // default Copy constructer ����Ʈ ���������
	GameServerDirectory(GameServerDirectory&& _other) noexcept; // default RValue Copy constructer ����Ʈ RValue ���������

public:		//delete operator
	GameServerDirectory& operator=(const GameServerDirectory& _other) = delete; // default Copy operator ����Ʈ ���� ������
	GameServerDirectory& operator=(const GameServerDirectory&& _other) = delete; // default RValue Copy operator ����Ʈ RValue ���Կ�����

public:
	std::string DirectoryName();

public:		//member Func
	// C: D:���� Ȯ��
	bool IsRoot();

	// �θ������� �̵�
	void MoveParent();

	// �θ������� _DirName�� ���� ������ �̵�
	bool MoveParent(const std::string& _DirName);

	// �ڽ� ������ _DirName���� �̵�
	bool MoveChild(const std::string& _DirName);

public:
	// �� ������ + �����̸� ��θ� �������ִ� �Լ�
	std::string PathToPlusFileName(const std::string& _FileName) const;

	bool IsExitsFile(const std::string& _FileName) const;

	// * �� �ǹ�
	// A* ��� �̸�
	// ABVBBB ��
	// CAFDSA �ȵ�
	// .
	// * ��� Ȯ����
	std::vector<GameServerFile> GetAllFile(const std::string& _filter = "*");
};

