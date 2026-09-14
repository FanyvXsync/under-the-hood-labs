#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/shm.h>

const int defaultid = -1;
const int gsize = 4096;
const std::string pathname = ".";
const int projid = 0x88;

#define ERR_EXIT(m)     \
    do                  \
    {                   \
        prror(m);       \
        exit(ERR_EXIT); \
    }while(0)

class Shm
{
piblic:
    Shm() 
    :_shmid(defaultid)
    ,_size(gsize)
    {}

    //创建的要是一个全新的，所以组合选项
    bool Creat()
    {
        key_t key = ftok(pathname, projid);
        if(key < 0)
        {
            ERR_EXIT("ftok");
        }

        printf("key : 0x%x \n", key);
        _shmid = shmget(key, _size, IPC_CREAT | IPC_EXCL);

        if(shmid < 0)
        {
            ERR_EXIT("shm");
        }

        printf("shmid : %d", _shmid);
        return 0;
    }

    ~Shm()
    {}
private:
    int _shmid;  //共享内存的标识
    int _size;
}

// 第一版， 第一次成功创建，第二次失败了， 因为shmget的选项问题