#include <string>
#include <iostream>
using namespace std;

#include "../classes/define.h"
#include "../classes/httpclient.h"
#include "../classes/util.h"
#include "../classes/json.h"
#include "../classes/city.h"
#include "../classes/weather.h"

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

    json root;
    root.assign_json(gbk_response);
    cout << "<===================JSON-PARSE-TEST===================>" << endl;
    cout << "请求返回状态：" << root["status"].get_string() << endl;
    vector<json> json_cities_weather;
    root["weather"].get_children(json_cities_weather);
    for (const auto& json_weather : json_cities_weather)
    {
        cout << "城市名称：" << json_weather["city_name"].get_string() << endl;
        cout << "城市ID：" << json_weather["city_id"].get_string() << endl;
        cout << "更新时间：" << json_weather["last_update"].get_string() << endl;
        json json_now = json_weather["now"];
        cout << "天气情况：" << json_now["text"].get_string() << endl;
        cout << "天气ID：" << json_now["code"].get_string() << endl;
        cout << "温度：" << json_now["temperature"].get_string() << endl;
        cout << "体感温度：" << json_now["feels_like"].get_string() << endl;
        cout << "风向：" << json_now["wind_direction"].get_string() << endl;
        cout << "风速：" << json_now["wind_speed"].get_string() << endl;
        cout << "风力等级：" << json_now["wind_scale"].get_string() << endl;
        cout << "湿度：" << json_now["humidity"].get_string() << endl;
        cout << "可见距离：" << json_now["visibility"].get_string() << endl;
        cout << "气压：" << json_now["pressure"].get_string() << endl;
        cout << "气压变化：" << json_now["pressure_rising"].get_string() << endl;
    }
    cout << "<==========================END========================>" << endl;

    system("pause");
    return 0;
}
