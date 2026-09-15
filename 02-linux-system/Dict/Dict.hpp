#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "Log.hpp"

const std::string defaultdict = "./dictionary.txt";
const std::string sep = ": ";

using namespace LogModule;

class Dict
{
public:
    Dict(const std::string& path = defaultdict)
    :_dict_path(path)
    {}

    bool LoadDict()
    {
        std::ifstream in(_dict_path);
        if(!in.is_open())
        {
            LOG(LogLevel::FATAL) << "打开字典: " << _dict_path << "失败";
            return false;
        }

        std::string line;
        while(getline(in, line)) // 一直读
        {
            auto pos = line.find(sep);
            if(pos == std::string::npos)
            {
                LOG(LogLevel::WARNING) << "解析失败" ;
                continue;  //有一个解析失败了后面的还要继续
            }

            std::string english = line.substr(0, pos);
            std::string chinese = line.substr(pos + sep.size());

            if(english.empty() || chinese.empty())
            {
                LOG(LogLevel::WARNING) << "没有有效内容" << line;
                continue;
            }

            _dict.insert(std::make_pair(english, chinese));
            LOG(LogLevel::DEBUG) << "加载: " << line;

        }

        in.close();
        return true;

    }

    std::string Translate(const std::string& word, InetAddr& client)
    {
        auto iter = _dict.find(word);
        if(iter == _dict.end())
        {
            LOG(LogLevel::DEBUG) << "进入到翻译模块[" << client.Ip() << ":" << client.Port() << word << "-> None" ;
            return "NONE";
        } 

        LOG(LogLevel::DEBUG) << "进入到翻译模块[" << client.Ip() << ":" << client.Port() << word << "->" << iter->second;
        return iter->second;
    }

    ~Dict()
    {}


private:
    std::string _dict_path;
    std::unordered_map<std::string, std::string> _dict;
}