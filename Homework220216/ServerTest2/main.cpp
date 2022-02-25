#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<assert.h>
class String
{
public:

    // ū���� ���͵� �� �ٲ������ ��, ������ ������ ������ �ʰ� ��, ã������ ���ڿ��� ������ �׳� �״��
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

    // �����Ϸ��� �ε����� ���ڿ� ���̺��� Ŭ ��� ���� x, �ε����� 0���� ������� ���� x
    static void Insert(std::string& _Text, int _Index, const std::string& _InsertText)
    {
        if (_Text.length() < _Index || _Index < 0)
            return;
        _Text.insert(_Index, _InsertText);
    }

    // ���� ����
    static void TrimRemove(std::string& _Text)
    {
        Replace(_Text, " ", "", static_cast<int>(_Text.length()));
    }

    static void ToUpper(std::string& _Text)
    {
        std::transform(_Text.begin(), _Text.end(), _Text.begin(), [](const char& c) { return std::toupper(c); });
    }

    // ���� ����
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


