#pragma once
#include <filesystem>

// �з� :
// �뵵 :
// ���� :
class GameServerPath
{
protected:	// member Var
	std::filesystem::path path_;

public:		
	GameServerPath(); // default constructer ����Ʈ ������
	GameServerPath(std::filesystem::path _path);
	~GameServerPath(); // default destructer ����Ʈ �Ҹ���

public:		// delete constructer
	GameServerPath(const GameServerPath& _other); // default Copy constructer ����Ʈ ���������
	GameServerPath(GameServerPath&& _other) noexcept; // default RValue Copy constructer ����Ʈ RValue ���������

public:		//delete operator
	GameServerPath& operator=(const GameServerPath& _other) = delete; // default Copy operator ����Ʈ ���� ������
	GameServerPath& operator=(const GameServerPath&& _other) = delete; // default RValue Copy operator ����Ʈ RValue ���Կ�����

public:
	static std::string GetFileName(std::string _Path);
	std::string GetFileName();

	std::string GetFileNameWithOutExtension();

public:		//member Func
	// ������ ����ΰ� �ƴѰ��� �Ǵ��ϴ� �Լ�.
	bool IsExist();

	std::string GetFullPath();

};

