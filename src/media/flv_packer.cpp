#include "flv_packer.h"

FLVPacker::FLVPacker()
    : running_(false) {
}

FLVPacker::~FLVPacker() {
    Stop();
}

void FLVPacker::SetAudioDesc(ShareAudioDesc audio_desc) {
    audio_desc_ = audio_desc;
}

void FLVPacker::SetVideoDesc(ShareVideoDesc video_desc) {
    video_desc_ = video_desc;
}

void FLVPacker::SetPacketCallback(std::function<void(const FLVPacket& packet)>&& cb_func) {
    cb_ = std::move(cb_func);
}

void FLVPacker::Start() {
    running_ = true;
    thread_ = std::thread(&FLVPacker::Loop, this);
}

void FLVPacker::Stop() {
    running_ = false;
    if (thread_.joinable()) {
        thread_.join();
    }
}

void FLVPacker::PushAVFrame(const SharedAVFrame frame) {
    std::lock_guard<std::mutex> lock(mutex_);
    av_frame_que_.push(frame);
    cv_que_.notify_one();
}

void FLVPacker::Loop() {
    while (running_) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_que_.wait(lock, [this] { return !av_frame_que_.empty(); });

        SharedAVFrame frame = av_frame_que_.front();
        av_frame_que_.pop();
        lock.unlock();

        //FLVPacket packet = Pack(frame);
        // if (cb_) {
        //     cb_(packet);
        // }
    }
}

// FLVPacket FLVPacker::Pack(SharedAVFrame frame) {
// //     // Pack the frame into FLV packet
// //     // Add any additional logic here
// //     return FLVPacket();
// }

