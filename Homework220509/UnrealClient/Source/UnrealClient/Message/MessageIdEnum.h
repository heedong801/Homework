#pragma once

enum class MessageId 
{
	Login,
	CreateCharacter,
	SelectCharacter,
	ClientToReady,
	UDPConnectResult,
	LevelMoveReply,
	RankRequest,
	LoginResult,
	CharacterCreateResult,
	CharacterSelectResult,
	LevelMove,
	UDPReadyOK,
	SectionInsertResult,
	ServerDestroy,
	PlayerDestroy,
	ObjectDestroy,
	CharacterList,
	PlayersUpdate,
	MonsterUpdate,
	UserRankWindowData,
	Chat,
	PlayerUpdate,
	MAX
};