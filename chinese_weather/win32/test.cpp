#include <string>
#include <iostream>
using namespace std;

#include "../classes/define.h"
#include "../classes/httpclient.h"
#include "../classes/util.h"
#include "json/json.h"

USING_NS_CW;

const char* URL = "http://api.thinkpage.cn/v2/weather/now.json";
const char* KEY = "SHRWBJVR30";
size_t on_write_data(void* buffer, size_t size, size_t nmemb, void* resp);

/// 测试程序
int32_t main(int32_t argc, char* argv[])
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
	char* gbk_data = new char[response.size() + 1];
	util::utf8_to_gbk(response.c_str(), gbk_data);
    string gbk_response(gbk_data);
	cout << gbk_response << endl;
	delete[] gbk_data;

    // JSON解析测试
    Json::Reader reader;
    Json::Value root;
    if (reader.parse(gbk_response, root, false))
    {
        Json::Value json_status = root["status"];
        cout << "<===================JSON-PARSE-TEST===================>" << endl;
        cout << "请求返回状态：" << json_status.asString() << endl;
        Json::Value json_city_array = root["weather"];
        for (uint32_t index = 0; index <json_city_array.size(); ++index)
        {
            Json::Value json_weather = json_city_array[index];
            
            cout << "城市名称：" << json_weather["city_name"].asString() << endl;
            cout << "城市ID：" << json_weather["city_id"].asString() << endl;
            cout << "更新时间：" << json_weather["last_update"].asString() << endl;
            Json::Value json_now = json_weather["now"];
            cout << "天气情况：" << json_now["text"].asString() << endl;
            cout << "天气ID：" << json_now["code"].asString() << endl;
            cout << "温度：" << json_now["temperature"].asString() << endl;
            cout << "体感温度：" << json_now["feels_like"].asString() << endl;
            cout << "风向：" << json_now["wind_direction"].asString() << endl;
            cout << "风速：" << json_now["wind_speed"].asString() << endl;
            cout << "风力等级：" << json_now["wind_scale"].asString() << endl;
            cout << "湿度：" << json_now["humidity"].asString() << endl;
            cout << "可见距离：" << json_now["visibility"].asString() << endl;
            cout << "气压：" << json_now["pressure"].asString() << endl;
            cout << "气压变化：" << json_now["pressure_rising"].asString() << endl;
        }
        cout << "<==========================END========================>" << endl;
    }

	system("pause");
    return 0;
}
