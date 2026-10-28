#pragma once

#include <iostream>
#include <memory>
#include <unistd.h>

#include "Socket.hpp"
#include "Log.hpp"
#include <sys/epoll.h>

using namespace SocketModule;
using namespace LogModule;

// 

class EpollServer
{

    const static int size = 64;
    const static int defaultfd = -1;

public:
    EpollServer(int port)
    :_listensocket(std::make_unique<TcpSocket>())
    ,_isruning(false)
    {
        _listensocket->BuildTcpSocketMethod(port);

        _epfd = epoll_create(222);
        if(_epfd < 0)
        {
            LOG(LogLevel::FATAL) << "epoll_create error";
            exit(EPOLL_CREATE_ERR);
        }

        struct epoll_event ev;
        ev.events = EPOLLIN;
        ev.data.fd = _listensocket->Fd();


        int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, _listensocket->Fd(), &ev);
        if(n < 0)
        {
            LOG(LogLevel::FATAL) << "add listensockfd failed";
            exit(EPOLL_CTL_ERR);
        }

    }

    void Start()
    {
        int timeout = -1;
        _isruning = true;
        
        while(_isrunning)
        {
            int n = epoll_wait(_epfd, revs, size, timeout);
            switch(n)
            {
            case 0:
                LOG(LogLevel::DEBUG) << "timeout...";
                break;
            case -1:
                LOG(LogLevel::ERROR) << "epoll error";
                break;
            default:
                Dispatcher(n);
                break;     
            } 
        }


        _isrunning = false;


    }

    void Dispatcher(int rnums)
    {
        LOG(LogLevel::DEBUG) << "event ready...";

        for(int i = 0; i < rnums; i++)
        {
            int sockfd = _revs[i].data.fd;
            uint32_t revent = _revs[i].events;

            if(revents & EPOLLIN)
            {
                if(sockfd == _listensock->Fd())
                {
                    Accepter();
                }
                else
                {
                    Recver(sockfd);
                }
            }

        }



    }

    void Accepter()
    {
        InetAddr client;

        int sockfd = _listensocket->Accept(&client);
        if(sockfd < 0)
        {
            LOG(LogLevel::INFO) << "get a new link, sockfd: "
                                << sockfd << ", client is: " << client.StringAddr();
            // 能不能直接 recv ?
        
            struct epoll_event ev;
            ev.events = EPOLLIN;
            ev.data.fd = sockfd;
            int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, sockfd, &ev);
            if (n < 0)
            {
                LOG(LogLevel::WARNING) << "add listensockfd failed";
            }
            else
            {
                LOG(LogLevel::INFO) << "epoll_ctl add sockfd success: " << sockfd;
            }
        }


    }

    void Recv(int sockfd)
    {
        char buffer[1024];
        // 我在这里读取的时候，会不会阻塞? 本次读取，不会被阻塞
        ssize_t n = recv(sockfd, buffer, sizeof(buffer) - 1, 0); // recv写的时候有bug吗？
    
         if (n > 0)
        {
            buffer[n] = 0;
            std::cout << "client say@ " << buffer << std::endl;
        }
        else if (n == 0)
        {
            LOG(LogLevel::INFO) << "clien quit...";
            // 2. 从epoll中移除fd的关心 && 关闭fd -- 细节：epoll_ctl: 只能移除合法fd -- 先移除，在关闭！！
            int m = epoll_ctl(_epfd, EPOLL_CTL_DEL, sockfd, nullptr);
            if(m > 0)
            {
                LOG(LogLevel::INFO) << "epoll_ctl remove sockfd success: " << sockfd;
            }
            close(sockfd);
        }
        else
        {
            LOG(LogLevel::ERROR) << "recv error";
            // 2. 关闭fd
            int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, sockfd, nullptr);
            if(ret > 0)
            {
                LOG(LogLevel::INFO) << "epoll_ctl remove sockfd success: " << sockfd;
            }
            close(sockfd);
        }

        
    
    }

    void Stop()
    {
        _isruning = false;
    }

    ~EpollServer() 
    {
        _listensocket->Close();
        if(_enfd > 0) 
            close(_enfd);
    }


private:
    std::unique_ptr<Socket> _listensocket;
    bool _isrunning;
    int _epfd;

    struct epoll_event _revs[size];
}