#ifndef __HTTPSERVER_H__

#define __HTTPSERVER_H__

#include <string>
#include <map>
#include <vector>
#include <functional>

class HttpServer
{
private:
    std::string ip_;
    int port_;

public:
    HttpServer();
    ~HttpServer();

    void Init(const std::string &ip, int port);
    void Start();
    void Stop();
    void Uninit();
};


#endif // __HTTPSERVER_H__