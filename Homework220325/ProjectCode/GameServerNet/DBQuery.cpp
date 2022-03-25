#include "PreCompile.h"
#include "DBQuery.h"
#include "DBConnecter.h"
#include <GameServerBase/GameServerThread.h>

DBQuery::DBQuery(const char* _Query)
	: DBConnecterPtr(GameServerThread::GetLocalData<DBConnecter>())
	, QueryString(_Query)
{
}

DBQuery::~DBQuery() 
{
}
