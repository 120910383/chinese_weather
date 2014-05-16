#include "weather.h"

#include "json.h"
using namespace std;

NS_CW_BEGIN;

weather::weather()
{

}

weather::~weather()
{

}

void weather::process_weather(const json& json_info, weather_t& weather_info)
{

}

void weather::export_weather(const weather_t& weather_info, json& json_info)
{

}

string weather::get_weather_icon(weather_enum code)
{
    if (icons.find(code) != icons.end())
        return icons[code];

    return "";
}

NS_CW_END;