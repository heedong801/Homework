#pragma once

// �뵵 : 
// �з� :
// ÷�� : 
class GameServerString
{
public: // Member Var
	// �����ʿ����� ����Ҵ�� ������ string
	// �������� utf8

	// �𸮾���?
	// ����Ҷ��� FString ????? UNICODE
	// �������� utf8

	static bool UTF8ToUniCode(const std::string& _UTF8, std::wstring& _Unicode);
	static bool UniCodeToAnsi(const std::wstring& _Unicode, std::string& _Ansi);

	static bool AnsiToUnicode(const std::string& _Ansi, std::wstring& _Unicode);
	static bool UniCodeToUTF8(const std::wstring& _Unicode, std::string& _UTF8);

	static bool UTF8ToAnsi(const std::string& _UTF8, std::string& _Ansi);
	static bool AnsiToUTF8(const std::string& _Ansi, std::string& _UTF8);

	static std::string UTF8ToAnsi(const std::string& _UTF8);

	static std::vector<std::string> split(const std::string& input, char delimiter);

    static void Replace(std::string& _Text, const std::string& _Prev, const std::string& _Next, int _Count = 1);
    
	static void Insert(std::string& _Text, int _Index, const std::string& _InsertText);
    
	static void TrimRemove(std::string& _Text);

	static void ToUpper(std::string& _Text);
    
	static void Remove(std::string& _Text, const std::string& _DeleteText);

	static void ClearText(std::string& _Text);

public: // Default
	GameServerString();
	~GameServerString();

	GameServerString(const GameServerString& _Other) = delete;
	GameServerString(GameServerString&& _Other) noexcept;

protected:
	GameServerString& operator=(const GameServerString& _Other) = delete;
	GameServerString& operator=(GameServerString&& _Other) = delete;

private:

public: // Member Function
};

