# 本轮笔误和编译接口修正

以下项目已直接修正。这里记录的是拼写、声明、调用不一致，以及能从现有调用方式确定意图的漏项；运行策略问题另行说明。

| 文件 | 修正内容 |
| --- | --- |
| `Main.cc` | `aegv` 改为 `argv`；调用正确的日志策略入口；计算回调统一使用 `Response` 和 `Execute`。 |
| `Common.hpp` | `neinet/in.h` 改为 `netinet/in.h`；`LISTEM_ERR` 改为 `LISTEN_ERR`。 |
| `Connection.hpp` | `#pragma onces` 改为 `#pragma once`；补充 `fcntl.h` 和类结尾分号。 |
| `InetAddr.hpp` | 修正 `stys/socket.h`、`htos`、错误的 `sizeof` 对象、`socklen_t`、成员名和类结尾分号；统一 `NetAddrPtr()` 名称及返回类型；补上监听器使用的默认构造函数。 |
| `Socket.hpp` | 修正 `neinet/in.h`、`::sock`、构造函数冒号、日志行末字符、`local`/`localaddr`、`socklen_t` 和 `Close()` 的 fd 判断；统一 `Accept(InetAddr*)` 的声明与实现，补齐现有调用需要的 `Fd()`、`Connect()`，将地址参数改为显式转换，并为头文件加保护。 |
| `Epoller.hpp` | `_enfd` 改为 `_epfd`，`event` 改为 `events`，`epoll_events` 改为 `epoll_event`；统一 `DelEvent()` 名称；让 `WaitEvents()` 返回 `epoll_wait` 的结果并补上类结尾分号。 |
| `Reactor.hpp` | 统一 `Connection`、`GetEvent()`、`GetSockFd()`、`AddEvent()` 等类型和方法名；移除多余分号，修正 `if` 语法和连接存在性检查；统一 `_connection` 成员名并补上类结尾分号。 |
| `Channel.hpp` | `EINTER` 改为 `EINTR`；将错误的位或判断改为逻辑或；统一 `GetOwner()`、`EnableReadWriter()`、`GetSockFd()`、`Excepter()` 调用与重写，并补上类结尾分号。 |
| `Listenner.hpp` | 修正 `#pragma once`、`std::make_unique`、`std::make_shared`、监听端口传参、`SetEvent()`、`Accept()`、`RegisterHandler()` 和 `GetOwner()` 的调用；统一 `GetSockFd()` 返回类型并补上类结尾分号。保留原文件名以免影响现有引用。 |
| `Protocol.hpp` | 修正 `Json::Value`、`Json::FastWriter`、`writer`、`std::stoi`、`Socket` 等名称；统一 `Response` 类及构造/析构函数、`SetResult()`；补上缺少的构造函数和 `Execute()`，使主程序已有调用有对应实现。 |
| `NetCal.hpp` | 统一 `Response`、`Execute()` 与 `SetResult()` 名称。 |
| `Log.hpp` | `loccaltime_r` 改为 `localtime_r`；为多态日志策略补上虚析构函数。 |
| `Makefile` | 补上 `-pthread` 和 `-ljsoncpp` 链接参数。 |

静态检查可用 `cppcheck --enable=warning --std=c++17 --language=c++ --suppress=missingIncludeSystem --suppress=missingInclude Main.cc`。本机的 Windows g++ 没有 Linux `sys/epoll.h`，因此完整的 Linux 编译及网络运行仍需 Linux 环境确认。
