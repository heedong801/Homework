#include "PreCompile.h"
#include "IPEndPoint.h"
#include "SocketAddress.h"

IPEndPoint::IPEndPoint() :
	m_Port(0),
	m_Address(0)
{
}

IPEndPoint::IPEndPoint(const IPEndPoint& endPoint) :
	m_Port(endPoint.m_Port),
	m_Address(endPoint.m_Address)
{
}

IPEndPoint::IPEndPoint(__int64 address, int port) :
	m_Port(port),
	m_Address(address)
{
}

IPEndPoint::IPEndPoint(const IPAddress& address, int port) :
	m_Port(port),
	m_Address(address)
{
}

AddressFamily IPEndPoint::GetAddressFamily() const
{
	return m_Address.GetAddressFamily();
}

SocketAddress IPEndPoint::Serialize() const
{
	return SocketAddress(m_Address, m_Port);
}

uint64_t IPEndPoint::GetHashCode() const
{
	return (m_Address.Address() << 16) | m_Port;
}

IPEndPoint& IPEndPoint::operator=(const IPEndPoint& endPoint)
{
	m_Port = endPoint.m_Port;
	m_Address = endPoint.m_Address;
	return *this;
}

bool IPEndPoint::operator==(const IPEndPoint& endPoint) const
{
	return endPoint.m_Address.Address() == m_Address.Address() && endPoint.m_Port == m_Port;
}

bool IPEndPoint::operator!=(const IPEndPoint& endPoint) const
{
	return !(*this == endPoint);
}

IPAddress IPEndPoint::GetAddress() const
{
	return m_Address;
}

int IPEndPoint::GetPort() const
{
	return m_Port;
}