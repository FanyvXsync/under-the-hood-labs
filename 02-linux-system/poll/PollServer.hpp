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


class PollServer
{
    const static int size = 4096;
    const static int defaultfd = -1;


public:
    PollServer(int port)
    :_listensocket(std::make_unique<TcpSocket>())
    ,_isrunning(false)
    {
        _listensocket->BuildTcpSocketMethod(port);

        for(int i = 0; i < size, i++)
        {
            _fds[i].fd = defaultfd;
            _fds[i].events = 0;
            _fds[i].revents = 0;
            
        }

        _fds[0].fd = _listensocket->Fd();
        _fds[0].events = POLLIN;

    }

    void Start()
    {
        int timeout = -1;
        _isrunning = true;

        while(_isrunning)
        {
            PrintFd();

            int n = poll(_fds, size, timeout);
            switch(n)
            {
            case -1:
                LOG(LogLevel::ERROR) << "poll error";
                break;
            case 0:
                LOG(LogLevel::INFO) << "poll time out...";
                break;
            default:
                LOG(LogLevel::DEBUG) << "有事件就绪了..., n : " << n;
                Dispatcher(); // 处理就绪的事件啊！
                break;
            }


        }

        _isrunning = false;
    }


    void Dispatcher()
    {
        for(int i = 1; i < size; i++)
        {
            if(_fds[i].fd = defaultfd)
                continue;

            if(_fd[i].revents & POLLIN)
            {
                if(_fd[i].fd == _listensocket->Fd())
                {
                    Accepter();
                }
            }
            else
            {
                Recver(i);
            }

        }
    }

    // 链接管理器
    void Accepter()
    {
        InetAddr client;
        int sockfd = _listensock->Accept(&client); // accept会不会阻塞?
        if (sockfd >= 0)
        {
            // 获取新链接到来成功, 然后呢？？能不能直接
            // read/recv()， sockfd是否读就绪，我们不清楚
            // 只有谁最清楚，未来sockfd上是否有事件就绪？select！
            // 将新的sockfd，托管给select！
            // 如何托管? 将新的fd放入辅助数组！
            LOG(LogLevel::INFO) << "get a new link, sockfd: "
                                << sockfd << ", client is: " << client.StringAddr();
            int pos = 0;
            for (; pos < size; pos++)
            {
                if (_fds[pos].fd == defaultfd)
                    break;
            }
            if (pos == size)
            {
                LOG(LogLevel::WARNING) << "poll server full";
                close(sockfd);
            }
            else
            {
                _fds[pos].fd = sockfd;
                _fds[pos].events = POLLIN;
                _fds[pos].revents = 0;
            }
        }
    }

    void Recver(int pos)
    {
         char buffer[1024];
        // 我在这里读取的时候，会不会阻塞?
        ssize_t n = recv(_fds[pos].fd, buffer, sizeof(buffer) - 1, 0); // recv写的时候有bug吗？
        if (n > 0)
        {
            buffer[n] = 0;
            std::cout << "client say@ " << buffer << std::endl;
        }
        else if(n == 0)
        {
            LOG(LogLevel::INFO) << "clien quit...";
            // 2. 关闭fd
            close(_fds[pos].fd);
            // 1. 不要让select在关系这个fd了
            _fds[pos].fd = defaultfd;
            _fds[pos].events = 0;
            _fds[pos].revents = 0;
        }
        else
        {
            LOG(LogLevel::ERROR) << "recv error";
            // 2. 关闭fd
            close(_fds[pos].fd);
            // 1. 不要让select在关系这个fd了
            _fds[pos].fd = defaultfd;
            _fds[pos].events = 0;
            _fds[pos].revents = 0;
        }



    }

    void PrintFd()
    {
        std::cout << "_fds[]: ";
        for (int i = 0; i < size; i++)
        {
            if (_fds[i].fd == defaultfd)
                continue;
            std::cout << _fds[i].fd << " ";
        }
        std::cout << "\r\n";
    }


    void Stop()
    {
        _isrunning = false;
    }
    ~PollServer()
    {
    }

private:
    std::unique_ptr<Socket> _listensocket;
    bool _isrunning;

    struct pollfd _fds[size];
    //

}