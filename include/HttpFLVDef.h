#ifndef __HTTPFLVDEF_H__
#define __HTTPFLVDEF_H__

//audio tag type
enum AudioTagType
{
    AUDIO_TAG_TYPE_SEQUENCE_HEADER = 0,
    AUDIO_TAG_TYPE_AAC = 1,
};

//video tag type
enum VideoTagType
{
    VIDEO_TAG_TYPE_SEQUENCE_HEADER = 0,
    VIDEO_TAG_TYPE_AVC = 1,
};

//flv tag type
enum FlvTagType
{
    FLV_TAG_TYPE_AUDIO = 8,
    FLV_TAG_TYPE_VIDEO = 9,
    FLV_TAG_TYPE_SCRIPT = 18,
};

struct HttpFlvSvrInitParam
{
    int port;
    int max_client_num;
    int max_stream_num;
};  

struct AVInputParam
{
    int input_type;
    int input_id;
    int input_index;
};

struct AVOutputParam
{
    int output_type;
    int output_id;
    int output_index;
};

struct AVFrame
{
    int frame_type;
    int frame_index;
    int frame_size;
    int frame_data;
};






#endif // __HTTPFLVDEF_H__ 