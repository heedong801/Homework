#include "PreCompile.h"
#include "GameServerCollision.h"
#include "GameServerSection.h"

std::function<bool(GameServerCollision*, GameServerCollision*)> GameServerCollision::CollisionCheckFunction[static_cast<int>(CollisionCheckType::MAX)][static_cast<int>(CollisionCheckType::MAX)];

class GameCollisionFunctionInitialzer
{
public:
	GameCollisionFunctionInitialzer() 
	{
		GameServerCollision::CollisionCheckFunction[static_cast<int>(CollisionCheckType::SPHERE)][static_cast<int>(CollisionCheckType::SPHERE)] = GameServerCollision::SphereToSphere;
	}
};

// �ܸӸ� ���������� ���������� ������ ������ �ʱ�ȭ �ɶ� �� �浹�� �Լ��鵵 �ڵ� �ʱ�ȭ
GameCollisionFunctionInitialzer Inst = GameCollisionFunctionInitialzer();

bool GameServerCollision::SphereToSphere(GameServerCollision* _Left, GameServerCollision* _Right)
{
	return _Left->CollisionData_.Sphere.Intersects(_Right->CollisionData_.Sphere);
}






/// <summary>
/// /////////////////////////
/// </summary>

GameServerCollision::GameServerCollision()
	: OwnerSection(nullptr)
	, OwnerActor(nullptr)
	, Index_(0)
{
}

GameServerCollision::~GameServerCollision()
{
}

bool GameServerCollision::CollisionCheck(CollisionCheckType _ThisType, int _Order, CollisionCheckType _OtherType)
{
	if (nullptr == OwnerSection)
	{
		GameServerDebug::LogErrorAssert("���ǿ� ������ ���� �ݸ����Դϴ�.");
		return false;
	}

	if (nullptr == OwnerActor)
	{
		GameServerDebug::LogErrorAssert("���Ϳ� ������ ���� �ݸ����Դϴ�.");
		return false;
	}

	if (false == IsUpdate())
	{
		return false;
	}


	std::list<GameServerCollision*> ColList = OwnerSection->CollisionList[_Order];

	if (0 == ColList.size())
	{
		return false;
	}

	CollisionDataUpdate();

	int ThisType = static_cast<int>(_ThisType);
	int OtherType = static_cast<int>(_OtherType);

	for (GameServerCollision* _Other : ColList)
	{
		_Other->CollisionDataUpdate();

		if (true == CollisionCheckFunction[ThisType][OtherType](this,_Other))
		{
			return true;
		}
	}
	
	return false;
}

bool GameServerCollision::CollisionCheckResult(CollisionCheckType _ThisType, int _Order
	, CollisionCheckType _OtherType, std::vector<GameServerCollision*>& _HitResults)
{
	if (nullptr == OwnerSection)
	{
		GameServerDebug::LogErrorAssert("���ǿ� ������ ���� �ݸ����Դϴ�.");
		return false;
	}

	if (nullptr == OwnerActor)
	{
		GameServerDebug::LogErrorAssert("���Ϳ� ������ ���� �ݸ����Դϴ�.");
		return false;
	}

	if (false == IsUpdate())
	{
		return false;
	}

	std::list<GameServerCollision*> ColList = OwnerSection->CollisionList[_Order];

	if (0 == ColList.size())
	{
		return false;
	}

	CollisionDataUpdate();

	int ThisType = static_cast<int>(_ThisType);
	int OtherType = static_cast<int>(_OtherType);

	for (GameServerCollision* _Other : ColList)
	{
		_Other->CollisionDataUpdate();

		if (true == CollisionCheckFunction[ThisType][OtherType](this, _Other))
		{
			_HitResults.push_back(_Other);
		}
	}

	if (0 == _HitResults.size())
	{
		return false;
	}

	return true;
}


void GameServerCollision::CollisionDataUpdate()
{
	CollisionData_.OBB.Center = (OwnerActor->GetPos() + Pivot).ConvertXMFloat3();
	CollisionData_.OBB.Extents = Scale.HalfVector3D().ConvertXMFloat3();
	CollisionData_.OBB.Orientation = Rot.ConvertXMFloat4();
}

void GameServerCollision::Death()
{
	GameServerObjectBase::Death();

	if (nullptr == OwnerSection)
	{
		GameServerDebug::AssertDebugMsg("OwnerSection Is Null!!!!!!!!");
	}

	// ���� �Ҿ��Ѱ� ���ĸ�

	OwnerSection->CollisionList[Index_].remove(this);
	delete this;
}