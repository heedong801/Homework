#pragma once
#include <..\ProjectCode\Thirdparty\Mysql\include\mysql.h>
#include <string>
#include <string_view>
#include <vector>

class DBStmt;
class DBConnecter;
class DBStmtResult : public std::enable_shared_from_this<DBStmt> 
{
	friend DBStmt;

public:
	DBStmtResult(DBConnecter* _Ptr, MYSQL_STMT* _stmt, std::string_view _Query);

private:
	std::vector<unsigned long> ResultLengthBuffer_;
	std::vector<char> ResultIsNullBuffer_;
	std::vector<char> ResultBindBuffer_;

	// 특정할수 없는 정보들을 1개 1개마다 바인드시키는데 사용하는것을 
	// MYSQL_BIND 구조체를 통해서 바인드 시킬수 있다.
	std::vector<MYSQL_BIND> ResultBinds_;

	DBConnecter* DBConnecterPtr_;
	std::string_view Query_;
	MYSQL_STMT* Stmt_;


public:

	inline uint64_t AffectedRows() { return mysql_stmt_affected_rows(Stmt_); };

	bool Next();

	std::string GetString(const int _Value);
	int GetInt(const int _Value);
};

class DBConnecter;
class DBStmt : public std::enable_shared_from_this<DBStmt>
{
public:
	DBStmt(DBConnecter* _Ptr, MYSQL_STMT* _stmt, std::string_view _Query);


	// ??에 바인드 시키기 위한 정보체를 만들어줘야 합니다.
	// 인자들에 대한 바인드 ? string

	std::vector<unsigned long> ParamLengthBuffer_;
	std::vector<char> ParamIsNullBuffer_;
	std::vector<char> ParamBindBuffer_;

	std::vector<MYSQL_BIND> Parambinds_;

	DBConnecter* DBConnecterPtr_;
	std::string_view Query_;
	MYSQL_STMT* Stmt_;

public:
	void ParamBindString(std::string_view _Value);
	void ParamBindInt(const int _Value);
	void ParamBindFloat(const float _Value);

public:
	std::unique_ptr<DBStmtResult> Execute();

	// uint64_t Id = mysql_stmt_insert_id(Stmt_);
	// 오토인클리먼트 했을때 아이디가 나올겁니다.
	inline uint64_t InsertId() { return mysql_stmt_insert_id(Stmt_); };

	inline uint64_t AffectedRows() { return mysql_stmt_affected_rows(Stmt_); };
};

// 설명 :
class DBConnecter
{
public:
	// constrcuter destructer
	DBConnecter();
	~DBConnecter();

	// delete Function
	DBConnecter(const DBConnecter& _Other) = delete;
	DBConnecter(DBConnecter&& _Other) noexcept = delete;
	DBConnecter& operator=(const DBConnecter& _Other) = delete;
	DBConnecter& operator=(DBConnecter&& _Other) noexcept = delete;

	std::unique_ptr<DBStmt> CreateStmt(std::string_view _Query);

	void ConnectInfoSetting(
		const std::string& _Host,
		const std::string& _Id,
		const std::string& _Pw,
		const std::string& _Schema,
		unsigned int _Port
	);

	bool Connect();

	// 이 커넥트는 한번 무조건 호출해줘야 한다.
	bool Connect(
		const std::string& _Host,
		const std::string& _Id,
		const std::string& _Pw,
		const std::string& _Schema,
		unsigned int _Port
	);

	inline bool IsConnect() const
	{


		return mysql_ != nullptr;
	}

	std::string GetLastError();

protected:

private:
	MYSQL* mysql_;
	std::string Host_;
	std::string Id_;
	std::string Pw_;
	std::string Schema_;
	unsigned int Port_;
};

