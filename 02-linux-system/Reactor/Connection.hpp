#pragma once

#include <iostream>
#include "Log.hpp"
#include "Common.hpp"
#include <unistd.h>
#include <functional>
#include <fcntl.h>

using namespace LogModule;

using handler_t = std::function<std::string(std::string &)>;


class Reactor;


class Connection
{
public:
    Connection() 
    : _events(0)
    , _owner(nullptr)
    {}

    void SetEvent(const uint32_t event)
    {
        _events = event;
    }

    uint32_t GetEvent()
    {
        return _events;
    }

    void SetOwner(Reactor *owner)
    {
        _owner = owner;
    }

    Reactor *GetOwner()
    {
        return _owner;
    }

    virtual void Recver() = 0;
    virtual void Sender() = 0;
    virtual void Excepter() = 0;
    virtual int GetSockFd() = 0;

    void SetNonBlock(int sockfd)
    {
        int fl = fcntl(sockfd, F_GETFL);
        if(fl < 0) return;

        fcntl(sockfd, F_SETFL, fl | O_NONBLOCK);
    }


    void RegisterHandler(handler_t handler)
    {
        _handler = handler;
    }
  

    ~Connection()
    {
    }

private:
    uint32_t _events;

    Reactor *_owner;
public:

    handler_t _handler;
};
