#pragma once

#include "Enums.h"
#include <stdint.h>

// class Player 
// {
//	virtual AAAA();
// }
// Player* Ptr;
// fwrite(Ptr, 0, 0);

// �ּ�ü�踦 ����ϴ� Ŭ������� ��������
// �������� ������ ���������� �⺻ �������̽�
class SocketAddress;
class EndPoint
{
public:
	// ip4 ip6
	virtual AddressFamily GetAddressFamily() const = 0;

	// �̳༮�� ��Ŷ���� �������ִ�. 
	// ����ȭ��� �մϴ�.
	// ��Ŷ���� ������ �־�� �Ѵ�.
	// �ø�������� ��ø���������� �����ؾ� �ϴµ�.
	virtual SocketAddress Serialize() const = 0;

	// hashcode �����ϴ°�.
	virtual uint64_t GetHashCode() const = 0;

public:
	EndPoint() {}
	virtual ~EndPoint() = 0 {}
};