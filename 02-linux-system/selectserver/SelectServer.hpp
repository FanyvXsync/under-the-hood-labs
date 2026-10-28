#pragma once


#include "Common.hpp"
#include "InetAddr.hpp"
#include "Log.hpp"
#include "Socket.hpp"
#include <memory>
#include <unistd.h>
#include <sys/select.h>


using namespace SocketModule;
using namespace LogModule;



class SelectServer
{
const static size = sizeof(fd_set) * 8;
const static defaultfd = -1;

public:
    SelectServer(int port)
    :_listensocket(std::make_unique<TcpSocket()>)
    ,_isrunning(false)
    {
        _listensocket->BuildTcpSocketMethod(port);
        for(int i = 0; i < size; i++)
            _fd_array[i] = -1;

        _fd_array[0] = _listensocket->Fd();
    }

    void Start()
    {
        _isrunning = true;

        while(_isrunning)
        {
            fd_set rfds;
            FD_ZERO(&rfds);

            int maxfd = defaultfd;
            for(int i = 0; i < size; i++)
            {
                if(_fd_array[i] == defaultfd)
                    continue;

                FD_SET(_fd_array[i], &rfds);
                maxfd = max(maxfd, _fd_array[i]);
            }

            PrintFd();

            int n = select(maxfd + 1, &rfds, nullptr, nullptr,);
            switch(n)
            {
            case -1:
                LOG(LogLevel::ERROR) << "select error";
                break;
            case 0:
                LOG(LogLevel::INFO) << "time out..." ;
                break;
            default: 
                LOG(LogLevel::DEBUG) << "有事件就绪了...." ;
                Dispatcher(rfds);
                break;
            }

        }

        _isrunning = false;

    }

    void PrintFd()
    {
        for(int i = 0; i < size; i++)
        {
            if(_fd_array[i] != defaultfd)
                cout << _fd_array[i] << " ";
        }
    }


    void Dispatcher(fd_set &rfds)
    {
        for(int i = 0; i < size; i++)
        {
            if(_fd_array[i] == defaultfd)
                continue;

            if(FD_ISSET(_fd_array[i]), &rfds)
            {
                if(_fd_array[i] == _listensocket->Fd())
                {
                    Accepter();
                }
                else
                {
                    Recver(_fd_array[i], i);
                }

            }
        }
    }


    void Accepter()
    {
        InetAddr client;
        int sockfd = _listensocket->Accept(&client);

        if(sockfd > 0)
        {
            LOG(LogLevel::INFO) << "get a new link, sockfd"
                                << sockfd << "clinet is" << clinet.StingAddr();
            
            int pos = 0;
            for(; pos < size; pos++)
            {
                if(_fd_arary[pos] == defaultfd) break;
            }

            if(pos == size) 
            {
                LOG(LogLevel::WARNING) << "select server full";
                close(sockfd);
            }
            else
            {
                _fd_array[pos] = sockfd;
            }


        }

    }


    void Recver(int fd, int pos)
    {
        char buffer[1024];
        ssize_t n = recv(fd, buffer, sizeof(buffer) - 1, 0);


        if(n > 0)
        {
            buffer[n] = 0;
            LOG(LogLevel::INFO) << "client say@" << buffer << std::endl;
        }
        else if(n == 0)
        {
            LOG(LogLevel::INFO) << "client quit...";
            _fd_array[pos] = defaultfd;
            close(fd);
        }
        else
        (
            LOG(LogLevel::ERROR) << "recv error";
            _fd_array[pos] = defaultfd;
            
            close(fd);
        )
        


    }


private:
    std::unique_ptr<Socket> _listensocket;
    bool _isruning;

    int _fd_array[size];
}
