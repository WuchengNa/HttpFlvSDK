#ifndef __HTTPFLV_SVR_SDK_H__
#define __HTTPFLV_SVR_SDK_H__        


#include "HttpFLVDef.h"
#define HTTPFLV_SVR_SDK_EXPORT 1

#define HTTPFLV_SVR_SDK_VERSION "1.0.1"
#define HTTPFLV_SVR_SDK_VERSION_MAJOR 1
#define HTTPFLV_SVR_SDK_VERSION_MINOR 0
#define HTTPFLV_SVR_SDK_VERSION_PATCH 1

#ifdef _WIN32  
    #ifdef HTTPFLV_SVR_SDK_EXPORT
        #define HTTPFLV_SVR_API __declspec(dllexport)
    #else
        #define HTTPFLV_SVR_API __declspec(dllimport)
    #endif
        #define CALL_API __stdcall
#else //linux
    #define HTTPFLV_SVR_API
    #define CALL_API    
#endif // _WIN32


#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

    //初始化流媒体服务sdk
    //init_param_json: 初始化参数json字符串
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_Init(const char* init_param_json);

    //销毁流媒体服务sdk
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_Uninit();

    //启动流会话
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_StartStreamSession(int stream_id, AVInputParam* input_param, AVOutputParam* output_param);

    //停止流会话
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_StopStreamSession(int stream_id);

    //设置视频输入
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_SetVideoInput();

    //设置音频输入
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_SetAudioInput();

    //设置视频输出
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_SetVideoOutput();

    //设置音频输出
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_SetAudioOutput();   

    //推送音视频帧
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_PushAVFrame();

    //设置流会话状态回调
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_SetOnStreamSessionStatus();

    //设置客户端会话状态回调
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_SetOnClientSessionStatus();

    //移除客户端会话
    //返回值: 0表示成功,其他表示失败
    HTTPFLV_SVR_API int CALL_API HttpFlvSvr_RemoveClientSession();


#ifdef __cplusplus
}
#endif // __cplusplus



#endif // __HTTPFLV_SVR_SDK_H__