#include "httpclient.h"

#include "curl/curl.h"
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

NS_CW_BEGIN;

int32_t httpclient::get(const string& url, string& response)
{
    CURLcode res;
    // 初始化curl并返回一个指针，后续操作都需要在该指针基础上运作
    CURL* curl = curl_easy_init();
    if (nullptr == curl)
    {
        return CURLE_FAILED_INIT;
    }

    // 设置curl请求的地址，自定义参数，write回调
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, nullptr);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &httpclient::on_write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, static_cast<void*>(&response));
   
    // 执行访问，如果之前没有设置写函数，那么curl将使用内置的写函数并输出到标准输出上
    res = curl_easy_perform(curl);

    // 清理curl
    curl_easy_cleanup(curl);

    return res;
}

size_t httpclient::on_write_data(void* buffer, size_t size, size_t nmemb, void* resp)
{
    string* str = static_cast<string*>(resp);
    if (nullptr == str || nullptr == buffer)
    {
        return -1;
    }

    char* data = static_cast<char*>(buffer);
    str->append(data, size * nmemb);
    return size * nmemb;
}

NS_CW_END;