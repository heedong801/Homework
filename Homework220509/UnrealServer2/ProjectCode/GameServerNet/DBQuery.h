#pragma once
#include "DBConnecter.h"

// 설명 :
class DBQuery
{
public:
	DBQuery(const char* _Query);
	~DBQuery();
	DBQuery(const DBQuery& _Other) = delete;
	DBQuery(DBQuery&& _Other) noexcept = delete;
	DBQuery& operator=(const DBQuery& _Other) = delete;
	DBQuery& operator=(DBQuery&& _Other) noexcept = delete;

	// 이함수를 실행해야만 쿼리가 db에 날아간다.
	virtual bool DoQuery() = 0;

protected:
	DBConnecter* DBConnecterPtr;
	const char* QueryString;

private:

	
};

