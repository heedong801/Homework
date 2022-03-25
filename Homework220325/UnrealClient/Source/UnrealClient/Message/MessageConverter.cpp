#include "MessageConverter.h"
#include <memory>
MessageConverter::MessageConverter(const std::vector<unsigned char>&_buffer)
	: buffer_(_buffer)
{
	GameServerSerializer Sr = GameServerSerializer(buffer_);

	MessageId Type;
	memcpy_s(&Type, sizeof(MessageId), &buffer_[0], sizeof(MessageId));
	switch (Type)
	{
	case MessageId::Login:
		Message_ = std::make_shared<LoginMessage>();
		break;
	case MessageId::Join:
		Message_ = std::make_shared<JoinMessage>();
		break;
	case MessageId::LoginResult:
		Message_ = std::make_shared<LoginResultMessage>();
		break;
	case MessageId::JoinResult:
		Message_ = std::make_shared<JoinResultMessage>();
		break;
	case MessageId::ServerDestroy:
		Message_ = std::make_shared<ServerDestroyMessage>();
		break;
	case MessageId::ObjectDestroy:
		Message_ = std::make_shared<ObjectDestroyMessage>();
		break;
	case MessageId::MonsterUpdate:
		Message_ = std::make_shared<MonsterUpdateMessage>();
		break;
	case MessageId::Chat:
		Message_ = std::make_shared<ChatMessage>();
		break;
	default:
		return;
	}
	Message_->DeSerialize(Sr);
}