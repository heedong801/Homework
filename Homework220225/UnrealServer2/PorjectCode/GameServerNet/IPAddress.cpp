#include "PreCompile.h"
#include "IPAddress.h"

IPAddress::IPAddress(__int64 newAddress) :
	m_Address(0),
	m_AddressFamily(AddressFamily::IPv4)
{
	m_bInvalidAddress = newAddress < 0 || newAddress>0x00000000FFFFFFFF;
	m_Address = newAddress;
}

IPAddress::IPAddress(const IPAddress& address) noexcept :
	m_Address(address.m_Address),
	m_AddressFamily(address.m_AddressFamily),
	m_bInvalidAddress(address.m_bInvalidAddress)
{
}

IPAddress::IPAddress(IPAddress&& address) noexcept :
	m_Address(address.m_Address),
	m_AddressFamily(address.m_AddressFamily),
	m_bInvalidAddress(address.m_bInvalidAddress)
{
	address.m_Address = 0;
	address.m_AddressFamily = AddressFamily::Unknown;
	address.m_bInvalidAddress = false;
}

IPAddress::~IPAddress()
{
}

AddressFamily IPAddress::GetAddressFamily() const
{
	return m_AddressFamily;
}

__int64 IPAddress::Address() const
{
	return m_Address;
}

IPAddress& IPAddress::operator=(const IPAddress& address) noexcept
{
	m_Address = address.m_Address;
	m_AddressFamily = address.m_AddressFamily;
	m_bInvalidAddress = address.m_bInvalidAddress;
	return *this;
}

IPAddress& IPAddress::operator=(IPAddress&& address) noexcept
{
	m_Address = address.m_Address;
	address.m_Address = 0;
	m_AddressFamily = address.m_AddressFamily;
	address.m_AddressFamily = AddressFamily::Unknown;
	m_bInvalidAddress = address.m_bInvalidAddress;
	address.m_bInvalidAddress = false;
	return *this;
}

IPAddress IPAddress::Parse(const std::string& ipString)
{
	if (true == ipString.empty())
	{
		return IPAddress(0);
	}

	SOCKADDR_IN sin;
	sin.sin_family = AF_INET;
	if (ipString == "localhost")
	{
		inet_pton(AF_INET, "127.0.0.1", &sin.sin_addr.s_addr);
	}
	else if (ipString == "0.0.0.0")
	{
		// 0.0.0.0으로 열어야 public 서버 역할을 할수 있다.
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		inet_pton(AF_INET, ((std::string)ipString).c_str(), &sin.sin_addr.s_addr);
	}

	return IPAddress(sin.sin_addr.s_addr);
}