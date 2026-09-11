#ifndef _THREAD_H_
#define _THREAD_H_

#include <iostream>
#include <string>
#include <pthread.h>
#include <cstdio>
#include <cstring>
#include <functional>
#include "Log.hpp"

namespace ThreadModlue
{
    using namespace LogModule;
    static unsigned number = 1;

    class Thread
    {

        using func_t = std::function<void()>;
    private:
        
        void EnableDetach()
        {
            _isdetach = true;
        }
        
        void EnableRunning()
        {
            _isrunning = true;
        }
    
    
        static void* Routine(void* args)  // 把 this 指针去掉
        {
            Thread* self = static_cast<Thread*>(args);
            self -> EnableRunning();

            if(self->_isdetach) 
                self->Detach();
            pthread_setname_np(self->_tid, self->_name.c_str());
            self->_func(); // 回调处理

            return nullptr;
        }



    public:
        Thread(func_t func)
        :_tid(0)
        ,_isdetach(false)
        ,_isrunning(false)
        ,res(nullptr)
        ,_func(func)
        {
            _name = "thread - " + std::to_string(number++);
        }

        bool Start()
        {
            if(_isrunning) return false;
            int n = pthread_create(&_tid, nullptr, Routine, this);

            if(n != 0) return false;
            else return true;

        }

        void Detach()
        {
            if(_isdetach) return;

            if(_isrunning)
                pthread_detach(_tid);
            EnableDetach();
        }

        std::string Name()
        {
            return _name;
        }

        bool Stop()
        {
            if(_isrunning)
            {
                int n = pthread_cancel(_tid);
                if(n != 0) return false;
                else 
                {
                    _isrunning = false;
                    return true;
                }
            }
        }

        void Join()
        {
            if(_isdetach) return;

            int n = pthread_join(_tid, &res);
            if(n != 0)
            {
                LOG(LogLevel::DEBUG) << "Join线程失败";
            }
            else
            {
                LOG(loglevel::DEBUG) << "等待线程成功";
            }
        }

        ~Thread()
        {
        }


    private:
        pthread_t _tid;
        std::string _name;
        bool _isdetach;
        bool _isrunning;
        void *res;
        func_t _func;
    };
    


}

#endif