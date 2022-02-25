#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<assert.h>
class String
{
public:

    // 큰수가 들어와도 다 바뀌었으면 끝, 음수가 들어오면 변하지 않고 끝, 찾으려는 문자열이 없으면 그냥 그대로
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

    // 삽입하려는 인덱스가 문자열 길이보다 클 경우 삽입 x, 인덱스가 0보다 작을경우 삽입 x
    static void Insert(std::string& _Text, int _Index, const std::string& _InsertText)
    {
        if (_Text.length() < _Index || _Index < 0)
            return;
        _Text.insert(_Index, _InsertText);
    }

    // 공백 제거
    static void TrimRemove(std::string& _Text)
    {
        Replace(_Text, " ", "", static_cast<int>(_Text.length()));
    }

    static void ToUpper(std::string& _Text)
    {
        std::transform(_Text.begin(), _Text.end(), _Text.begin(), [](const char& c) { return std::toupper(c); });
    }

    // 전부 삭제
    static void Remove(std::string& _Text, const std::string& _DeleteText)
    {
        Replace(_Text, _DeleteText, "", static_cast<int>(_Text.length()));
    }
};


int main()
{
    std::string a = "aaaa";


    String::Remove(a, "a");
    std::cout << a << std::endl;
}


