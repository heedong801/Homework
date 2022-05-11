#include "PreCompile.h"
#include "SocketAddress.h"
#include "IPAddress.h"
#include "IPEndPoint.h"

SocketAddress::SocketAddress() :
	m_pBuffer(nullptr),
	m_stBufferMaxSize(0),
	m_stBufferLength(0)
{}

SocketAddress::SocketAddress(const SocketAddress& sock) :
	m_pBuffer(nullptr),
	m_stBufferMaxSize(0),
	m_stBufferLength(0)
{
	if (nullptr != sock.m_pBuffer)
	{
		Initialize();

		m_stBufferLength = sock.m_stBufferLength;

		memcpy_s(m_pBuffer, m_stBufferMaxSize, sock.m_pBuffer, sock.m_stBufferLength);
	}
}

SocketAddress::SocketAddress(SocketAddress&& sock) noexcept :
	m_pBuffer(nullptr),
	m_stBufferMaxSize(0),
	m_stBufferLength(0)
{
	m_pBuffer = sock.m_pBuffer;
	sock.m_pBuffer = nullptr;
	m_stBufferMaxSize = sock.m_stBufferMaxSize;
	sock.m_stBufferMaxSize = 0;
	m_stBufferLength = sock.m_stBufferLength;
	sock.m_stBufferLength = 0;
}

SocketAddress::SocketAddress(AddressFamily addressFamily)
{
	Initialize();

	m_stBufferLength = sizeof(SOCKADDR_IN6);
	if (AddressFamily::IPv4 == addressFamily)
	{
		m_stBufferLength = sizeof(SOCKADDR_IN);
	}

	int family = static_cast<int>(addressFamily);

	m_pBuffer[0] = static_cast<char>(family);
	m_pBuffer[1] = static_cast<char>((family >> 8));
}

SocketAddress::SocketAddress(const IPAddress& address) :
	SocketAddress(address.GetAddressFamily())
{
	m_pBuffer[2] = 0;
	m_pBuffer[3] = 0;

	__int64 i64Address = address.Address();

	m_pBuffer[4] = static_cast<char>(i64Address);
	m_pBuffer[5] = static_cast<char>((i64Address >> 8));
	m_pBuffer[6] = static_cast<char>((i64Address >> 16));
	m_pBuffer[7] = static_cast<char>((i64Address >> 24));
}

SocketAddress::SocketAddress(const IPAddress& address, int port) :
	SocketAddress(address)
{
	m_pBuffer[2] = static_cast<char>(port >> 8);
	m_pBuffer[3] = static_cast<char>(port);
}

SocketAddress::~SocketAddress()
{
	Destroy();
}

SocketAddress& SocketAddress::operator=(const SocketAddress& sock)
{
	if (nullptr != sock.m_pBuffer)
	{
		Initialize();

		m_stBufferLength = sock.m_stBufferLength;

		memcpy_s(m_pBuffer, m_stBufferMaxSize, sock.m_pBuffer, sock.m_stBufferLength);
	}

	return *this;
}

SocketAddress& SocketAddress::operator=(SocketAddress&& sock) noexcept
{
	Destroy();

	m_pBuffer = sock.m_pBuffer;
	sock.m_pBuffer = nullptr;
	m_stBufferMaxSize = sock.m_stBufferMaxSize;
	sock.m_stBufferMaxSize = 0;
	m_stBufferLength = sock.m_stBufferLength;
	sock.m_stBufferLength = 0;

	return *this;
}

void SocketAddress::Initialize()
{
	if (nullptr == m_pBuffer)
	{
		m_stBufferMaxSize = sizeof(SOCKADDR_IN) < sizeof(SOCKADDR_IN6) ? sizeof(SOCKADDR_IN6) : sizeof(SOCKADDR_IN);
		m_pBuffer = new char[m_stBufferMaxSize];
	}

	m_stBufferLength = 0;
	memset(m_pBuffer, 0x00, m_stBufferMaxSize);
}

void SocketAddress::Destroy()
{
	if (nullptr != m_pBuffer)
	{
		delete[] m_pBuffer;
		m_pBuffer = nullptr;
		m_stBufferMaxSize = 0;
		m_stBufferLength = 0;
	}
}

const char* SocketAddress::GetBuffer() const
{
	return m_pBuffer;
}

size_t SocketAddress::GetBufferLength() const
{
	return m_stBufferLength;
}

AddressFamily SocketAddress::GetAddressFamily()
{
	int family = m_pBuffer[0] | (m_pBuffer[1] << 8);
	return static_cast<AddressFamily>(family);
}

int SocketAddress::GetPort()
{
	int port = m_pBuffer[2] << 8 & 0xFF00 | m_pBuffer[3] & 0xFF;
	return port;
}

IPAddress SocketAddress::GetIPAddress()
{
	__int64 address = static_cast<__int64>(
		(m_pBuffer[4] & 0x000000FF) |
		(m_pBuffer[5] << 8 & 0x0000FF00) |
		(m_pBuffer[6] << 16 & 0x00FF0000) |
		(m_pBuffer[7] << 24 & 0xFF000000)
		) & 0x00000000FFFFFFFF;
	return IPAddress(address);
}

IPEndPoint SocketAddress::GetIPEndPoint()
{
	IPAddress address = GetIPAddress();
	int port = GetPort();

	return IPEndPoint(address, port);
}