#pragma once
#include <GameServerMessage/Dispatcher.h>


extern Dispatcher<TCPSession> Dis;
void DispatcherRegistration();