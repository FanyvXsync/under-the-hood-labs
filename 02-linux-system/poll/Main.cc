#include "PollServer.hpp"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage" << argv[0] << "port" << std::endl;
        exit(USAGE_ERR);
    }

    Enable_Console_Log_Strategy();

    std::unique_ptr<PollServer> svr = std::make_unique<Pollserver>(port);
    svr->Start();

    return 0;
}
