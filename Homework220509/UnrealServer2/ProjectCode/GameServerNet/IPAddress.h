#pragma once

#include "Enums.h"
#include <string>

class IPAddress
{
private:
	bool m_bInvalidAddress;
	__int64 m_Address;
	AddressFamily m_AddressFamily;

public:
	static IPAddress Parse(const std::string& ipString);

public:
	AddressFamily GetAddressFamily() const;
	__int64 Address() const;

public:
	IPAddress& operator=(const IPAddress& address) noexcept;
	IPAddress& operator=(IPAddress&& address) noexcept;

public:
	IPAddress() = delete;
	IPAddress(__int64 newAddress);
	IPAddress(const IPAddress& address) noexcept;
	IPAddress(IPAddress&& address) noexcept;
	~IPAddress();
};