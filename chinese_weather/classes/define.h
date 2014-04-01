#ifndef __CHINESE_WEATHER__DEFINE_H_
#define __CHINESE_WEATHER__DEFINE_H_

#include <cassert>

/// 重定义32位和64位整数类型
#define INT_TYPES
typedef     signed __int32          int32_t;
typedef     unsigned __int32        uint32_t;
typedef     signed __int64          int64_t;
typedef     unsigned __int64        uint64_t;

/// 定义时间戳和时间段相关类型
typedef     int64_t                 timestamp_t;
typedef     int64_t                 timespan_t;

/// 定义命名空间便捷宏
#ifdef __cplusplus
    #define     NS_CW_BEGIN             namespace ChineseWeather {
    #define     NS_CW_END               }
    #define     USING_NS_CW             using namespace ChineseWeather
#else
    #define     NS_CW_BEGIN
    #define     NS_CW_END
    #define     USING_NS_CW
#endif // __cplusplus

/// 断言宏
#if defined(DEBUG) || defined(_DEBUG)
    #define     cwassert(exp)           assert(exp)
#else
    #define     cwassert(exp)
#endif // DEBUG || _DEBUG

/// 指针删除
#define CW_SAFE_DELETE(p)               do { if(p) { delete (p); (p) = 0; } } while(0)
#define CW_SAFE_DELETE_ARRAY(p)         do { if(p) { delete[] (p); (p) = 0; } } while(0)

#endif // __CHINESE_WEATHER__DEFINE_H_