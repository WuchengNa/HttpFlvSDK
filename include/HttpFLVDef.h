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







#endif // __HTTPFLVDEF_H__