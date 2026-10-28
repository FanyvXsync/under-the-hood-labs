#pragma once

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdlib>
#include <unistd.h>
#include "Log.hpp"
#include "InetAddr.hpp"
#include <string>
#include "Common.hpp"


#define ACCEPT_DONE -1
#define ACCEPT_CONTINUE -2
#define ACCEPT_ERR -3

namespace SocketModule
{
    using namespace LogModule;
    const static int gbacklog = 16;

    //模板方法模式
    // 基类大部分方法都是纯虚方法
    class Socket
    {
    public:
        virtual ~Socket(){}
        virtual void SocketOrDie() = 0;
        virtual void BindOrDie(uint16_t port) = 0;
        virtual void ListenOrDie(int backlog) = 0;
        virtual int Accept(InetAddr* client) = 0;
        virtual void Close() = 0;
        virtual int Fd() const = 0;
        virtual int Recv(std::string *out) = 0;
        virtual int Send(const std::string& message) = 0;
        virtual int Connect(const std::string &server_ip, uint16_t port) = 0;

    public:
        void BuildTcpSocketMethod(uint16_t port, int backlog = gbacklog)
        {
            SocketOrDie();
            BindOrDie(port);
            ListenOrDie(backlog);
        }
    };

    const static int defaultfd = -1;

    class TcpSocket : public Socket
    {
    public:
        TcpSocket(int fd): _sockfd(fd){}
        TcpSocket(): _sockfd(defaultfd){}

        ~TcpSocket(){ Close(); }

        void SocketOrDie() override
        {
            _sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
            if(_sockfd < 0)
            {
                LOG(LogLevel::FATAL) << "socket error";
                exit(SOCKET_ERR); 
            }
            LOG(LogLevel::INFO) << "socket success";
        }

        void BindOrDie(uint16_t port) override
        {
            InetAddr localaddr(port);
            int n = ::bind(_sockfd, localaddr.NetAddrPtr(), localaddr.NetAddrLen());
            if(n < 0)
            {
                LOG(LogLevel::FATAL) << "bind error";
                exit(BIND_ERR);
            }
            LOG(LogLevel::INFO) << "bind success";    
            
        }

        void ListenOrDie(int backlog) override
        {
            int n = ::listen(_sockfd, backlog);
            if(n < 0)
            {
                LOG(LogLevel::FATAL) << "listen error";
                exit(LISTEN_ERR);
            }
            LOG(LogLevel::INFO) << "listen success";
        }

        int Accept(InetAddr* client) override
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);

            int fd = ::accept(_sockfd, reinterpret_cast<struct sockaddr*>(&peer), &len);
            if(fd < 0)
            {
                LOG(LogLevel::WARNING) << "accept warning ...";
                return ACCEPT_ERR; // TODO
            }
            client->SetAddr(peer);
            return fd;

        }

        int Recv(std::string *out) override
        {
            char buffer[1024];
            ssize_t n = ::recv(_sockfd, buffer, sizeof(buffer) - 1, 0);
            if(n > 0)
            {
                buffer[n] = 0;
                *out += buffer; // 故意
            }

            return n;
        }


        int Send(const std::string& message) override
        {
            return send(_sockfd, message.c_str(), message.size(), 0);
        }

        


        int Connect(const std::string& server_ip, uint16_t port) override
        {
            InetAddr serveraddr(server_ip, port);
            return ::connect(_sockfd, serveraddr.NetAddrPtr(), serveraddr.NetAddrLen());
        }

        int Fd() const override { return _sockfd; }

        void Close() override
        {
            if(_sockfd >= 0)
            {
                ::close(_sockfd);
                _sockfd = defaultfd;
            }
        }        


    private:
        int _sockfd; // 可以是任意 fd
    };


}
