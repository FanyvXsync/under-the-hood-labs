#pragma once
#include <iostream>
#include <string>
#include "Socket.hpp"
#include <memory>
#include <jsoncpp/json/json.h>
#include <functional>
#include <utility>


using namespace SocketModule;

class Request;
class Response;
using func_t = std::function<Response(Request&)>;


class Request
{
public:
    Request(){}
    Request(int x, int y, char oper)
    :_x(x), _y(y), _oper(oper)
    {

    }

    std::string Serialize()
    {
        Json::Value root;
        root["x"] = _x;
        root["y"] = _y;
        root["oper"] = std::string(1, _oper);

        Json::FastWriter writer;
        std::string s = writer.write(root);
        return s;
    }

    bool Deserialize(std::string& in)
    {
        Json::Value root;
        Json::Reader reader;

        bool ok = reader.parse(in, root);
        if(ok)
        {
            _x = root["x"].asInt();
            _y = root["y"].asInt();
            std::string oper = root["oper"].asString();
            if(oper.size() != 1) return false;
            _oper = oper[0];
        }
        
        return ok;
    }

    int X(){ return _x; }
    int Y(){ return _y; }
    char Oper(){return _oper;}

private:
    int _x;
    int _y;
    char _oper;
};


class Response
{
public:
    Response(int result, int code) : _result(result), _code(code) {}

    
    std::string Serialize()
    {
        Json::Value root;
        root["result"] = _result;
        root["code"] = _code;

        Json::FastWriter writer;
        std::string s = writer.write(root);
        return s;
    }
    bool Deserialize(std::string &in)
    {
        Json::Value root;
        Json::Reader reader;

        bool ok = reader.parse(in, root);
        if(ok)
        {
            _result = root["result"].asInt();
            _code = root["code"].asInt();
        }
        
        return ok;
    }

    void SetResult(int res) {_result = res;}
    void SetCode(int code) {_code = code;}


    ~Response() {}


private:
    int _result;
    int _code;
};



const std::string sep = "\r\n";


class Protocol
{
public:
    Protocol(){}
    explicit Protocol(func_t func): _func(std::move(func)) {}

    std::string Encode(const std::string& jsonstr)
    {
        std::string len = std::to_string(jsonstr.size());
        return len + sep + jsonstr + sep; 
    }

    
    // 50\r\n{"x": 10, "y" : 20, "oper" : '+'}\r\n
    // 5
    // 50
    // 50\r
    // 50\r\n
    // 50\r\n{"x": 10, "
    // 50\r\n{"x": 10, "y" : 20, "oper" : '+'}\r\n
    // 50\r\n{"x": 10, "y" : 20, "oper" : '+'}\r\n50\r\n{"x": 10, "y" : 20, "ope
    //.....
    // packge故意是&
    // 1. 判断报文完整性
    // 2. 如果包含至少一个完整请求，提取他， 并从移除它，方便处理下一个


    bool Decode(std::string& buffer, std::string* package)
    {
        ssize_t pos = buffer.find(sep);
        if(pos == std::string::npos)
            return false;

        std::string package_len_str = buffer.substr(0, pos);
        int package_len_int = std::stoi(package_len_str);

        int target_len = package_len_str.size() + package_len_int + 2 *sep.size();
        if(buffer.size() < target_len)
            return false;

        *package = buffer.substr(pos + sep.size(), package_len_int);
        buffer.erase(0, target_len);
        return true;

    }




    std::string Execute(std::string& package)
    {
        Request req;
        if(!req.Deserialize(package)) return {};
        Response resp = _func(req);
        return Encode(resp.Serialize());
    }

    void GetRequest(std::shared_ptr<Socket>& sock, InetAddr& client)
    {
        std::string buffer_queue;
        while(true)
        {
            int n = sock->Recv(&buffer_queue);
            if(n > 0)
            {
                std::string json_package;
                // 解析报文
                bool ret = Decode(buffer_queue, &json_package);
                if(!ret)
                    continue;
                //
                Request req;
                bool ok = req.Deserialize(json_package);
                if(!ok)
                    continue;
                //
                Response resp = _func(req);
                //
                std::string json_str = resp.Serialize();
                std::string send_str = Encode(json_str);
                sock->Send(send_str);

            }
            else if(n == 0)
            {
                LOG(LogLevel::INFO) << "client:" << client.StringAddr() << "Quit!";
                break;
            }
            else
            {
                LOG(LogLevel::WARNING) << "client:" << client.StringAddr() << ", recv error";
                break;
            }

        }


    }
    
    ~Protocol(){}

private:
    func_t _func;

};
