#include "PreCompile.h"
#include "GameServerPath.h"


// Static Var
// Static Func

// constructer destructer
GameServerPath::GameServerPath()
	: path_("")
{
}

GameServerPath::GameServerPath(std::filesystem::path _path) 
	: path_(_path)
{

}

GameServerPath::~GameServerPath()
{
}


GameServerPath::GameServerPath(const GameServerPath& _other) 
	: path_(_other.path_)
{

}

GameServerPath::GameServerPath(GameServerPath&& _other) noexcept
{
}

//member Func

bool GameServerPath::IsExist()
{
	return std::filesystem::exists(path_);
}

std::string GameServerPath::GetFileName(std::string _Path) 
{
	std::filesystem::path NewPath = _Path;
	return NewPath.filename().string();
}

std::string GameServerPath::GetFullPath()
{
	return path_.string();
}

std::string GameServerPath::GetFileName() 
{
	return path_.filename().string();
}

std::string GameServerPath::GetFileNameWithOutExtension()
{
	std::string Ex = path_.extension().string();
	std::string FileName = path_.filename().string();
	return FileName.erase(FileName.size() - Ex.size(), Ex.size());
}