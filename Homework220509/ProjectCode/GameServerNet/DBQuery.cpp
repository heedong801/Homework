#include "PreCompile.h"
#include "DBQuery.h"
#include "DBConnecter.h"
#include <GameServerBase/GameServerThread.h>

DBQuery::DBQuery(const char* _Query)
	: DBConnecterPtr(GameServerThread::GetLocalData<DBConnecter>(0))
	, QueryString(_Query)
{
}

DBQuery::~DBQuery() 
{
}
