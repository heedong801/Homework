#pragma once
#include <filesystem>

// 분류 :
// 용도 :
// 설명 :
class GameServerPath
{
protected:	// member Var
	std::filesystem::path path_;

public:		
	GameServerPath(); // default constructer 디폴트 생성자
	GameServerPath(std::filesystem::path _path);
	~GameServerPath(); // default destructer 디폴트 소멸자

public:		// delete constructer
	GameServerPath(const GameServerPath& _other); // default Copy constructer 디폴트 복사생성자
	GameServerPath(GameServerPath&& _other) noexcept; // default RValue Copy constructer 디폴트 RValue 복사생성자

public:		//delete operator
	GameServerPath& operator=(const GameServerPath& _other) = delete; // default Copy operator 디폴트 대입 연산자
	GameServerPath& operator=(const GameServerPath&& _other) = delete; // default RValue Copy operator 디폴트 RValue 대입연산자

public:
	static std::string GetFileName(std::string _Path);
	std::string GetFileName();

	std::string GetFileNameWithOutExtension();

public:		//member Func
	// 유요한 경로인가 아닌가를 판단하는 함수.
	bool IsExist();

	std::string GetFullPath();

};

