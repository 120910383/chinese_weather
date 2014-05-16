#ifndef __CHINESE_WEATHER__WEATHER_H_
#define __CHINESE_WEATHER__WEATHER_H_

#include "define.h"
#include "singleton.h"

#include <string>
#include <vector>
#include <map>

NS_CW_BEGIN;

/// 天气模块
class json;
class weather : public singleton<weather>
{
public:
    weather();
    ~weather();

public:
    /// 天气类别
    enum weather_enum
    {
        sunny_day               = 0,                // 阳光明媚(白天)
        clear_night             = 1,                // 万里无云(夜晚)
        fair_day                = 2,                // 晴朗(白天)
        fair_night              = 3,                // 晴朗(夜晚)
        cloudy                  = 4,                // 多云
        partly_cloudy_day       = 5,                // 晴间多云(白天)
        partly_cloudy_night     = 6,                // 晴间多云(夜晚)
        mostly_cloudy_day       = 7,                // 大部多云(白天)
        mostly_cloudy_night     = 8,                // 大部多云(夜晚)
        overcast                = 9,                // 阴
        shower                  = 10,               // 阵雨
        thundershower           = 11,               // 雷阵雨
        thundershower_with_hail = 12,               // 雷阵雨伴有冰雹
        light_rain              = 13,               // 小雨
        moderate_rain           = 14,               // 中雨
        heavy_rain              = 15,               // 大雨
        storm                   = 16,               // 暴雨
        heavy_storm             = 17,               // 大暴雨
        severe_storm            = 18,               // 特大暴雨
        ice_rain                = 19,               // 冻雨
        sleet                   = 20,               // 雨夹雪
        snow_flurry             = 21,               // 阵雪
        light_snow              = 22,               // 小雪
        moderate_snow           = 23,               // 中雪
        heavy_snow              = 24,               // 大雪
        snowstorm               = 25,               // 暴雪
        dust                    = 26,               // 浮尘
        sand                    = 27,               // 扬沙
        duststorm               = 28,               // 沙尘暴
        sandstorm               = 29,               // 强沙尘暴
        foggy                   = 30,               // 雾
        haze                    = 31,               // 霾
        windy                   = 32,               // 风
        blustery                = 33,               // 大风
        hurricane               = 34,               // 飓风
        tropical_storm          = 35,               // 热带风暴
        tornado                 = 36,               // 龙卷风
        cold                    = 37,               // 冷
        hot                     = 38,               // 热
        unknown                 = 99,               // 未知
    };

    /// 空气质量
    struct quality_t
    {
        int                     aqi;                // 空气质量指数(AQI)
        float                   pm25;               // PM2.5颗粒物（粒径小于等于2.5μm）1小时平均值。单位：μg/m³
        float                   pm10;               // PM10颗粒物（粒径小于等于10μm）1小时平均值。单位：μg/m³
        float                   so2;                // 二氧化硫1小时平均值。单位：μg/m³
        float                   no2;                // 二氧化氮1小时平均值。单位：μg/m³
        float                   co;                 // 一氧化碳1小时平均值。单位：mg/m³
        float                   o3;                 // 臭氧1小时平均值。单位：μg/m³
        std::string             last_update;        // 空气质量数据发布时间
    };

    // 当前空气质量
    struct air_quality_t
    {
        std::string                                 quality_description;        // 空气质量类别，有“优、良、轻度污染、中度污染、重度污染、严重污染”6类
        quality_t                                   average_quality;            // 平均空气质量
        std::map<std::string, quality_t>            stations_quality;           // 各个监测站数据
    };

    /// 当前天气
    struct now_t
    {
        weather_enum            code;               // 天气类别
        std::string             text;               // 天气情况文字
        float                   temperature;        // 当前实时温度
        float                   feels_like;         // 当前实时体感温度
        std::string             wind_direction;     // 风向
        float                   wind_speed;         // 风速。单位：km/h
        int                     wind_scale;         // 风力等级
        int                     humidity;           // 湿度。单位：百分比%
        float                   visibility;         // 能见度。单位：公里km
        float                   pressure;           // 气压。单位：百帕hPa
        int                     pressure_rising;    // 气压变化。0或steady为稳定，1或rising为升高，2或falling为降低
        air_quality_t           air_quality;        // 空气质量
    };

    // 生活建议
    struct suggestion_t
    {
        std::string             brief;              // 简要描述
        std::string             details;            // 详细说明
    };

    // 当日概况
    struct today_t
    {
        std::string             sunrise;            // 日出时间
        std::string             sunset;             // 日落时间
        suggestion_t            dressing;           // 穿衣
        suggestion_t            uv;                 // 紫外线
        suggestion_t            car_washing;        // 洗车
        suggestion_t            travel;             // 旅游
        suggestion_t            flu;                // 感冒
        suggestion_t            sport;              // 户外运动
    };

    // 预报天气
    struct future_t
    {
        std::string             data;
        std::string             day;
        weather_enum            day_code;
        std::string             day_text;
        weather_enum            night_code;
        std::string             night_text;
        int                     hight;
        int                     low;
        std::string             cop;
        std::string             wind;
    };

    // 天气综合信息
    struct weather_t
    {
        now_t                   now;
        today_t                 today;
        std::vector<future_t>   future;
    };

public:
    static void process_weather(const json& json_info, weather_t& weather_info);
    static void export_weather(const weather_t& weather_info, json& json_info);

public:
    std::string get_weather_icon(weather_enum code);

protected:
    std::map<weather_enum, std::string>         icons;              // 天气图标
};

NS_CW_END;

#endif // __CHINESE_WEATHER__WEATHER_H_