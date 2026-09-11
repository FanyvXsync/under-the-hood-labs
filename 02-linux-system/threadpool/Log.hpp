#ifndef __LOG_HPP__
#define __LOG_HPP__

#include <iostream>
#include <cstdio>
#include <string>
#include <filesystem> //C++ 17
#include <sstream>
#include <fstream>
#include <memory>
#include <ctime>
#include <unistd.h>
#include "Mutex.hpp"

namespace LogModule
{
    using namespace MutexModule;
    const std::string gsep = "\r\n";

    //策略模式 多态 
    //刷新策略: 1. 显示器打印 2. 向指定文件写入

    class LogStrategy
    {
    public:
        ~LogStrategy() = default;
        virtual void SyncLog(const std::string& message) = 0; 
    };

   class ConsloeLogStrategy : public LogStrategy
   {
    public:
        void SyncLog(const std::string& message) override
        {
            LockGuard lockguard(_mutex);
            std::cout << message << gsep;
        }

    private:
        Mutex _mutex;
   };

   const std::string defaultpath = "./log";
   const std::string defaultfile = "my.log";
   
   class FilleLogStrategy : public LogStrategy
   {
    public:
        FilleLogStrategy(const std::string& path = defaultpath, const std::string& file = defaultfile)
        :_path(path)
        ,_file(file)
        {
            LockGuard lockguard(_mutex);
            if(std::filesystem::exists(_path)) return;
            try
            {
                std::filesystem::create_directories(_path);
            }
            catch(const std::filesystem::filesystem_error& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }

        void SyncLog(const std::string& message) override
        {
            LockGuard lockguard(_mutex);

            std::string filename = _path + (_path.back() == '/' ? "" : "/") + _file;
            std::ofstream out(filename, std::ios::app);
            if(!out.is_open())
            {
                return;
            }
            out << message << gsep;
            out.close();  // 文件流操作
            
        }



    private:
        std::string _path;
        std::string _file;
        Mutex _mutex;
   };

   // 形成一条完整的日志 根据上面的策略 , 选择不同的刷新方式

   enum class LogLevel
   {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
   };

   std::string Level2Str(LogLevel level)
   {
        switch (level)
        {
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
        }
   }

    std::string GetTimeSTamp()
    {
        time_t curr = time(nullptr);
        struct tm curr_tm;

        loccaltime_r(&curr,  &curr_tm);

        char timebuffer[128];
        snprintf(timebuffer, sizeof(timebuffer), "%4d-%02d-%02d %02d:%02d:%02d",
        curr_tm.tm_year + 1900,
        curr_tm.tm_mon + 1,
        curr_tm.tm_mday,
        curr_tm.tm_hour,
        curr_tm.tm_min,
        curr_tm.tm_sec
        );

        return timebuffer;
    }

   class Logger
   {
    public:
        Logger()
        {
            EnableConsoleLogStrategy();
        }

        void EnableFileLogStrategy()
        {
            _fflush_strategy = std::make_unique<FilleLogStrategy>();
        }
        void EnableConsoleLogStrategy()
        {
            _fflush_strategy = std::make_unique<ConsloeLogStrategy>();
        }
        
        class LogMessage
        {
        public:
            LogMessage(LogLevel& level, std::string& src_name, int line_number, Logger &logger)
            :_level(level)
            ,_pid(getpid())
            ,_src_name(src_name)
            ,_line_number(line_number)
            ,_logger(logger)
            ,_curr_time(GetTimeSTamp())
            {
                std::stringstream ss;
                ss  << "[" << _curr_time << "] "
                    << "[" << Level2Str(_level) << "] "
                    << "[" << _pid << "] "
                    << "[" << _src_name << "] "
                    << "[" << _line_number << "] "
                    << "- ";
                _loginfo = ss.str();

            }

            template <class T>
            LogMessage &operator<<(const T& info)
            {
                std::stringstream ss;
                ss << info;
                _loginfo += ss.str();
                
                return *this;
            }
            
            ~LogMessage()
            {
                if(_logger._fflush_strategy)
                {
                    _logger._fflush_strategy->SyncLog(_loginfo);
                }
            }
        
            
        private:
            std::string _curr_time;
            LogLevel _level;
            pid_t _pid;
            std::string _src_name;
            int _line_number;
            std::string _loginfo; //  完整信息 
            Logger &_logger;
        };

        //这里故意写成返回临时对象
        LogMessage operator() (LogLevel level, std::string name, int line)
        {
            return LogMessage(level, name, line, *this);
        }


    private:
        std::unique_ptr<LogStrategy> _fflush_strategy;
   };


}




#endif