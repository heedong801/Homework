#pragma once

class TCPSession;
class TCPListener;

using PtrSTCPListener = std::shared_ptr<TCPListener>;
using PtrWTCPListener = std::weak_ptr<TCPListener>;

using PtrSTCPSession = std::shared_ptr<TCPSession>;
using PtrWTCPSession = std::weak_ptr<TCPSession>;
