#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <memory>
#include <functional>
#include <cerrno>
#include "Common.hpp"
#include "Connection.hpp"
#include "Log.hpp"
#include "InetAddr.hpp"
#include "Reactor.hpp"


using namespace LogModule;
#define SIZE 1024

class Channel : public Connection
{
public:
    Channel(int sockfd, InetAddr& clientaddr)
    :_sockfd(sockfd)
    ,_clientaddr(clientaddr)
    {
        SetNonBlock(_sockfd);
    }

    void Recver() override
    {
        char buffer[SIZE];
        buffer[0] = 0; // 清空字符串
    
        while(true)
        {
           
            ssize_t n = recv(_sockfd, buffer, sizeof (buffer) - 1, 0);
            
            if(n > 0)
            {
                buffer[n] = 0;
                _inbuffer += buffer;
            }
            else if (n == 0)
            {   
                Excepter();
                return;
            }
            else
            {
                if(errno == EAGAIN || errno == EWOULDBLOCK)
                {
                    break;
                }
                else if(errno == EINTR)
                {
                    continue;
                }
                else
                {
                    Excepter();
                    return;
                }

            }
            

        }

        LOG(LogLevel::DEBUG) << "Channel: Inbuffer:\n"
                             << _inbuffer;

        //

        if(!_inbuffer.empty())
        {
            _outbuffer += _handler(_inbuffer);  // protocal 有关
        }

        if(!_outbuffer.empty())
        {
            Sender();  // 最佳实践
        }
    }

    void Sender() override
    {
        while(true)
        {
            ssize_t n = send(_sockfd, _outbuffer.c_str(), _outbuffer.size(), 0);
        
            if(n > 0)
            {
                _outbuffer.erase(0, n);
                if(_outbuffer.empty())
                    break;
            }
            else if(n == 0)
            {
                break;
            }
            else
            {
                if(errno == EAGAIN || errno == EWOULDBLOCK)
                {
                    break;
                }
                else if(errno == EINTR)
                {
                    continue;
                }
                else
                {
                    Excepter();
                    return;
                }
            }
        
        }

        if(!_outbuffer.empty())
        {
            GetOwner()->EnableReadWriter(_sockfd, true, true);
        }
        else
        {
            GetOwner()->EnableReadWriter(_sockfd, true, false);
        }

    }

    int GetSockFd() override
    {
        return _sockfd;
    }

    std::string& Inbuffer()
    {
        return _inbuffer;
    }

    void AppendOutBuffer(const std::string &out)
    {
        _outbuffer += out;
    }

    void Excepter() override
    {
        GetOwner()->DelConnection(_sockfd);
    }

    ~Channel() {}

private:    
    std::string _inbuffer;
    std::string _outbuffer;
    int _sockfd;
    InetAddr _clientaddr;
};
