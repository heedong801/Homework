#include "PreCompile.h"
#include "GameServerString.h"
#include "GameServerDebug.h"
#include <sstream>

GameServerString::GameServerString() 
{

}

GameServerString::~GameServerString() 
{

}

GameServerString::GameServerString(GameServerString&& _Other) noexcept
{

}

bool GameServerString::UTF8ToUniCode(const std::string& _UTF8, std::wstring& _UnicodeResult)
{
	// 변환기능 외에도 
	//_In_ UINT CodePage, 변환하려는 byte의 문자열 인코딩 방식
	//_In_ DWORD dwFlags,
	//_In_NLS_string_(cbMultiByte) LPCCH lpMultiByteStr,
	//_In_ int cbMultiByte,
	//_Out_writes_to_opt_(cchWideChar, return) LPWSTR lpWideCharStr,
	//_In_ int cchWideChar

	_UnicodeResult.clear();

	// 변환했을때 길이가 얼마일지 나옵니다.
	int32_t Len = MultiByteToWideChar(
		CP_UTF8, 
		0, 
		_UTF8.c_str(), 
		static_cast<int32_t>(_UTF8.size()),
		nullptr,
		0
	);

	if (0 >= Len)
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
	}

	_UnicodeResult.resize(Len);

	Len = MultiByteToWideChar(
		CP_UTF8,
		0,
		_UTF8.c_str(),
		static_cast<int32_t>(_UTF8.size()),
		&_UnicodeResult[0],
		Len
	);

	if (0 >= Len)
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
	}

	return true;
}

//
//std::string GameServerString::UTF8ToString(std::string _Text) {
//
//}

bool GameServerString::UniCodeToAnsi(const std::wstring& _Unicode, std::string& _AnsiString)
{
	//_In_ UINT CodePage,
	//	_In_ DWORD dwFlags,
	//	_In_NLS_string_(cchWideChar) LPCWCH lpWideCharStr,
	//	_In_ int cchWideChar,
	//	_Out_writes_bytes_to_opt_(cbMultiByte, return) LPSTR lpMultiByteStr,
	//	_In_ int cbMultiByte,
	//	_In_opt_ LPCCH lpDefaultChar,
	//	_Out_opt_ LPBOOL lpUsedDefaultChar

	int32_t Len = WideCharToMultiByte(
		CP_ACP,
		0,
		_Unicode.c_str(),
		static_cast<int32_t>(_Unicode.size()),
		nullptr,
		0,
		nullptr,
		nullptr
	);


	if (0 >= Len)
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
	}

	_AnsiString.resize(Len);

	Len = WideCharToMultiByte(
		CP_ACP,
		0,
		_Unicode.c_str(),
		static_cast<int32_t>(_Unicode.size()),
		&_AnsiString[0],
		static_cast<int32_t>(_AnsiString.size()),
		nullptr,
		nullptr
	);

	return true;
}


bool GameServerString::AnsiToUnicode(const std::string& _Ansi, std::wstring& _Unicode)
{
	int32_t Len = MultiByteToWideChar(
		CP_ACP,
		0,
		_Ansi.c_str(),
		static_cast<int32_t>(_Ansi.size()),
		nullptr,
		0
	);


	if (0 >= Len)
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
	}

	_Unicode.resize(Len);

	Len = MultiByteToWideChar(
		CP_ACP,
		0,
		_Ansi.c_str(),
		static_cast<int32_t>(_Ansi.size()),
		&_Unicode[0],
		static_cast<int32_t>(_Unicode.size())
	);

	return true;
}


bool GameServerString::UniCodeToUTF8(const std::wstring& _Unicode, std::string& _UTF8) {

	int32_t Len = WideCharToMultiByte(
		CP_UTF8,
		0,
		_Unicode.c_str(),
		static_cast<int32_t>(_Unicode.size()),
		nullptr,
		0,
		nullptr,
		nullptr
	);


	if (0 >= Len)
	{
		GameServerDebug::GetLastErrorPrint();
		return false;
	}

	_UTF8.resize(Len);

	Len = WideCharToMultiByte(
		CP_UTF8,
		0,
		_Unicode.c_str(),
		static_cast<int32_t>(_Unicode.size()),
		&_UTF8[0],
		static_cast<int32_t>(_UTF8.size()),
		nullptr,
		nullptr
	);

	return true;
}

std::string GameServerString::UTF8ToAnsi(const std::string& _UTF8)
{
	std::string Ansi;
	std::wstring UniCode;
	if (false == UTF8ToUniCode(_UTF8, UniCode))
	{
		GameServerDebug::AssertDebugMsg("UTF8 => Ansi ConvertError");
	}
	if (false == UniCodeToAnsi(UniCode, Ansi))
	{
		GameServerDebug::AssertDebugMsg("UniCode => Ansi ConvertError");
	}

	return Ansi;
}

bool GameServerString::UTF8ToAnsi(const std::string& _UTF8, std::string& _Ansi) 
{
	std::wstring UniCode;
	if (false == UTF8ToUniCode(_UTF8, UniCode))
	{
		GameServerDebug::AssertDebugMsg("UTF8 => Ansi ConvertError");
	}
	if(false == UniCodeToAnsi(UniCode, _Ansi))
	{
		GameServerDebug::AssertDebugMsg("UniCode => Ansi ConvertError");
	}

	return true;
}

bool GameServerString::AnsiToUTF8(const std::string& _Ansi, std::string& _UTF8)
{
	std::wstring UniCode;
	if (false == AnsiToUnicode(_Ansi, UniCode))
	{
		GameServerDebug::AssertDebugMsg("UTF8 => Ansi ConvertError");
	}
	if (false == UniCodeToUTF8(UniCode, _UTF8))
	{
		GameServerDebug::AssertDebugMsg("UniCode => Ansi ConvertError");
	}

	return true;
}

std::vector<std::string> GameServerString::split(const std::string& input, char delimiter) 
{
	std::vector<std::string> answer;
	std::stringstream ss(input);
	std::string temp;

	while (getline(ss, temp, delimiter)) 
	{
		if (temp == "")
		{
			continue;
		}
		answer.push_back(temp);
	}

	return answer;
}

void GameServerString::Replace(std::string& _Text, const std::string& _Prev, const std::string& _Next, int _Count /*= 1*/)
{
	int cnt = 0;
	while (_Count > cnt++)
	{
		size_t startIdx = _Text.find(_Prev);
		if (startIdx == std::string::npos)
			return;
		_Text.replace(startIdx, _Prev.length(), _Next);
	}
	return;
}

// 삽입하려는 인덱스가 문자열 길이보다 클 경우 삽입 x, 인덱스가 0보다 작을경우 삽입 x
void GameServerString::Insert(std::string& _Text, int _Index, const std::string& _InsertText)
{
	if (_Text.length() < _Index || _Index < 0)
		return;
	_Text.insert(_Index, _InsertText);
}

// 공백 제거
void GameServerString::TrimRemove(std::string& _Text)
{
	Replace(_Text, " ", "", static_cast<int>(_Text.length()));
}

void GameServerString::ToUpper(std::string& _Text)
{
	std::transform(_Text.begin(), _Text.end(), _Text.begin(), [](const char& c) { return std::toupper(c); });
}

// 전부 삭제
void GameServerString::Remove(std::string& _Text, const std::string& _DeleteText)
{
	Replace(_Text, _DeleteText, "", static_cast<int>(_Text.length()));
}

void GameServerString::ClearText(std::string& _Text)
{
	Replace(_Text, "\t", "", static_cast<int>(_Text.length()));
	Replace(_Text, "\n", "", static_cast<int>(_Text.length()));
}