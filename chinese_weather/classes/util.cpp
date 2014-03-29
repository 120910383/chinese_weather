#include "util.h"

#include "define.h"

#ifdef WIN32
#include <windows.h>
#endif

NS_CW_BEGIN;

int32_t util::utf8_to_gbk(const char* str, char* out)
{
#ifdef WIN32
	int32_t len = MultiByteToWideChar(CP_UTF8, 0, str, -1, nullptr, 0);
	wchar_t* src = new wchar_t[len];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, src, len);

	len = WideCharToMultiByte(CP_ACP, 0, src, -1, nullptr, 0, nullptr, nullptr);
	char* dest = new char[len];
	WideCharToMultiByte(CP_ACP, 0, src, -1, dest, len, nullptr, nullptr);

	memcpy(out, dest, len);
	delete[] src;
	delete[] dest;
	return len;
#else
	return 0;
#endif
}

NS_CW_END;