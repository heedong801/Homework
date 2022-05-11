#pragma once

#include "Enums.h"

class IPEndPoint;
class IPAddress;
class SocketAddress
{
private:
	char* m_pBuffer;
	size_t m_stBufferMaxSize;
	size_t m_stBufferLength;

private:
	void Initialize();
	void Destroy();

public:
	const char* GetBuffer() const;
	size_t GetBufferLength() const;

public:
	AddressFamily GetAddressFamily();

	int GetPort();
	IPAddress GetIPAddress();
	IPEndPoint GetIPEndPoint();

public:
	SocketAddress& operator=(const SocketAddress& sock);
	SocketAddress& operator=(SocketAddress&& sock) noexcept;

public:
	SocketAddress();
	SocketAddress(const SocketAddress& sock);
	SocketAddress(SocketAddress&& sock) noexcept;
	SocketAddress(AddressFamily addressFamily);
	SocketAddress(const IPAddress& address);
	SocketAddress(const IPAddress& address, int port);
	~SocketAddress();
};