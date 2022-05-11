#include "PreCompile.h"
#include "DBConnecter.h"
#include <GameServerBase\GameServerDebug.h>

/////////////////////////////////////////////// STMT Result
DBStmtResult::DBStmtResult(DBConnecter* _ConncterPtr, MYSQL_STMT* _Stmt, std::string_view _Query)
	: DBConnecterPtr_(_ConncterPtr)
	, Query_(_Query)
	, Stmt_(_Stmt)
{
	ResultLengthBuffer_.reserve(20);
	ResultIsNullBuffer_.reserve(20);
	ResultBindBuffer_.reserve(1024);
}

bool DBStmtResult::Next() 
{
	// 다음게 없다면 0 != 다음녀석이 없다.
	return 0 == mysql_stmt_fetch(Stmt_);
}

std::string DBStmtResult::GetString(const int _Index)
{
	return std::string(reinterpret_cast<char*>(ResultBinds_[_Index].buffer));
}

int DBStmtResult::GetInt(const int _Index)
{
	return *reinterpret_cast<int32_t*>(ResultBinds_[_Index].buffer);
}


float DBStmtResult::GetFloat(const int _Index)
{
	return *reinterpret_cast<float*>(ResultBinds_[_Index].buffer);
}


/////////////////////////////////////////////// STMT
DBStmt::DBStmt(DBConnecter* _ConncterPtr, MYSQL_STMT* _Stmt, std::string_view _Query)
	: DBConnecterPtr_(_ConncterPtr)
	, Query_(_Query)
	, Stmt_(_Stmt)
{
	ParamLengthBuffer_.reserve(20);
	ParamIsNullBuffer_.reserve(20);
	ParamBindBuffer_.reserve(1024);

}

void DBStmt::ParamBindString(std::string_view _Value)
{
	ParamLengthBuffer_.emplace_back();
	ParamIsNullBuffer_.emplace_back();
	size_t Size = ParamBindBuffer_.size();
	ParamBindBuffer_.resize(ParamBindBuffer_.size() + _Value.size());

	// 선확장 후보고
	MYSQL_BIND& Bind = Parambinds_.emplace_back();
	Bind.buffer_type = MYSQL_TYPE_VARCHAR;
	Bind.buffer = &ParamBindBuffer_[Size];
	memset(Bind.buffer, 0x00, _Value.size() + 1);
	memcpy_s(Bind.buffer, _Value.length(), _Value.data(), _Value.length());
	Bind.buffer_length = static_cast<unsigned long>(_Value.length());
	Bind.is_null = reinterpret_cast<bool*>(&ParamIsNullBuffer_[ParamIsNullBuffer_.size() - 1]);
	*Bind.is_null = false;
	Bind.length = &ParamLengthBuffer_[ParamLengthBuffer_.size() - 1];
	*Bind.length = Bind.buffer_length;
}
void DBStmt::ParamBindInt(const int _Value)
{
	ParamLengthBuffer_.emplace_back();
	ParamIsNullBuffer_.emplace_back();
	size_t Size = ParamBindBuffer_.size();
	ParamBindBuffer_.resize(ParamBindBuffer_.size() + sizeof(int));

	// 선확장 후보고
	MYSQL_BIND& Bind = Parambinds_.emplace_back();
	Bind.buffer_type = MYSQL_TYPE_LONG;
	Bind.buffer = &ParamBindBuffer_[Size];
	memset(Bind.buffer, 0x00, sizeof(int));
	memcpy_s(Bind.buffer, sizeof(int), &_Value, sizeof(int));
	Bind.buffer_length = static_cast<unsigned long>(sizeof(int));
	Bind.is_null = reinterpret_cast<bool*>(&ParamIsNullBuffer_[ParamIsNullBuffer_.size() - 1]);
	*Bind.is_null = false;
	Bind.length = &ParamLengthBuffer_[ParamLengthBuffer_.size() - 1];
	*Bind.length = Bind.buffer_length;
}
void DBStmt::ParamBindFloat(const float _Value)
{

}


