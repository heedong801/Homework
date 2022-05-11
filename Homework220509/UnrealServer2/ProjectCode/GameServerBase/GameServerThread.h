#pragma once
#include <thread>
#include <tuple>
#include <typeinfo>
#include "GameServerDebug.h"
#include "GameServerNameBase.h"
#include "GameServerTime.h"

// �뵵 : 
// �з� :
// ÷�� : 
class GameServerThread  : public GameServerNameBase
{
public:
	static void ThreadNameSetting(const std::string& _Name);

	static std::string GetThreadName();

private: // Member Var
	std::thread thread_;
	static thread_local std::string name_;
	static thread_local unsigned int Order_;
	static thread_local std::map<size_t, const std::type_info*> LocalDataType_;
	static thread_local std::map<size_t, std::vector<char>> Data_;

protected:
	static thread_local GameServerTime Timer_;

public:
	inline std::thread::id ThreadId()
	{
		return thread_.get_id();
	}

	static inline void SetThreadOrder(unsigned int _Order)
	{
		Order_ = _Order;
	}

	static int GetThreadOrder() 
	{
		return Order_;
	}


	// CreateThreadLocalData<Player>();

	// GetLocalData<Monster>();

	// ����� �������� ���ΰ� ä�����ִ� �����͸� �־���� �Ѵٴ� �̴ϴ�.
	template<typename LocalDataType>
	static LocalDataType* CreateThreadLocalData(size_t _Index)
	{
		if (LocalDataType_.end() == LocalDataType_.find(_Index))
		{
			LocalDataType_[_Index] = nullptr;
		}

		if (nullptr != LocalDataType_[_Index])
		{
			GameServerDebug::AssertDebugMsg("Local Data Is Not Null");
			return nullptr;
		}

		LocalDataType_[_Index] = &typeid(LocalDataType);

		// c�� ������ �׳� ���� �ʿ��� �޸𸮸� ũ�⸸ŭ �����Ҵ��ϴ� �༮.
		// �����Լ� ���̺��� �ִ� Ŭ������ 
		Data_[_Index].resize(sizeof(LocalDataType));

		// return new (&Data_[0]) LocalDataType();

		return reinterpret_cast<LocalDataType*>(&Data_[_Index][0]);
	}

	template<typename LocalDataType>
	static LocalDataType* GetLocalData(size_t _Index)
	{
		// 0. �����帶�� �ٸ� �����͸� ��������.
		// 1. �ٸ� �ڷ������� �ڵ带 ġ�� ������� ���ƾ� // RTTI
		// DBConnecter�Ҵ��ߴµ�. NetworkManager�� �޶�� �ϴ� ���.
		// 2. �Ϲ����� Ŭ������ �Ҵ��� �� �ֵ��� �����ڸ� ����.
		// 3. �̷� �� �𸮾��̳� �ֱ� �޸�Ʈ����� 
		//    list���� vector�� ����� �޸𸮸� �Ҵ��ϴ°� ��õ�ǰ� �־��
		//    ���� ������ ������ �ϰ� �ʹ�
		//    for Ƚ���� ���̴°� �ƴ϶�. �޸𸮸� ����ȭ�ϸ�
		//    �ӷµ� �´�.

		if (LocalDataType_[_Index] != &typeid(LocalDataType))
		{
			GameServerDebug::AssertDebugMsg("Local Data Type Is Not Equal");
		}

		return (LocalDataType*)&Data_[_Index][0];
	}

public: // Default
	template <class _Fn, class... _Args, std::enable_if_t<!std::is_same_v<std::_Remove_cvref_t<_Fn>, std::thread>, int> = 0>
	explicit GameServerThread(std::string _name, _Fn&& _Fx, _Args&&... _Ax)
	{
		thread_ = std::thread(_Fx, _Ax...);
	}

	template <class _Fn, class... _Args, std::enable_if_t<!std::is_same_v<std::_Remove_cvref_t<_Fn>, std::thread>, int> = 0>
	explicit GameServerThread(_Fn&& _Fx, _Args&&... _Ax) 
		: thread_(_Fx, _Ax...)
	{
		// _Start(_STD forward<_Fn>(_Fx), _STD forward<_Args>(_Ax)...);
	}

	GameServerThread(){}

	~GameServerThread();

	GameServerThread(const GameServerThread& _Other) = delete;
	GameServerThread(GameServerThread&& _Other) noexcept;

protected:
	GameServerThread& operator=(const GameServerThread& _Other) = delete;
	GameServerThread& operator=(GameServerThread&& _Other) = delete;

public: // Member Function
	void join();

	template <class _Fn, class... _Args, std::enable_if_t<!std::is_same_v<std::_Remove_cvref_t<_Fn>, std::thread>, int> = 0>
	void Start(_Fn&& _Fx, _Args&&... _Ax)
	{
		thread_ = std::thread(_Fx, _Ax...);
	}
};

