#ifndef __CLIENT_SESSION_H__
#define __CLIENT_SESSION_H__

#include "../../include/HttpFLVDef.h"

#include <queue>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

class ClientSession {
private:
    bool running_;

    std::mutex mutex_;
    std::condition_variable cv_que_;
    std::queue<SharedFLVPacket> packet_que_;

    std::thread thread_;
    SharedHttpClientAgent http_client_agent_;
    std::function<void(const HttpMsg& msg)> cb_;

public:
    ClientSession(SharedHttpClientAgent http_client_agent);
    virtual ~ClientSession();

    void SetHttpClientCallback(std::function<void(const HttpMsg& msg)>&& cb_func);
    void Start();
    void Stop();
    void PushPacket(const SharedFLVPacket packet);

private:
    void Loop();
    void SendPacket();
};


#endif // __CLIENT_SESSION_H__