std::unique_ptr<DBStmtResult> DBStmt::Execute()
{
	// ?가 1개인데
	int ParamCount = mysql_stmt_param_count(Stmt_);

	// 바인드는 아직 안되어있고
	// 넣어놓지 않았으면 안된다.
	if (ParamCount != Parambinds_.size())
	{
		GameServerDebug::AssertDebugMsg("query bind count not Equal");
		return nullptr;
	}

	if (0 != ParamCount)
	{
		if (0 != mysql_stmt_bind_param(Stmt_, &Parambinds_[0]))
		{
			GameServerDebug::AssertDebugMsg("mysql_stmt_bind_param Error" + DBConnecterPtr_->GetLastError());
			return nullptr;
		}
	}

	MYSQL_RES* ResultMetaData = mysql_stmt_result_metadata(Stmt_);
	// 당연히 이 쿼리가 select 쿼리가 아니라면
	// 결과값이 없을수가 있죠?

	std::unique_ptr<DBStmtResult> Result = nullptr;

	if (nullptr != ResultMetaData)
	{
		Result = std::make_unique<DBStmtResult>(DBConnecterPtr_, Stmt_, Query_);

		// 이게 nullptr이 아니라면 결과값이 나올거라는 이야기이가 되고
		// 결과값의 columncount와 그 row카운트를 알아내야 한다.
		int ColumnCount = mysql_num_fields(ResultMetaData);
		for (size_t i = 0; i < ColumnCount; i++)
		{
			MYSQL_BIND& ResultBind = Result->ResultBinds_.emplace_back();
			Result->ResultIsNullBuffer_.emplace_back();
			Result->ResultLengthBuffer_.emplace_back();

			MYSQL_FIELD& field = ResultMetaData->fields[i];

			size_t BufferStart = Result->ResultBindBuffer_.size();
			// 나는 int에요
			// 나는 string이에요
			switch (field.type)
			{
			case enum_field_types::MYSQL_TYPE_VAR_STRING:
			{
				Result->ResultBindBuffer_.resize(Result->ResultBindBuffer_.size() + field.length + 1);
				ResultBind.buffer_type = enum_field_types::MYSQL_TYPE_VAR_STRING;
				ResultBind.buffer = &Result->ResultBindBuffer_[BufferStart];
				// ResultBind.buffer = new char[field.length + 1];
				ResultBind.buffer_length = field.length + 1;
				memset(ResultBind.buffer, 0x00, field.length + 1);
				ResultBind.is_null = reinterpret_cast<bool*>(&Result->ResultIsNullBuffer_[Result->ResultIsNullBuffer_.size() - 1]);
				*ResultBind.is_null = false;
				ResultBind.length = &Result->ResultLengthBuffer_[Result->ResultLengthBuffer_.size() - 1];
				break;
			}
			case enum_field_types::MYSQL_TYPE_LONG:
			{
				Result->ResultBindBuffer_.resize(Result->ResultBindBuffer_.size() + sizeof(int));
				ResultBind.buffer_type = enum_field_types::MYSQL_TYPE_LONG;
				ResultBind.buffer = &Result->ResultBindBuffer_[BufferStart];
				// ResultBind.buffer = new char[sizeof(int)];
				ResultBind.buffer_length = sizeof(int);
				memset(ResultBind.buffer, 0x00, sizeof(int));
				ResultBind.is_null = reinterpret_cast<bool*>(&Result->ResultIsNullBuffer_[Result->ResultIsNullBuffer_.size() - 1]);
				*ResultBind.is_null = false;
				ResultBind.length = &Result->ResultLengthBuffer_[Result->ResultLengthBuffer_.size() - 1];
				break;
			}
			case enum_field_types::MYSQL_TYPE_FLOAT:
			{
				Result->ResultBindBuffer_.resize(Result->ResultBindBuffer_.size() + sizeof(float));
				ResultBind.buffer_type = enum_field_types::MYSQL_TYPE_FLOAT;
				ResultBind.buffer = &Result->ResultBindBuffer_[BufferStart];
				// ResultBind.buffer = new char[sizeof(int)];
				ResultBind.buffer_length = sizeof(float);
				memset(ResultBind.buffer, 0x00, sizeof(float));
				ResultBind.is_null = reinterpret_cast<bool*>(&Result->ResultIsNullBuffer_[Result->ResultIsNullBuffer_.size() - 1]);
				*ResultBind.is_null = false;
				ResultBind.length = &Result->ResultLengthBuffer_[Result->ResultLengthBuffer_.size() - 1];
				break;
			}
			default:
				GameServerDebug::AssertDebugMsg("mysql result type switch error");
				break;
			}
		}

		if (0 != mysql_stmt_bind_result(Stmt_, &Result->ResultBinds_[0]))
		{
			GameServerDebug::AssertDebugMsg("mysql_stmt_bind_result Error" + DBConnecterPtr_->GetLastError());
			return nullptr;
		}

	}

	// 쿼리를 날려라.
	if (0 != mysql_stmt_execute(Stmt_))
	{
		DBConnecterPtr_->GetLastError();

		// 이건 지워져도 된다. 여러분들이 
		// GameServerDebug::AssertDebugMsg("mysql_stmt_execute Error" + DBConnecterPtr_->GetLastError());
		// GameServerDebug::AssertDebugMsg("mysql_stmt_execute Error" + DBConnecterPtr_->GetLastError());
		return nullptr;
	}

	// 날린 결과를 받아온겁니다.
	if (0 != mysql_stmt_store_result(Stmt_))
	{
		GameServerDebug::AssertDebugMsg("mysql_stmt_store_result Error" + DBConnecterPtr_->GetLastError());
		return nullptr;
	}


	// db 가 어떻게 변화됐고..
	//uint64_t Id = mysql_stmt_insert_id(Stmt_);
	//// 늘어난 로우 개수를 알아올수가 있습니다.
	//// 내가 들어갈때 하나 증가한 값이 아닐수가 있습니다.
	//uint64_t Row = mysql_stmt_affected_rows(Stmt_);

	// 저쪽에 들어있는 값은 
	// 내가 받아볼 값이 long

	if (nullptr != ResultMetaData)
	{
		mysql_free_result(ResultMetaData);
	}

	return Result;
	// mysql_stmt_result_metadata(Stmt_);
	


}

