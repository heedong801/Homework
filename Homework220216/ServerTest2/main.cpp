#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<assert.h>
class String
{
public:

    static void Replace(std::string& _Text, const std::string& _Prev, const std::string& _Next, int _Count = 1)
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

    // "ffasdfsdafdas" "cccc"
    static void Insert(std::string& _Text, int _Index, const std::string& _InsertText)
    {
        if (_Text.length() < _Index)
            return;
        _Text.insert(_Index, _InsertText);
    }

    // ' '
    static void TrimRemove(std::string& _Text)
    {
        Replace(_Text, " ", "", _Text.length() - 1);
    }

    // 한글이 섞여있어도.
    static void ToUpper(std::string& _Text)
    {
        std::transform(_Text.begin(), _Text.end(), _Text.begin(), [](const char& c) { return std::toupper(c); });
    }

    // ReMove
    static void Remove(std::string& _Text, const std::string& _DeleteText)
    {
        Replace(_Text, _DeleteText, "", _Text.length() - 1);
    }
};


int main()
{
    std::string a = "111 2222 33444 455 6";
    std::string b = "22";
    std::string c = "777";
    std::string d = "aAc";
    //String::Replace(a, b, c, -1);
    //String::Insert(a, 124241, c);
    //String::ToUpper(d);
    String::Remove(a, b);
    String::TrimRemove(a);
    std::cout << a << std::endl;
}


