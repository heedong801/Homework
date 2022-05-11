#pragma once
#include <vector>
#include <memory>
#include "GameServerMessage.h"
#include "Messages.h"


class MessageConverter
{
public:
	std::shared_ptr<GameServerMessage> Message_;

public:
	inline std::shared_ptr<GameServerMessage> GetServerMessage()
	{
		return Message_;
	}

	inline uint32_t GetMessageId()
	{
		return Message_->GetId();
	}

	inline uint32_t GetMessageIdUint()
	{
		return static_cast<uint32_t>(GetMessageId());
	}

	inline bool IsVailed()
	{
		return nullptr != Message_;
	}


public:
	MessageConverter(const std::vector<unsigned char>& _buffer);
	~MessageConverter() {}
public:

private:
	const std::vector<unsigned char>& buffer_;

};