/////////////////////////////////////////////// CONNECTER


DBConnecter::DBConnecter()
	: mysql_(nullptr)
{
}

DBConnecter::~DBConnecter()
{
}

void DBConnecter::Reset() 
{
	mysql_ = nullptr;
	Host_ = std::string();
	Id_ = std::string();
	Pw_ = std::string();
	Schema_ = std::string();

}

// 스테이트먼트 제작
// 스테이트먼트는 내가 넣으려는 인자값을 mysql라이브러리 
// 수준에서 방어하고 싶을때 사용하는
// 쿼리 형식이다.
std::unique_ptr<DBStmt> DBConnecter::CreateStmt(std::string_view _Query)
{
	// 프레그먼트 쿼리를 보내기 위한것으로 다이나믹 쿼리라면 이걸 만들필요가 없다.
	MYSQL_STMT* stmt = mysql_stmt_init(mysql_);

	if (nullptr == stmt)
	{
		GameServerDebug::AssertDebugMsg("mysql Statememnt Create Error");
		return nullptr;
	}

	if (0 != mysql_stmt_prepare(stmt, _Query.data(), static_cast<unsigned long>(_Query.length())))
	{
		mysql_stmt_close(stmt);
		GameServerDebug::AssertDebugMsg("mysql Statememnt mysql_stmt_prepare Error");
		return nullptr;
	}

	return std::make_unique<DBStmt>(this, stmt, _Query);
}

void DBConnecter::ConnectInfoSetting(
	const std::string& _Host,
	const std::string& _Id,
	const std::string& _Pw,
	const std::string& _Schema,
	unsigned int _Port
) 
{
	Host_ = _Host;
	Id_ = _Id;
	Pw_ = _Pw;
	Schema_ = _Schema;
	Port_ = _Port;
}


bool DBConnecter::Connect()
{
	if (nullptr != mysql_)
	{
		return true;
	}

	mysql_ = mysql_init(nullptr);

	if (nullptr == mysql_)
	{
		GameServerDebug::AssertDebugMsg("Mysql Init Error");
		return false;
	}

	mysql_options(mysql_, MYSQL_SET_CHARSET_NAME, "utf8");

	// 동시에 여러개의 SELECT정보를 받아볼수 있게 처리해줍니다.
	MYSQL* Handle = mysql_real_connect(mysql_, Host_.c_str(), Id_.c_str(), Pw_.c_str(), Schema_.c_str(), Port_, nullptr, CLIENT_MULTI_RESULTS);

	if (mysql_ != Handle)
	{
		// 실패했을때 왜 실패했는지 알려줍니다.
		GameServerDebug::AssertDebugMsg(std::string("Mysql connect Error =>") + GetLastError());
		return false;
	}

	// 만약 DB와의 연결이 끊어지면
	// 자동옵션으로 핸들 내부에서 알아서 연결을 복구한다.
	bool reconnect = true;
	// 시간 1분정도 DB가 
	mysql_options(mysql_, MYSQL_OPT_RECONNECT, &reconnect);
	// 내가 직접해도 되죠?

	 //이 헤더안의 구현내용이 알아서 쿼리 앞뒤에 mysql 서버에 보내는 프로토콜을 만들어서 
	 //날려줄거니까.
	 //함수만 열심히 찾으면 됩니다.
	 //mysql_query(Handle, "SELECT * FROM userver2.character");

	return true;
}

std::string DBConnecter::GetLastError() 
{
	return mysql_error(mysql_);
}

bool DBConnecter::Connect(const std::string& _Host, const std::string& _Id, const std::string& _Pw, const std::string& _Schema, unsigned int _Port)
{
	ConnectInfoSetting(_Host, _Id, _Pw, _Schema, _Port);
	return Connect();
}

