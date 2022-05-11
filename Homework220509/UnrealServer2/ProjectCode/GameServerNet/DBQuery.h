#pragma once
#include "DBConnecter.h"

// ���� :
class DBQuery
{
public:
	DBQuery(const char* _Query);
	~DBQuery();
	DBQuery(const DBQuery& _Other) = delete;
	DBQuery(DBQuery&& _Other) noexcept = delete;
	DBQuery& operator=(const DBQuery& _Other) = delete;
	DBQuery& operator=(DBQuery&& _Other) noexcept = delete;

	// ���Լ��� �����ؾ߸� ������ db�� ���ư���.
	virtual bool DoQuery() = 0;

protected:
	DBConnecter* DBConnecterPtr;
	const char* QueryString;

private:

	
};

