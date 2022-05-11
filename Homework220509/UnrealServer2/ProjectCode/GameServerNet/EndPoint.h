#pragma once

#include "Enums.h"
#include <stdint.h>

// class Player 
// {
//	virtual AAAA();
// }
// Player* Ptr;
// fwrite(Ptr, 0, 0);

// 주소체계를 담당하는 클래스라면 가져야할
// 선생님이 생각한 엔진에서의 기본 인터페이스
class SocketAddress;
class EndPoint
{
public:
	// ip4 ip6
	virtual AddressFamily GetAddressFamily() const = 0;

	// 이녀석은 패킷으로 보낼수있다. 
	// 직렬화라고 합니다.
	// 패킷으로 보낼수 있어야 한다.
	// 시리얼라이저 디시리얼라이저를 구현해야 하는데.
	virtual SocketAddress Serialize() const = 0;

	// hashcode 리턴하는것.
	virtual uint64_t GetHashCode() const = 0;

public:
	EndPoint() {}
	virtual ~EndPoint() = 0 {}
};