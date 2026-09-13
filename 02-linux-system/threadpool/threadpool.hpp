#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Log.hpp"
#include "Thread.hpp"
#include "Cond.hpp"
#include <Mutex.hpp>

namespace ThreadPoolModule
{
    using namespace ThreadModlue;
    using namespace LogModule;
    using namespace MutexModule;
    using namespace CondModule;

    static const int gnum = 5;

    template<class T>
    class ThreadPool
    {
    private:
        ThreadPool(int num = gnum)
        :_num(num)
        ,_isrunning(false)
        ,_sleepernum(0)
        {
            for(int i = 0; i < num; i++)
            {
                _thread.emplace_back(
                    [this]()
                    {
                        HandlerTask();
                    };
                )
            }
        }

        void WakeUpAllThread()
        {
            LockGuard lockerguard(_mutex);
            if(_sleepernum)
                _cond.Broadcast();
            
            LOG(LogLevel::INFO) << "唤醒所有的休眠线程";
        }

        void WakeUpOne()
        {
            
            _cond.Signal();

            LOG(LogLevel::INFO) << "唤醒一个休眠线程";
        }
        

    public:
        void Start()
        {
            if(_isrunning) return;

            _isrunning = true;
            for(auto &thread: _thread)
            {
                thread.Start();
                LOG(LogLevel::INFO) << "start new thread success: " << thread.Name();
            }
        }

        ThreadPool(const ThreadPool<T>& ) = delete;  // 单例
        ThreadPool<T> &operator=(const Thread<T>&) = delete;


        void HandlerTask()
        {
            char name[128];
            pthread_getname_np(pthread_self(), name, sizeof name);

            while(true)
            {
                T t;
                {
                    LockGuard lockguard(_mutex);
                    // 
                    while(_tackq.empty() && _isrunning)
                    {
                        _sleepernum++;
                        _cond.Wait(_mutex);
                        _sleepernum--;
                    }

                    if(!_isrunning && _taskq.empty())
                    {
                        LOG(LogLevel::INFO) << name << " 退出了， 线程池退出 且任务列表为空"；
                        break;
                    }

                    t = _taskq.front();
                    _taskq.pop();


                }
                t();


            }


        }

        bool Enqueue(const T& in)
        {
            if(_isrunning)
            {
                LockGuard lockerguard(_mutex);
                _taskq.push(in);
                if(_threads.size() == _sleepernum)
                    WakeUpOne();
                return true;
            }

            return false;
        }

        void Stop()
        {
            if(!_isrunning) return;

            _isrunning = false;
            WakeUpAllThread();
        }

        void Join()
        {
            for(auto &thread: _thread)
            {
                thread.Join();
            }
        }

        static ThreadPool<T> *GetInstance()
        {
            if(inc == nullptr)
            {
                LockGuard lockguard(_lock);

                LOG(LogLevel::DEBUG) << "获取单例 ....";
                if(inc == nullptr)
                {
                    LOG(Loglevel::DEBUG) << "首次使用单例, 创建之 ..."
                    inc = new ThreadPool<T>();
                    inc->Start();
                }
            }

            return inc;
        }


    private:
        std::vector<thread> _threads;
        int _num;
        std::queue<T> _taskq;
        Cond _cond;
        Mutex _mutex;

        bool _isrunning;
        bool _sleepernum;

        //单例
        static ThreadPool<T> *inc;
        static Mutex _lock;

    };

    template<typename T>
    ThreadPool<T> *ThreadPool<T>::inc = nullptr;


    template<typename T>
    Mutex ThreadPool<T>:: _lock;
}