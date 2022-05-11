#include "PreCompile.h"
#include "ContentsGlobalValue.h"

std::mutex ContentsGlobalValue::PlayableMutex;
std::unordered_set<int> ContentsGlobalValue::PlayerCharacterIndex;


bool ContentsGlobalValue::UnRegistPlayable(int _CharacterIndex) 
{
	std::lock_guard Lock(PlayableMutex);

	if (PlayerCharacterIndex.end() == PlayerCharacterIndex.find(_CharacterIndex))
	{
		return false;
	}
	PlayerCharacterIndex.erase(_CharacterIndex);
	return true;
}

bool ContentsGlobalValue::RegistPlayable(int _CharacterIndex) 
{
	std::lock_guard Lock(PlayableMutex);

	if (PlayerCharacterIndex.end() != PlayerCharacterIndex.find(_CharacterIndex))
	{
		return false;
	}
	PlayerCharacterIndex.insert(_CharacterIndex);
	return true;
}

ContentsGlobalValue::ContentsGlobalValue() 
{
}

ContentsGlobalValue::~ContentsGlobalValue() 
{
}

