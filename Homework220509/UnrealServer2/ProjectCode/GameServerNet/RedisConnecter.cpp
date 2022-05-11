#include "PreCompile.h"
#include "RedisConnecter.h"

thread_local std::vector<std::shared_ptr<RedisConnecter>> RedisConnecter::AllConnector;


void RedisConnecter::InitConntor(const std::string& _Host, unsigned int _Port, int _Index /*= 0*/)
{
	AllConnector.resize(_Index + 1);
	AllConnector[_Index] = std::make_shared<RedisConnecter>();
	AllConnector[_Index]->Connect(_Host, _Port);
}

std::shared_ptr<RedisConnecter> RedisConnecter::GetConnector(int _Index /*= 0*/)
{
	return AllConnector[_Index];
}

RedisConnecter::RedisConnecter() 
{
}

RedisConnecter::~RedisConnecter() 
{
}

bool RedisConnecter::Connect(const std::string& _Host, unsigned int _Port)
{
	return Session_.ConnectSync(_Host, _Port);
}

void RedisConnecter::Close()
{
	Session_.Close();
}

// ������ �������̰�
// aaaa 10000
// aaaa 10000
// ddd 10000
// rrr 10000
// aaaa 10000
// aaaa 10000
// bbb 9000
// ccc 100

void RedisConnecter::Query(class RedisCommendBase& _Query) 
{
	_Query.Result = Query(_Query.Query);
}

// "SET aaa"
std::string RedisConnecter::Query(const std::string& _Query) 
{
	Session_.SendSync(_Query.c_str(), _Query.size());
	char NewData[1024] = {0};
	std::string Result;
	Result.reserve(1024);
	Session_.RecvSync(NewData, 1024);
	Result += std::string(NewData);
	return Result;
}

void RedisCommendBase::Process(class RedisConnecter& _Con)
{
	Result = _Con.Query(Query);

	ConvertResult();
}
