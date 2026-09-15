#include "UdpServer.hpp"
#include "Dict.hpp"

std::string defaulthandler(const std::string& message)
{
    std::string hello = "hello";
    hello += message;
    return hello;
}

// /.udpserver port
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << port << std::endl;
        return 1
    }

    uint16_t port = std::stoi(argv[1]);
    Enable_Console_Log_Strategy();

    Dict dict;
    dict.LoadDict();
    
    std::unique_ptr<Udpserver> usvr = std::make_unique<Udpserver>(port, [&dict](const std::string& word, InetAddr cli) -> std::string{
        return dict.Translate(word, cli);
    });
    usvr->Init();
    usvr->Start();

    
    return 0;
}