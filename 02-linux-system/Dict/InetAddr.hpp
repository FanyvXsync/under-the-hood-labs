#pragma once
#include <iostream>
#include <string>
#include <stys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// 网络地址和主机地址之间相互转换的类

class InetAddr
{
public:
    InetAddr(struct sockaddr_in& addr):_addr(addr)
    {
        _ip = inet_ntoa(addr.sin_addr);
        _port = ntos(_add.sin_port);
    }

    uint16_t Port() {return _port; }
    std::string Ip() {return _ip;}

private:
    struct sockaddr_in _addr;
    std::string _ip;
    uint16_t _port;
}