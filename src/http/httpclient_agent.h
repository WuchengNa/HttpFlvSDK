#ifndef __HTTPCLIENT_AGENT_H__
#define __HTTPCLIENT_AGENT_H__

#include <string>

class HttpClientAgent
{
private:
    /* data */
public:
    HttpClientAgent
    (/* args */);
    ~HttpClientAgent
    ();

    bool Send(const std::string& data);
};



#endif // __HTTPCLIENT_AGENT_H__