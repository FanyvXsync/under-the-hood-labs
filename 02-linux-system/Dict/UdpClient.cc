#include <iostream>
#include <string>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

// ./udpclient
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " server_ip server_port" << std::endl;
        return 1;
    }

    std::string server_ip = argv[1];
    uint16_t server_port = argv[2];


    int n = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0)
    {
        std::cerr << "socket error" << std::endl;
        return 2;
    }

    // 不要 显式 bind

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htos(server_port);
    server.sin_addr.s_addr = inet_addr(server_ip);

    while(true)
    {
        std::string input;
        std::cout << "Plase Enter# ";
        std::getline(std::cin, input);

        int n = sendto(_socket, input.c_str(), input.size(), 0, (struct sockaddr*)&server, sizeof(server));
        (void) n;
        
        char buffer[1024];
        struct sockaddr_in peer;
        socklen_t len = sizof(peer);
        int m = resvfrom(_socket, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&peer, &len);

        if(m > 0)
        {
            buffer[m] = 0;
            std::cout << buffer << std::endl;
        }
    }


    return 0;
}
