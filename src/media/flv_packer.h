#ifndef __FLV_PACKER_H__
#define __FLV_PACKER_H__

#include <queue>
#include <memory>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class AudioDesc;
class VideoDesc;
using ShareAudioDesc = std::shared_ptr<AudioDesc>;
using ShareVideoDesc = std::shared_ptr<VideoDesc>;
class AVFrame;
class FLVPacket;
using SharedAVFrame = std::shared_ptr<AVFrame>;

class FLVPacker {

private:
    ShareAudioDesc audio_desc_;
    ShareVideoDesc video_desc_;

    bool running_;
    std::mutex mutex_;
    std::condition_variable cv_que_;
    std::queue<SharedAVFrame> av_frame_que_;

    std::thread thread_;
    std::function<void(const FLVPacket& packet)> cb_;
public:
    FLVPacker();
    virtual ~FLVPacker();

    void SetAudioDesc(ShareAudioDesc audio_desc);
    void SetVideoDesc(ShareVideoDesc video_desc);
    
    void SetPacketCallback(std::function<void(const FLVPacket& packet)>&& cb_func);
    void Start();
    void Stop();

    void PushAVFrame(const SharedAVFrame frame);

private:
    void Loop();
    FLVPacket Pack(SharedAVFrame frame);   
};

#endif // __FLV_PACKER_H__