#include "PreCompile.h"
#include <GameServerCore\GameServerSection.h>
#include "Portal.h"
#include "ContentsSystemEnum.h"

Portal::Portal(FVector4 _Pos, FVector4 _Scale)
{
	SetPos(_Pos);
	SetScale(_Scale);
}

Portal::~Portal()
{
}


void Portal::SectionInitialize()
{
	static int Count = 0;
	++Count;

	auto Col = GetSection()->CreateCollision(ECollisionGroup::POTAL, this);

	Col->SetScale({ 320.0f, 320.0f, 320.0f });

	return;
}