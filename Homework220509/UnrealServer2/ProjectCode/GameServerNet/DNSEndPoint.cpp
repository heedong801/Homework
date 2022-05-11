#include "PreCompile.h"
#include "DNSEndPoint.h"
#include "SocketAddress.h"
#include "IPAddress.h"

DnsEndPoint::DnsEndPoint(const std::string& host, int port) :
	DnsEndPoint(host, port, AddressFamily::Unspecified)
{
}

DnsEndPoint::DnsEndPoint(const std::string& host, int port, AddressFamily addressFamily) :
	m_Port(port),
	m_AddressFamily(addressFamily),
	m_Address(-1)
{
	if (0 == host.length())
	{
		return;
	}

	int minPort = 0x00000000;
	int maxPort = 0x0000FFFF;

	if (port < minPort ||
		port > maxPort)
	{
		return;
	}

	if (addressFamily != AddressFamily::IPv4 &&
		addressFamily != AddressFamily::Unspecified)
	{
		return;
	}

	m_Host = host;

	addrinfo hints;
	memset(&hints, 0x00, sizeof(addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	addrinfo* serviceResult;
	std::string hostString = (std::string)m_Host;
	std::stringstream stringStream;
	stringStream << m_Port;
	std::string stdPortString = stringStream.str();

	int errorCode = getaddrinfo(hostString.c_str(), stdPortString.c_str(), &hints, &serviceResult);

	while (nullptr != serviceResult)
	{
		sockaddr_in* addrin = reinterpret_cast<sockaddr_in*>(serviceResult->ai_addr);
		if (nullptr != addrin)
		{
			if (AddressFamily::Unspecified == m_AddressFamily && addrin->sin_family == AF_INET)
			{
				m_Address = addrin->sin_addr.s_addr;
				m_AddressFamily = AddressFamily::IPv4;
				break;
			}
			else if (AddressFamily::IPv4 == m_AddressFamily && addrin->sin_family == AF_INET)
			{
				m_Address = addrin->sin_addr.s_addr;
				break;
			}
		}

		serviceResult = serviceResult->ai_next;
	}
}

DnsEndPoint::~DnsEndPoint()
{
}

std::string DnsEndPoint::GetHost()
{
	return m_Host;
}

int DnsEndPoint::GetPort()
{
	return m_Port;
}

std::string DnsEndPoint::GetIp()
{
	if (0 == m_Ip.length())
	{
		constexpr int maxSize = 15;
		char addressString[maxSize + 1];
		int offset = maxSize;
		int number = (int)((m_Address >> 24) & 0xFF);
		do {
			addressString[--offset] = (char)('0' + number % 10);
			number = number / 10;
		} while (number > 0);
		addressString[--offset] = '.';
		number = (int)((m_Address >> 16) & 0xFF);
		do {
			addressString[--offset] = (char)('0' + number % 10);
			number = number / 10;
		} while (number > 0);
		addressString[--offset] = '.';
		number = (int)((m_Address >> 8) & 0xFF);
		do {
			addressString[--offset] = (char)('0' + number % 10);
			number = number / 10;
		} while (number > 0);
		addressString[--offset] = '.';
		number = (int)(m_Address & 0xFF);
		do {
			addressString[--offset] = (char)('0' + number % 10);
			number = number / 10;
		} while (number > 0);
		addressString[maxSize] = 0;
		m_Ip = addressString + offset;
	}

	return m_Ip;
}

AddressFamily DnsEndPoint::GetAddressFamily() const
{
	return m_AddressFamily;
}

SocketAddress DnsEndPoint::Serialize() const
{
	return SocketAddress(IPAddress(m_Address), m_Port);
}