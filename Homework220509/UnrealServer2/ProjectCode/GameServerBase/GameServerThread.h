#pragma once
#include <thread>
#include <tuple>
#include <typeinfo>
#include "GameServerDebug.h"
#include "GameServerNameBase.h"
#include "GameServerTime.h"

// 용도 : 
// 분류 :
// 첨언 : 
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

	// 절대로 값만으로 내부가 채워져있는 데이터를 넣어줘야 한다는 겁니다.
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

		// c의 말록은 그냥 내가 필요한 메모리를 크기만큼 동적할당하는 녀석.
		// 가상함수 테이블이 있는 클래스를 
		Data_[_Index].resize(sizeof(LocalDataType));

		// return new (&Data_[0]) LocalDataType();

		return reinterpret_cast<LocalDataType*>(&Data_[_Index][0]);
	}

	template<typename LocalDataType>
	static LocalDataType* GetLocalData(size_t _Index)
	{
		// 0. 쓰레드마다 다른 데이터를 가져야해.
		// 1. 다른 자료형으로 코드를 치는 사람들을 막아야 // RTTI
		// DBConnecter할당했는데. NetworkManager를 달라고 하는 사람.
		// 2. 일반적인 클래스도 할당할 수 있도록 생성자를 지연.
		// 3. 이론 왜 언리얼이나 최근 메모리트랜드는 
		//    list보다 vector에 가까운 메모리를 할당하는게 추천되고 있어요
		//    내가 뭔가를 빠르게 하고 싶다
		//    for 횟수를 줄이는게 아니라. 메모리를 최적화하면
		//    속력도 는다.

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

