#ifndef __CHINESE_WEATHER__HTTPCLIENT_H_
#define __CHINESE_WEATHER__HTTPCLIENT_H_

#include "singleton.h"

#include <string>

/// http客户端
class httpclient : public singleton<httpclient>
{
public:
    httpclient() {}
    ~httpclient() {}

public:
    /// http get请求(阻塞)，url请求地址，response应答内容
    int get(const std::string& url, std::string& response);

protected:
    static size_t on_write_data(void* buffer, size_t size, size_t nmemb, void* resp);
};

#endif // __CHINESE_WEATHER__HTTPCLIENT_H_