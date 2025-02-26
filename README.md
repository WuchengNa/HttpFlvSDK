# HttpFlvSDK（v1.0.1)

    项目为提供一个Http-flv的流媒体服务sdk,支持多路音视频流并发，支持多端客户端点播
    1.支持多路视频流同时接入
    2.支持多个客户端同时点播
    3.支持断线重连
    4.支持多种音视频输入格式
    5.点播视频流格式为http-flv,音频流格式为aac,视频流编码为h264,音频流编码为aac
    6.支持本地视频文件输入
    

    项目工程结构
    HttpFlvSDK
    接口层：
        Init() 初始化流媒体服务sdk
        Uninit() 销毁流媒体服务sdk
        StartStreamSession() 启动流会话
        StopStreamSession() 停止流会话
        SetVideoInput() 设置视频输入
        SetAudioInput() 设置音频输入
        SetVideoOutput() 设置视频输出
        SetAudioOutput() 设置音频输出
        PushAVFrame() 推送音视频帧
        SetOnStreamSessionStatus() 设置流会话状态回调
        SetOnClientSessionStatus() 设置客户端会话状态回调
        RemoveClientSession() 移除客户端会话
        

    流会话管理（流会话管理为流媒体服务sdk的核心功能，负责流媒体服务的接入、处理、分发）
        --视频输入
        --音频输入
        --视频复用FLV格式
        --音频复用ACC格式
        --FLV帧包分发
    客户端会话管理（客户端会话管理为流媒体服务sdk的客户端管理功能，负责客户端的接入、处理、分发）
        --客户端点流请求接入处理
        --客户端长链接会话建立与保活
        --客户端链接推FLV包
        --客户端会话断开通知与会话清理
        
    
