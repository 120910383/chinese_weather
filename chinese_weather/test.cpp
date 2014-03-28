#include <string>
#include <iostream>
using namespace std;

#include "httpclient.h"
#include "util.h"

const char* URL = "http://api.thinkpage.cn/v2/weather/now.json";
const char* KEY = "SHRWBJVR30";
size_t on_write_data(void* buffer, size_t size, size_t nmemb, void* resp);

/// 测试程序
int main(int argc, char* argv[])
{
	string response;
	string city_name = argc > 1 ? argv[1] : "shanghai";

    // 组合url字符串，必须使用key访问，否则出错
    string url_str = URL;
    url_str += "?";
    url_str += "city=";
    url_str += city_name;
    url_str += "&";
    url_str += "key=";
    url_str += KEY;

    // 请求数据(阻塞)
    if(httpclient::GetInstance()->get(url_str, response))
    {
        cout << "Http Request Error!" << endl;
        return 0;
    }

	// 网站文本UTF8==>控制台显示文本gbk
	char* gbk_str = new char[response.size() + 1];
	util::utf8_to_gbk(response.c_str(), gbk_str);
	cout << gbk_str << endl;
	delete[] gbk_str;

	system("pause");
    return 0;
}
