#pragma once
#include <GameServerNet\DBQuery.h>

class UserRow : public std::enable_shared_from_this<UserRow>
{
public:
	int			Index;
	std::string Id;
	std::string Pw;

public:
	UserRow() 
	{
	}

	UserRow(
		int _Index,
		std::string _Id,
		std::string _Pw
	)
		:Index(_Index),
		Id(_Id),
		Pw(_Pw)
	{
	}
};

// 설명 :
// 실제적으로 아무런 의미없는 녀석입니다.
class UserTable 
{
public:
	// constrcuter destructer
	UserTable();
	~UserTable();

	// delete Function
	UserTable(const UserTable& _Other) = delete;
	UserTable(UserTable&& _Other) noexcept = delete;
	UserTable& operator=(const UserTable& _Other) = delete;
	UserTable& operator=(UserTable&& _Other) noexcept = delete;



protected:
	static std::string TableName;
	std::string Query;
	// SELECT Idx, ID, PW FROM userver2.user WHERE ID = "A";


private:
	std::shared_ptr<UserRow> GetUser(const std::string& Id);
};


class UserTable_SelectIDToUserInfo : public DBQuery, UserTable
{
public:
	std::string ID;
	std::shared_ptr<UserRow> RowData;

public:
	UserTable_SelectIDToUserInfo(std::string _ID);
	bool DoQuery() override;
};


class UserTable_AllUserInfo : public DBQuery, UserTable
{
public:
	std::vector<std::shared_ptr<UserRow>> RowDatas;

public:
	UserTable_AllUserInfo();

	bool DoQuery() override;
};

class UserTable_InsertUserInfo : public DBQuery, UserTable
{
	std::string ID;
	std::string PW;

public:
	UserTable_InsertUserInfo(std::string _ID, std::string _PW);

	bool DoQuery() override;
};