#pragma once
#include <iostream>
#include <pthread.h>
#include "Mutex.hpp"

using namespace MutexModule;

namespace CondModule
{
    class Cond
    {
    public:
        Cond()
        {
            pthread_cond_init(&_cond, nullptr);
        }

        void Wait(Mutex& mutex)
        {
            pthread_cond_wait(&_cond, mutex.Get());
        }

        void Signal()
        {
            pthread_cond_signal(&_cond);
        }

        void Broadcast()
        {
            pthread_cond_broadcast(&_cond);
        }

        ~Cond()
        {
            pthread_cond_destroy(&_cond);
        }

    private:
        pthread_cond_t _cond;
    };
}