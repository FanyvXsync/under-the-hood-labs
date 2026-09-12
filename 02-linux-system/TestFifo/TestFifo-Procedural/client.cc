#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fcntl.h>

#define PATH_NAME "fifo"
// server 服务端已经打开文件，接下来客户端只需要进行文件操作就可以了

int main()
{
    int fd = open(PATH_NAME, O_WRONLY);

   
    if (fd < 0)
    {
        perror("open error");
        exit(1);
    }

    std::string messages;
    int cnt = 1;

    pid_t id = getpid();
    while (true)
    {
        std::cout << "Clinet Ready To Say :";
        std::getline(std::cin, messages);
        
        messages += ", message number :" + std::to_string(cnt++) + " [" + std::to_string(id) + "] ";
        
        write(fd, messages.c_str(), messages.size());

    }

    return 0;
}