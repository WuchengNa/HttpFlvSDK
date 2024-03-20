#include "httpserver.h"
#include <iostream>

HttpServer::HttpServer()
{
}

HttpServer::~HttpServer()
{
}   

void HttpServer::Init(const std::string &ip, int port)
{
    ip_ = ip;
    port_ = port;
}

void HttpServer::Start()
{
    std::cout << "HttpServer::Start" << std::endl;
    //开始循环监听socket

}

void HttpServer::Stop()
{
    std::cout << "HttpServer::Stop" << std::endl;
}

void HttpServer::Uninit()
{
    std::cout << "HttpServer::Uninit" << std::endl;
}
```
