#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fcntl.h>

#define PATH_NAME "fifo"

int main()
{
    // 创建命名管道
    umask(0);
    int n = mkfifo(PATH_NAME, 0666);
    if(n == 0)
    {
        std::cout << "Open Fifo Success" << std::endl;
    }
    else if(n < 0)
    {
        perror("mkfifo");
        exit(1);
    }

    //对命名管道进行操作
    //这里是服务端，我们搞一个客户端输入， 服务端读
    //这也是我们之前提到的在创建出来以后，就都是文件操作了

    int fd = open(PATH_NAME, O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return 2;
    }

    std::cout << "Server Open File Success!" << std::endl;

    while(true)
    {
        char buffer[1024];
        int nums = read(fd, buffer, sizeof(buffer) - 1);
        

        if(nums > 0)
        {
            buffer[nums] = 0;
            std::cout << "#Client Say :" << buffer << std::endl; 
        }
        else if(nums == 0)
        {
            std::cout << "Client end! Me too!" << std::endl;
            break;
        }
    }


    close(fd);  // 记得关，好习惯
    //删除命名管道命名管道
    unlink(PATH_NAME);

    return 0;
}