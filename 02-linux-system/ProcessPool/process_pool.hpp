#ifndef __PROCESS_POOL_HPP__
#define __PROCESS_POOL_HPP__

#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h>
#include <Task.hpp>

class Channel
{
public:
    Channel(int fd, pid_t subid)
    :_wfd(fd)
    ,_subid(subid)
    {
        _name = "channel - " + std::to_string(_wfd) + '-' + std::to_string(_subid);
    }

    int GetFd() {return _wfd};
    pid_t GetSubid() {return _subid};
    std::string GetName() {return _name};
    

    void Send(int code)
    {   
        int n = write(_wfd, &code, sizeof(code));
        (void)n; // ?
    }
    
    void Close()
    {
        close(_wfd);
        std::cout << "子进程" << _subid << "关闭" << std::endl;
    }

    void Wait()
    {
        pid_t rid = waitpid(_subid, nullptr, 0);
        (void)rid;
    }

    ~Channel()
    {}
private:
    int _wfd;  // 父进程想要管理管道，管道必须提供文件描述符
    int _subid // 还想要知道子进程是谁 BuildChannel
    std::string _name;
};   // 





class ChannelManager
{
public:
    ChannelManager():_next(0)
    {}

    void Insert(int wfd , pid_t subid)
    {
        
        _channels.emplace_back(wfd, subid);  // 小优化
        // 构建  Channel 然后 push 到 vector 里面
        // Channel c(wfd, subid);
        // _channels.push_back(std::move(c));
    }

    void PrintChannel()
    {
        for(auto& e: _channels)
        {
            std::cout << e.GetName << std::endl;
        }
    }

    Channel& Select()
    {
       auto &e = _channels[_next];
       _next ++;
       _next %= _channels.size();

       return e;
    }

    void StopSubProcess()
    {
        // 遍历 channel 然后关闭 要求  channel 提供接口 close
        for(auto& c : _channels)
        {
            c.Close();
        }

    }

    void WaitSubProcess()
    {
        for(auto& c : _channels)
        {
            c.Wait();
        }

    }

    ~ChannelManager()
    {}
private:
    std::vector<Channel> _channels;  // 对信道管理，就是对这个管理  先描述再组织
    int _next; // 下一个选谁
};

const gdefaultnum = 5 ; // 默认创建多少个进程 

class process_pool
{
public:
    ProcessPool(int num)
    :_process_num(num)
    {
        _tak.Rigister(TaskPrintHello);
        _tak.Rigister(TaskPrintWorld);
        _tak.Rigister(TaskPrintLover);
    }


    ~ProcessPool()
    {}

    void Work(int rfd)
    {
        while(true)
        {
            // std::cout << "我是一个子进程我的 rfd 是：" << rfd << std::endl;
            // sleep(1);

            //  子进程等待父进程发 天然的
            int code  = 0;
            ssize_t n = read(rfd, &code, sizeof (code));  // 已整形读 读到 code 里面，四个字节
            // if(n != sizeof(code))  // 没有读到四个字节 读失败了
            if(n > 0)
            {
                if(n != sizeof(code)) continue; // 继续读 直到读规范

                std::cout << "子进程["<< gitpid() << "]收到一个任务码" << code << std::endl; // 想知道子进程是谁？

                _tal.Execute(code);
            }
            else if(n == 0)
            {
                std::cout << "子进程退出" << std:: endl;
                break; // 结束work
            }
            else
            {
                std::cout << "子进程退出" << std:: endl;
                break; // 结束work
            }
        
        
        }
    }

    // 首先要提供创建进程池的接口
    bool Create()
    {
        // 首先要照着那个图的结构维护起来
        for(int i = 0; i < _process_num; i++)
        {
            // 1. 创建管道
            int pipefd[2] = {0};

            int p = pipe(pipefd);
            if(p < 0) return false;
           
            // 2.创建子进程
            pid_t subid = fork();
            if(subid < 0) return false; 
            else if(subid == 0)
            {
                // 3. 关闭不需要的文件描述符
                close(pipefd[1]);
                Work(pipefd[0]); // 子进程要读 子进程工作的时候把读端给给子进程


                close(pipefd[0]); // 结束之后把读端关掉
                exit(0); // 不管子进程做什么，结束之后都要直接退掉   先把结构搭建一下
            }
            else
            {
                close(pipefd[0]);
                // 写端 pipefd[1]  向一个个的 channel
                // 知道了 写端 知道了子进程是谁 subid
                // 之前创建管道的都是临时空间 这里父进程就要创建管理这样一个信道
                // wfd  subid
                _cm.Insert(pipefd[1], subid); // 所以 要支持这样的接口

            }
            
            return true;
            
        }
    }


    void Debug()  // 测试接口
    {
        _cm.PrintChannel()
    }


    // 先改子进程work 让他做起来
    // 选择子进程写入  轮询
    
    // void PushTask(int taskcode)
    // {

    //     auto& c = _cm.Select();
    //     std::cout << "选择了一个子进程" << c.name << std::endl;
    //     // 2. 发送任务 写入  由信道提供接口
    //     c.Send(taskcode);    //  这里第二次测试必须有顺序
    // }

    void Run()
    {
        int taskcode = _tak.Code();


        auto& c = _cm.Select(); 
        // 2. 发送任务 写入  由信道提供接口
        c.Send(taskcode);        //  这里第二次测试必须有顺序
    }


    void Stop()
    {
        // 父进程关  wfd

        // 清理僵尸   channemanager  管理着 wfd pid 提供接口
    }



private:
    ChannelManager _cm;  // main 里面 ChannelManager 的 build 都不用暴露了
    int _process_num;  // 在创建的时候需要告诉我要创建几个进程
    TaskManager _tak;
};


#endif