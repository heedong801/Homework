#include "PreCompile.h"
#include "RedisConnecter.h"

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

// 쿼리가 있을것이고
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
