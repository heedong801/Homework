#pragma once

#include "Enums.h"
#include "EndPoint.h"
#include "IPAddress.h"

class SocketAddress;
class IPEndPoint : public EndPoint
{
private:
	IPAddress m_Address;
	int m_Port;

public:
	IPAddress GetAddress() const;
	int GetPort() const;

public:
	AddressFamily GetAddressFamily() const override;
	SocketAddress Serialize() const override;
	uint64_t GetHashCode() const override;

public:
	IPEndPoint& operator=(const IPEndPoint& endPoint);

	bool operator==(const IPEndPoint& endPoint) const;

	bool operator!=(const IPEndPoint& endPoint) const;

public:
	IPEndPoint();
	IPEndPoint(const IPEndPoint& endPoint);
	IPEndPoint(__int64 address, int port);
	IPEndPoint(const IPAddress& address, int port);
	~IPEndPoint() {}
};