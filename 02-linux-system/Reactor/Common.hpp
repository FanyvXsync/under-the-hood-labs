#pragma once

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

enum ExitCode
{
    OK = 0,
    USAGE_ERR,
    SOCKET_ERR,
    BIND_ERR,
    LISTEN_ERR,
    CONNECT_ERR,
    FORK_ERR,
    EPOLL_CREATE_ERR,
    EPOLL_CTL_ERR
};

class NoCopy
{
public:
    NoCopy(){}
    ~NoCopy(){}

    NoCopy(const NoCopy&) = delete;
    const NoCopy& operator= (const NoCopy&) = delete;

};

#define CONV(addr) ((struct sockaddr*)&addr)
