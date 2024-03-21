#include "client_session.h"
#include "../http/httpclient_agent.h"


ClientSession::ClientSession(SharedHttpClientAgent http_client_agent)
    : running_(false), http_client_agent_(http_client_agent) {

}

ClientSession::~ClientSession() {
    Stop();
}

void ClientSession::SetHttpClientCallback(std::function<void(const HttpMsg& msg)>&& cb_func) {
    cb_ = std::move(cb_func);
}

void ClientSession::Start() {
    running_ = true;
    thread_ = std::thread(&ClientSession::Loop, this);
}

void ClientSession::Stop() {
    running_ = false;
    if (thread_.joinable()) {
        thread_.join();
    }
}

void ClientSession::PushPacket(const SharedFLVPacket packet) {
    std::lock_guard<std::mutex> lock(mutex_);
    packet_que_.push(packet);
    cv_que_.notify_one();
}

void ClientSession::Loop() {
    while (running_) {
        SendPacket();
        // Add any additional logic here
    }
}

void ClientSession::SendPacket() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_que_.wait(lock, [this] { return !packet_que_.empty(); });

    SharedFLVPacket packet = packet_que_.front();
    packet_que_.pop();
    lock.unlock();

    std::string data;

    if(http_client_agent_)
        http_client_agent_->Send(data);
    // Send the packet using http_client_agent_
    // Add any additional logic here
}
