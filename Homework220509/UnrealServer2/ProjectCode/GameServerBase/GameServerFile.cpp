#include "PreCompile.h"
#include "GameServerFile.h"
#include "GameServerDebug.h"


// Static Var
// Static Func

// constructer destructer
GameServerFile::GameServerFile()
	: OpenMode(""), fileHandle_(nullptr)
{
}

GameServerFile::GameServerFile(const char* _Path) 
	: GameServerPath(_Path), fileHandle_(nullptr)
{

}

GameServerFile::GameServerFile(const std::filesystem::path& _Path) 
	: GameServerPath(_Path), fileHandle_(nullptr)
{

}

GameServerFile::GameServerFile(const std::string& _Path, const std::string& _OpenType)
	: fileHandle_(nullptr)
{
	path_ = _Path;

	Open(_OpenType);

	if (false == IsExist())
	{
		GameServerDebug::AssertDebug();
	}
}

GameServerFile::GameServerFile(const std::string& _Path)
{
	path_ = _Path;


	if (false == IsExist())
	{
		GameServerDebug::AssertDebug();
	}
}

GameServerFile::~GameServerFile()
{
	Close();
}

GameServerFile::GameServerFile(GameServerFile&& _other) noexcept
	: GameServerPath(_other), fileHandle_(nullptr)
{
}

//member Func

void GameServerFile::Open(const std::string& _Mode) 
{
	OpenMode = _Mode;
	fopen_s(&fileHandle_, path_.string().c_str(), _Mode.c_str());
	if (nullptr == fileHandle_)
	{
		GameServerDebug::AssertDebug();
	}
}

void GameServerFile::Close() 
{
	if (nullptr != fileHandle_)
	{
		fclose(fileHandle_);
		fileHandle_ = nullptr;
	}
}

void GameServerFile::Write(const void* _Data, size_t _Size) 
{
	// ��������� ������ ���� �ʰ�
	// �� ������ �ϴ³Ŀ� ���� ����ó���Դϴ�.
	if (OpenMode[0] != 'w')
	{
		GameServerDebug::AssertDebug();
		return;
	}

	// ������ ���� ������ ����Ϸ��� �ߴ�.
	if (nullptr == fileHandle_)
	{
		GameServerDebug::AssertDebug();
		return;
	}

	fwrite(_Data, _Size, 1, fileHandle_);
}

void GameServerFile::Read(void* _Buffer, size_t _BufferSize, size_t _DataSize)
{
	// ��������� ������ ���� �ʰ�
// �� ������ �ϴ³Ŀ� ���� ����ó���Դϴ�.
	if (OpenMode[0] != 'r')
	{
		GameServerDebug::AssertDebug();
		return;
	}

	// ������ ���� ������ ����Ϸ��� �ߴ�.
	if (nullptr == fileHandle_)
	{
		GameServerDebug::AssertDebug();
		return;
	}

	fread_s(_Buffer, _BufferSize, _DataSize, 1, fileHandle_);

}

void GameServerFile::Write(const std::string& _Data)
{
	// ũ�⸦ ��������� �մϴ�.
	// string��? ũ�Ⱑ ������ �����͸� ������ �ֳ���?
	int Size = static_cast<int>(_Data.size());
	Write(&Size, sizeof(int));
	Write(_Data.c_str(), _Data.size());
}

void GameServerFile::Write(const std::wstring& _Data) 
{
	int Size = static_cast<int>(_Data.size() * 2);
	Write(&Size, sizeof(int));
	Write(_Data.c_str(), _Data.size());
}

void GameServerFile::Write(const int& _Data)
{
	Write(&_Data, sizeof(int));
}


void GameServerFile::Read(std::string& _Data)
{
	int Size = 0;
	Read(&Size, sizeof(int), sizeof(int));
	_Data.resize(Size);
	Read(&_Data[0], Size, Size);
}
void GameServerFile::Read(int& _Data)
{
	Read(&_Data, sizeof(int), sizeof(int));
}

uintmax_t GameServerFile::GetFileSize() 
{
	return std::filesystem::file_size(path_);
}

std::string GameServerFile::GetString() 
{
	std::string AllString = std::string();

	AllString.resize(GetFileSize());

	for (size_t i = 0; i < AllString.size(); i++)
	{
		Read(&AllString[i], 1, 1);
	}


	while (AllString[AllString.size() - 1] == 0)
	{
		AllString.erase(--AllString.end());
	}

	return AllString;
}

std::string GameServerFile::FileName() 
{
	return path_.filename().string();
}