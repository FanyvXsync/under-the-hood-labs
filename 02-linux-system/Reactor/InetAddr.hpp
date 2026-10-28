#pragma once
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

// 网络地址和主机地址之间相互转换的类

class InetAddr
{
public:
    InetAddr(): _addr{}, _ip(), _port(0) {}

    InetAddr(struct sockaddr_in& addr)
    {
       SetAddr(addr);
    }

    InetAddr(uint16_t port): _port(port), _ip()
    {
        memset(&_addr, 0, sizeof _addr);
        _addr.sin_family = AF_INET;
        _addr.sin_addr.s_addr = INADDR_ANY;
        _addr.sin_port = htons(_port);
    }

    InetAddr(const std::string& ip, uint16_t port): 
    _port(port)
    ,_ip(ip)
    {
        memset(&_addr, 0, sizeof _addr);
        _addr.sin_family = AF_INET;
        inet_pton(AF_INET, _ip.c_str(), &_addr.sin_addr);
        _addr.sin_port = htons(_port);
    } 

    void SetAddr(struct sockaddr_in& addr)
    {
        _addr = addr;
        _port = ntohs(_addr.sin_port);
        char ipbuffer[64];
        inet_ntop(AF_INET, &addr.sin_addr, ipbuffer, sizeof(ipbuffer));
        _ip = ipbuffer;
    }


    uint16_t Port() {return _port; }
    std::string Ip() {return _ip;}

    const struct sockaddr_in& NetAddr(){return _addr;}
    const struct sockaddr* NetAddrPtr()
    {
        return reinterpret_cast<const struct sockaddr*>(&_addr);
    }

    socklen_t NetAddrLen()
    {
        return sizeof _addr;
    }

    bool operator==(const InetAddr& addr)
    {
        return addr._ip == _ip && addr._port == _port;
    }

    std::string StringAddr()
    {
        return _ip + ":" + std::to_string(_port);
    }

    ~InetAddr(){};

private:
    struct sockaddr_in _addr;
    std::string _ip;
    uint16_t _port;
};
