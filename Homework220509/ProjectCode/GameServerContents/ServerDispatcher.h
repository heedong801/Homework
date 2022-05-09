#pragma once
#include <GameServerNet\TCPSession.h>
#include <GameServerNet\UDPSession.h>
#include <GameServerMessage\Dispatcher.h>

extern Dispatcher<TCPSession> Dis;
extern Dispatcher<UDPSession> UDPDis;
void DispatcherRegistration();