#pragma once

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fcntl.h>

#define FIFO_FILE "fifo"

class NamedFifo // 创建和销毁管道文件
{
public:
    NamedFifo(const std::string &path, const std::string &name)
        : _path(path), _name(name)
    {

        _fifoname = _path + "/" + _name;
        // 创建命名管道
        umask(0);
        int n = mkfifo(_fifoname.c_str(), 0666); //  新写法

        if (n < 0)
        {
            std::cerr << "mkfifo error" << std::endl;
        }
        else
        {
            std::cout << "mkfifo success" << std::endl;
        }
    }

    ~NamedFifo()
    {
        int n = unlink(_fifoname.c_str());

        if (n == 0)
        {
            std::cout << "unlink success" << std::endl;
        }
        else
        {
            std::cout << "unlink success" << std::endl;
        }
    }

private:
    std::string _path;
    std::string _name;
    std::string _fifoname;
};

// 创建删除有了以后，还有操作， 所以，来一个操作类
//  这些文件操作，大家都一样

class FileOper
{
public:
    FileOper(const std::string &path, const std::string &name)
        : _path(path), _name(name)
    {
        _fifoname = _path + "/" + _name;
    }

    void OpenForRead()
    {
        _fd = open(_fifoname.c_str(), O_RDONLY);
        if (_fd < 0)
        {
            std::cerr << "Open Fifo Fail" << std::endl;
            exit(1);
        }

        std::cout << "Open File Success!" << std::endl;
    }

    void OpenForWrite()
    {
        _fd = open(_fifoname.c_str(), O_WRONLY);

        if (_fd < 0)
        {
            std::cerr << "Open fifo fail" << std::endl;
            exit(1);
        }

        std::cout << "Open File Success!" << std::endl;
    }

    void Read()
    {
        while (true)
        {
            char buffer[1024];
            int nums = read(_fd, buffer, sizeof(buffer) - 1);

            if (nums > 0)
            {
                buffer[nums] = 0; // 放里面
                std::cout << "#Client Say :" << buffer << std::endl;
            }
            else if (nums == 0)
            {
                std::cout << "Client end! Me too!" << std::endl;
                break;
            }
        }
    }

    void Write()
    {
        std::string messages;
        int cnt = 1;

        pid_t id = getpid();
        while (true) // 循环写，放外面， 今天就无所谓了
        {
            std::cout << "Clinet Ready To Say :";
            std::getline(std::cin, messages);

            messages += ", message number :" + std::to_string(cnt++) + " [" + std::to_string(id) + "] ";

            write(_fd, messages.c_str(), messages.size());
        }
    }

    void Close()
    {
        if (_fd > 0)
            close(_fd);
    }

    ~FileOper()
    {
        // 需要的话呢，其实可以Close放里面
    }

private:
    std::string _path;
    std::string _name;
    std::string _fifoname;
    int _fd = -1;
};


// 其实也可以合并起来， 为什么分开，因为想让只让 server 创建，看到fifo 
// 合并写的话会有更多注意事项