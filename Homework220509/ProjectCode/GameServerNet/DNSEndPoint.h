#pragma once

#include "Enums.h"
#include "EndPoint.h"
// 홈페이지 주소를 보냅니다.

class SocketAddress;
class DnsEndPoint : public EndPoint
{
private:
	std::string m_Host;
	std::string m_Ip;
	int m_Port;
	AddressFamily m_AddressFamily;

	__int64 m_Address;

public:
	std::string GetHost();
	int GetPort();

	std::string GetIp();

public:
	AddressFamily GetAddressFamily() const override;
	SocketAddress Serialize() const override;

public:
	DnsEndPoint() = delete;
	DnsEndPoint(const std::string& host, int port);
	DnsEndPoint(const std::string& host, int port, AddressFamily addressFamily);
	~DnsEndPoint();
};