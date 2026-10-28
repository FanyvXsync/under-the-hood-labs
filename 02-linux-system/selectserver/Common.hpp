#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <neinet/in.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

enum ExitCode
{
    OK = 0;
    USAGE_ERR;
    SOCKET_ERR;
    BIND_ERR;
    LISTEM_ERR;
    CONNECT_ERR;
    FORK_ERR;
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