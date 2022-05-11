#pragma once
#include "DBConnecter.h"

// Ό³Έν :
class DBTableBase
{
public:
	// constrcuter destructer
	DBTableBase(DBConnecter* _Connecter);
	~DBTableBase();

	// delete Function
	DBTableBase(const DBTableBase& _Other) = delete;
	DBTableBase(DBTableBase&& _Other) noexcept = delete;
	DBTableBase& operator=(const DBTableBase& _Other) = delete;
	DBTableBase& operator=(DBTableBase&& _Other) noexcept = delete;

protected:

private:
	DBConnecter* Connecter_;
};

