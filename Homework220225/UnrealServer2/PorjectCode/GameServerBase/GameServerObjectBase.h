#pragma once
#include <vector>
#include <memory>

// �뵵 : 
// �з� :
// ÷�� : 
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
	// ���� ���������� Ȥ�� ���ӵǾ��ٸ�
	GameServerObjectBase* parent_;
	std::vector<std::shared_ptr<GameServerObjectBase>> linkObject_;

public:
	void SetParent(GameServerObjectBase* _Ptr)
	{
		// �������̽� ����
		// �׷� ��찡 ������ ����.
		// �ڽ��� �������ִ� �ָ� �˾ƾ��� 
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