#ifndef __CHINESE_WEATHER__UTIL_H_
#define __CHINESE_WEATHER__UTIL_H_

#include "define.h"

#include <sstream>

NS_CW_BEGIN;

/// 通用工具类
class util
{
public:
    util() {}
    ~util() {}

public:
    /// UTF8转换GBK
    static int32_t utf8_to_gbk(const char* str, char* out);

    /// 数值 ==> 10进制字符串
    template<typename T>
    static std::string convert_to_string(const T& val)
    {
        std::ostringstream convert_stream;
        convert_stream << val;
        return convert_stream.str();
    }

    /// 10进制字符串 ==> 数值
    template<typename T>
    static T convert_to_number(const std::string& s)
    {
        std::istringstream convert_stream(s);
        T val;
        convert_stream >> val;
        return val;
    }
};

NS_CW_END;

#endif // __CHINESE_WEATHER__UTIL_H_