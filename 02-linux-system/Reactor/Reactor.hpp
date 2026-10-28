#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include "Epoller.hpp"
#include "Log.hpp"
#include "Connection.hpp"

using namespace LogModule;

class Reactor
{
    const static int revs_num = 128;



private:

    bool IsConnectionExistsHelper(int sockfd)
    {
        return _connection.count(sockfd);
    }

    int LoopOnce(int timeout)
    {
        return _epoller_ptr->WaitEvents(_revs, _revs_num, timeout);
    }

    bool IsConnectionEmpty()
    {
        return _connection.empty();
    }

    bool IsConnectionExists(int sockfd)
    {
        return IsConnectionExistsHelper(sockfd);
    }

    bool IsConnectionExists(const std::shared_ptr<Connection> &conn)
    {
        return IsConnectionExistsHelper(conn->GetSockFd());
    }

    void Dispatcher(int n)
    {
        for(int i = 0; i < n; i++)
        {
            int sockfd = _revs[i].data.fd;
            uint32_t revents = _revs[i].events;

            if(revents & EPOLLERR)
                revents |= (EPOLLIN | EPOLLOUT);
            if(revents & EPOLLHUB)
                revents |= (EPOLLIN | EPOLLOUT);


            if(revents & EPOLLIN)
            {
                if(IsConnectionExists(sockfd))
                    _connection[sockfd]->Recver();
            }
            if(revents & EPOLLOUT)
            {
                 if(IsConnectionExists(sockfd))
                    _connection[sockfd]->Sender();
            }
        
        }
    }



public:
    Reactor() 
    :_epoller_ptr(std::make_unique<Epoller>())
    ,_isrunning (false)
    {

    }

    void Loop()
    {
      
        if(IsConnectionEmpty()) return;

        _isrunning = true;
        int timeout = -1;

        while(_isrunning)
        {
            PrintConnection(); //debug

            int n = LoopOnce(timeout);
            Dispatcher(n);
        }

        _isrunning = false;
    }

    void AddConnection(std::shared_ptr<Connection>& conn)
    {
        if(IsConnectionExists(conn)) 
        {
            
            LOG(LogLevel::WARNING) << "conn is exists: " << conn->GetSockFd();
            return;
        }

        uint32_t events = conn->GetEvent();
        int sockfd = conn->GetSockFd();

        _epoller_ptr->AddEvent(sockfd, events);

        conn->SetOwner(this); // 设置回调
        
        _connection[sockfd] = conn;
    }
   

    void EnableReadWriter(int sockfd, bool enableread, bool enablewrite)
    {
        if(!IsConnectionExists(sockfd))
        {
            LOG(LogLevel::WARNING) << "EnableReadWrite, conn is exists: " << sockfd;
            return;
        }

        uint32_t new_event = (EPOLLET | (enableread ? EPOLLIN : 0) | (enablewrite ? EPOLLOUT:0));
        _connection[sockfd]->SetEvent(new_event);

        // 2. 写透到内核，调整sockfd对特定事件的关心
        _epoller_ptr->ModEvent(sockfd, new_event);
    }

    void DelConnection(int sockfd)
    {
        _epoller_ptr->DelEvent(sockfd);
        _connection.erase(sockfd);
        
        close(sockfd);
        LOG(LogLevel::INFO) << "client quit:" << sockfd;
    }

    void Stop()
    {
        _isrunning = false;
    }


    void PrintConnection()
    {
        std::cout << "当前Reactor正在进行管理的fd List:";
        for(auto &conn : _connection)
        {
            std::cout << conn.second->GetSockFd() << " ";
        }
        std::cout << "\r\n";
    }


    
    ~Reactor() {}
private:

    std::unique_ptr<Epoller> _epoller_ptr;
    std::unordered_map<int, std::shared_ptr<Connection>> _connection;

    struct epoll_event _revs[revs_num];
    bool _isrunning;
};
