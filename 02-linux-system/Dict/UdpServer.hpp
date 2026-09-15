#pragma once

#include <iostream>
#include "Log.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <functional>
#include "InetAddr.hpp"

using namespace LogModule;

const int defultfd = -1;

using fun_t = std::function<std::string(const std::string&), InetAddr>;


class Udpserver
{
public:
    Udpserver(uint16_t port, func_t func)
    :_port(port)
    ,_sockid(defultfd)
    ,_func(func)
    ,_isrunning(false)
    {

    }

    void Init()
    {
        //1. 创建套接字
        _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if(_sockfd < 0)
        {
            LOG(LogLevel::FATAL) << "socket error";
            exit(1);
        }
        LOG(LogLevel::INFO) << "socket success, socketfd :" << _sockfd;

        //1.绑定 socket 信息 ， ip 和 端口 ip 特殊，后续改
        struct sockaddr_in local;
        bzero(&local, sizeof(local));

        local.sin_family = AF_INET;
        local.sin_port = htos(_port); 
        local.sin_addr.s_addr = INADDR_ANY;
        // 转网络序列
        lcoal.sin_addr.s_addr = inet_addr(ip.c_str());

        int n = bind(_sockfd, (struct sockaddr *)&local, sizeof(local));
        (void)n;
        if(n < 0)
        {
            LOG(LogLevel::FATAL) << "bind error" << endl;
            exit(2);
        }
        LOG(LogLevel::INFO) << "bind success, sockfd " << _sockfd;
        

        
        

    }


    void Start()
        {
            _isruning = true;
            while(_isruning)
            {
                char buffer[1024];
                struct sockaddr_in peer;
                socklen_t len = sizeof(peer);

                ssize_t recvfrom(_socket, buffer, sizeof(buffer) - 1, 0 ,(struct sockaddr *)& peer, &len);
                if(s > 0)
                {
                    // 收消息
                    // 转本地序列
                    InetAddr client(peer);

                    buffer[s] = 0;

                    std::string result = _func(buffer, client);
                    //发消息
                    // std::string echo_string = "server echo@: ";
                    // echo_string += buffer;
                    sento(_socket, result.c_str(), result.size(), 0, (struct sockaddr*)& peer, len);

                }
            }
        }


private:
    int _sockid;
    uint16_t _port;
    
    // std::string _ip;  不需要了
    bool _isrunning;
    func_t _func;
}

