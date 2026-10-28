#include <iostream>
#include <string>
#include "Reactor.hpp"
#include "Listenner.hpp"
#include "Channel.hpp"
#include "Log.hpp"
#include "Common.hpp"
#include "Protocol.hpp"
#include "NetCal.hpp"


static void Usage(std::string proc)
{
    std::cerr<< "Usage :" << proc << "port" << std::endl;
}



int main(int argc, char* argv[])
{   
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }

    Enable_Console_Log_Strategy();

    uint16_t port = std::stoi(argv[1]);

    //
    std::shared_ptr<Cal> cal = std::make_shared<Cal>();

    //
    std::shared_ptr<Protocol> protocol = std::make_shared<Protocol> (
        [&cal] (Request& req) -> Response
        {
            return cal->Execute(req);
        }
    );

    std::shared_ptr<Connection> conn = std::make_shared<Listener>(port);
    conn->RegisterHandler([&protocol] (std::string &inbuffer) -> std::string{
        LOG(LogLevel::DEBUG) << "进入匿名函数" ;
        std::string response_str;

        while(true)
        {
            std::string package;
            if(!protocol->Decode(inbuffer, &package))
                break;
            //
            response_str += protocol->Execute(package);
        
        }
        return response_str;
    });

    std::unique_ptr<Reactor> R = std::make_unique<Reactor>();
    R->AddConnection(conn);
    R->Loop();


    return 0;
}
