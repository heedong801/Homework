#pragma once
#include <vector>
#include <memory>

// 용도 : 
// 분류 :
// 첨언 : 
class GameServerObjectBase : public std::enable_shared_from_this<GameServerObjectBase>
{
private: // Member Var

public: // Default
	GameServerObjectBase();
	virtual ~GameServerObjectBase();

	GameServerObjectBase(const GameServerObjectBase& _Other) = delete;
	GameServerObjectBase(GameServerObjectBase&& _Other) noexcept;

protected:
	GameServerObjectBase& operator=(const GameServerObjectBase& _Other) = delete;
	GameServerObjectBase& operator=(GameServerObjectBase&& _Other) = delete;

private:
	// 내가 누군가에게 혹시 종속되었다면
	GameServerObjectBase* parent_;
	std::vector<std::shared_ptr<GameServerObjectBase>> linkObject_;

public:
	void SetParent(GameServerObjectBase* _Ptr)
	{
		// 인터페이스 통일
		// 그런 경우가 굉장히 많다.
		// 자신을 관리해주는 애를 알아야할 
		parent_ = _Ptr;
	}

	void SetLink(std::shared_ptr<GameServerObjectBase> _Ptr)
	{
		linkObject_.push_back(_Ptr);
	}

public:
	template<typename ParentType>
	ParentType* GetParent()
	{
		return dynamic_cast<ParentType*>(parent_);
	}

	template<typename LinkObjectType>
	LinkObjectType* GetChild(int _Index = 0)
	{
		return dynamic_cast<LinkObjectType*>(linkObject_[_Index]);
	}

public: // Member Function
	bool IsLowLevelValid();
};