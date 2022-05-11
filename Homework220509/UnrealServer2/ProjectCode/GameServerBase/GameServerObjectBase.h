#pragma once
#include <vector>
#include <memory>
#include "GameServerDebug.h"

// 용도 : 
// 분류 :
// 첨언 : 
// public std::enable_shared_from_this<GameServerObjectBase> 필요한 애들마다 달아줄걸 하고 후회하고 있다.
class GameServerObjectBase : public std::enable_shared_from_this<GameServerObjectBase>
{
public: // Default
	GameServerObjectBase();
	virtual ~GameServerObjectBase();

	GameServerObjectBase(const GameServerObjectBase& _Other) = delete;
	GameServerObjectBase(GameServerObjectBase&& _Other) noexcept;

protected:
	GameServerObjectBase& operator=(const GameServerObjectBase& _Other) = delete;
	GameServerObjectBase& operator=(GameServerObjectBase&& _Other) = delete;

private:
	std::atomic<bool> IsDeath_;
	std::atomic<bool> IsUpdate_;
	int Frame;
	float AccTime_;

	// 내가 누군가에게 혹시 종속되었다면
	GameServerObjectBase* parent_;
	std::vector<std::shared_ptr<GameServerObjectBase>> linkObject_;

	// std::vector<std::vector<char>> linkObject_;


public:
	template<typename ConvertType>
	std::shared_ptr<ConvertType> DynamicCast() 
	{
		return std::dynamic_pointer_cast<ConvertType>(shared_from_this());
	}

	void AccTimeReset() 
	{
		AccTime_ = 0.0f;
	}

	void AccTimeUpdate(float _AccTime)
	{
		AccTime_ += _AccTime;
		++Frame;
	}

	bool IsFrame(int _Frame) 
	{
		return (Frame % _Frame) == 0;
	}

	float GetAccTime() 
	{
		return AccTime_;
	}

	void SetParent(GameServerObjectBase* _Ptr)
	{
		// 인터페이스 통일
		// 그런 경우가 굉장히 많다.
		// 자신을 관리해주는 애를 알아야할 
		parent_ = _Ptr;
	}

	void ClearLinkObject() 
	{
		linkObject_.clear();
	}

	template<typename CreateType, typename EnumData>
	std::shared_ptr<CreateType>  CreateLink(EnumData _Index)
	{
		std::shared_ptr<CreateType> NewData = std::make_shared<CreateType>();
		SetLink<EnumData>(_Index, NewData);
		return NewData;
	}

	template<typename CreateType>
	std::shared_ptr<CreateType>  CreateLink(size_t _Index)
	{
		std::shared_ptr<CreateType> NewData = std::make_shared<CreateType>();
		SetLink(_Index, NewData);
		return NewData;
	}

	template<typename EnumData>
	void SetLink(EnumData _Index, std::shared_ptr<GameServerObjectBase> _Ptr)
	{
		SetLink(static_cast<size_t>(_Index), _Ptr);
	}


	void SetLink(size_t _Index, std::shared_ptr<GameServerObjectBase> _Ptr)
	{
		// 100개 이상면 터트려.
		if (_Index >= linkObject_.size())
		{
			linkObject_.resize(_Index + 1);
		}

		if (_Index >= 128)
		{
			GameServerDebug::AssertDebugMsg("is Big Index Index Not Over 128.");
			return;
		}


		if (nullptr != linkObject_[_Index])
		{
			GameServerDebug::AssertDebugMsg("is OverLap Link Data");
			return;
		}

		linkObject_[_Index] = _Ptr;
	}


	template<typename DataType, typename EnumType>
	std::shared_ptr<DataType> GetLink(EnumType _Index)
	{
		return GetLink<DataType>(static_cast<size_t>(_Index));
	}


	template<typename DataType>
	std::shared_ptr<DataType> GetLink(size_t _Index)
	{
		if (linkObject_.size() <= _Index)
		{
			return nullptr;
		}

	 	return std::dynamic_pointer_cast<DataType>(linkObject_[_Index]);
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

	virtual void Death()
	{
		IsDeath_ = true;
	}

	void On() 
	{
		IsUpdate_ = true;
	}

	void Off()
	{
		IsUpdate_ = false;
	}

	bool IsDeath() 
	{
		return IsDeath_;
	}
	bool IsUpdate() 
	{
		return true == IsUpdate_ && false == IsDeath_;
	}

	bool IsLowLevelValid();
};