#ifndef __CHINESE_WEATHER__UTIL_H_
#define __CHINESE_WEATHER__UTIL_H_

#include "define.h"

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
};

NS_CW_END;

#endif // __CHINESE_WEATHER__UTIL_H_