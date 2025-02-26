#ifndef __MSG_QUEUE_H__
#define __MSG_QUEUE_H__

#include <mutex>
#include <condition_variable>
#include <queue>

template <class Msg>
class MsgQueue{
public:
    MsgQueue(){}
    virtual ~MsgQueue(){}

    void Push(const Msg& msg){
        std::unique_lock<std::mutex> lk(mtx_);
        msg_que_.push(msg);
        cv_que_ept_.notify_all();
    }

    bool Pop(Msg& msg){
        std::unique_lock<std::mutex> lk(mtx_);
        cv_que_ept_.wait(lk,[this](){ return !msg_que_.empty()||stop_;});

        if(stop_){
            return false;
        }

        msg = msg_que_.front();
        msg_que_.pop();
        cv_que_ept_.notify_all();
        return true;
    }

    bool Empty(){
        std::unique_lock<std::mutex> lk(mtx_);
        return msg_que_.empty();
    }

    void Terminate(){
        std::unique_lock<std::mutex> lk(mtx_);
        if(!stop_){
            stop_ = true;
            cv_que_ept_.notify_all();
        }
    }
private:
    std::mutex mtx_;
    std::condition_variable cv_que_ept_;
    std::queue<Msg> msg_que_;

};

#endif