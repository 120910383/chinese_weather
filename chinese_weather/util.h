#ifndef __CHINESE_WEATHER__UTIL_H_
#define __CHINESE_WEATHER__UTIL_H_

/// 通用工具类
class util
{
public:
	util() {}
	~util() {}

public:
	/// UTF8转换GBK
	static int utf8_to_gbk(const char* str, char* out);
};

#endif // __CHINESE_WEATHER__UTIL_H_