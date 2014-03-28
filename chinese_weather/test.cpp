#include <string>
#include <iostream>
using namespace std;

#include "curl/curl.h"
#include "util.h"

const char* URL = "http://api.thinkpage.cn/v2/weather/now.json";
const char* KEY = "SHRWBJVR30";
size_t on_write_data(void* buffer, size_t size, size_t nmemb, void* resp);

/// 测试程序
int main(int argc, char* argv[])
{
	string response;
	string city_name = argc > 1 ? argv[1] : "shanghai";

	// 初始化curl并返回一个指针，后续操作都需要在该指针基础上运作
	CURL* curl = curl_easy_init();
	if (nullptr != curl)
	{
		// 组合url字符串，必须使用key访问，否则出错
		string url_str = URL;
		url_str += "?";
		url_str += "city=";
		url_str += city_name;
		url_str += "&";
		url_str += "key=";
		url_str += KEY;

		// 设置curl请求的地址，自定义参数，write回调
		curl_easy_setopt(curl, CURLOPT_URL, url_str.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, static_cast<void*>(&response));
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &on_write_data);
		
		// 执行访问，如果之前没有设置写函数，那么curl将使用内置的写函数并输出到标准输出上
		curl_easy_perform(curl);

		// 清理curl
		curl_easy_cleanup(curl);
	}

	// 网站文本UTF8==>控制台显示文本gbk

	// 输出请求的报文
	char* gbk_str = new char[response.size() + 1];
	util::utf8_to_gbk(response.c_str(), gbk_str);
	cout << gbk_str << endl;
	delete[] gbk_str;

	system("pause");
    return 0;
}

/// curl报文自定义写函数
size_t on_write_data(void* buffer, size_t size, size_t nmemb, void* resp)
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