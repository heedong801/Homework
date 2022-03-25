#pragma once
#include "GameServerPath.h"
// 분류 :
// 용도 :
// 설명 :

class GameServerFile;
class GameServerDirectory : public GameServerPath
{
public:
	GameServerDirectory(); // default constructer 디폴트 생성자
	~GameServerDirectory(); // default destructer 디폴트 소멸자

public:		// delete constructer
	GameServerDirectory(const GameServerDirectory& _other); // default Copy constructer 디폴트 복사생성자
	GameServerDirectory(GameServerDirectory&& _other) noexcept; // default RValue Copy constructer 디폴트 RValue 복사생성자

public:		//delete operator
	GameServerDirectory& operator=(const GameServerDirectory& _other) = delete; // default Copy operator 디폴트 대입 연산자
	GameServerDirectory& operator=(const GameServerDirectory&& _other) = delete; // default RValue Copy operator 디폴트 RValue 대입연산자

public:
	std::string DirectoryName();

public:		//member Func
	// C: D:인지 확인
	bool IsRoot();

	// 부모폴더로 이동
	void MoveParent();

	// 부모폴더중 _DirName을 가진 폴더로 이동
	bool MoveParent(const std::string& _DirName);

	// 자식 폴더중 _DirName으로 이동
	bool MoveChild(const std::string& _DirName);

public:
	// 내 폴더에 + 파일이름 경로를 리턴해주는 함수
	std::string PathToPlusFileName(const std::string& _FileName);

	// * 의 의미
	// A* 모든 이름
	// ABVBBB 됨
	// CAFDSA 안됨
	// .
	// * 모든 확장자
	std::vector<GameServerFile> GetAllFile(const std::string& _filter = "*");
};

