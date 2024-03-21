#ifndef   __STREAM_SESSION_H__
#define   __STREAM_SESSION_H__

//流会话类，负责启停和打包
class StreamSession
{

public:
    // Open a stream
    void openStream();

    // Close a stream
    void closeStream();

    // Push audio frame to the specified stream
    void pushAudioFrame(const AudioFrame& frame);

    // Push video frame to the specified stream
    void pushVideoFrame(const VideoFrame& frame);

};





#endif // __STREAM_SESSION_H__
