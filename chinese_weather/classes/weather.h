#ifndef __CHINESE_WEATHER__WEATHER_H_
#define __CHINESE_WEATHER__WEATHER_H_

#include "define.h"
#include "singleton.h"

#include <string>
#include <map>

NS_CW_BEGIN;

/// 天气模块
class weather : public singleton<weather>
{
public:
    weather() {}
    ~weather() {}

public:
    /// 天气类别
    enum weather_enum
    {
        sunny_day               = 0,                        // 阳光明媚(白天)
        clear_night             = 1,                        // 万里无云(夜晚)
        fair_day                = 2,                        // 晴朗(白天)
        fair_night              = 3,                        // 晴朗(夜晚)
        cloudy                  = 4,                        // 多云
        partly_cloudy_day       = 5,                        // 晴间多云(白天)
        partly_cloudy_night     = 6,                        // 晴间多云(夜晚)
        mostly_cloudy_day       = 7,                        // 大部多云(白天)
        mostly_cloudy_night     = 8,                        // 大部多云(夜晚)
        overcast                = 9,                        // 阴
        shower                  = 10,                       // 阵雨
        thundershower           = 11,                       // 雷阵雨
        thundershower_with_hail = 12,                       // 雷阵雨伴有冰雹
        light_rain              = 13,                       // 小雨
        moderate_rain           = 14,                       // 中雨
        heavy_rain              = 15,                       // 大雨
        storm                   = 16,                       // 暴雨
        heavy_storm             = 17,                       // 大暴雨
        severe_storm            = 18,                       // 特大暴雨
        ice_rain                = 19,                       // 冻雨
        sleet                   = 20,                       // 雨夹雪
        snow_flurry             = 21,                       // 阵雪
        light_snow              = 22,                       // 小雪
        moderate_snow           = 23,                       // 中雪
        heavy_snow              = 24,                       // 大雪
        snowstorm               = 25,                       // 暴雪
        dust                    = 26,                       // 浮尘
        sand                    = 27,                       // 扬沙
        duststorm               = 28,                       // 沙尘暴
        sandstorm               = 29,                       // 强沙尘暴
        foggy                   = 30,                       // 雾
        haze                    = 31,                       // 霾
        windy                   = 32,                       // 风
        blustery                = 33,                       // 大风
        hurricane               = 34,                       // 飓风
        tropical_storm          = 35,                       // 热带风暴
        tornado                 = 36,                       // 龙卷风
        cold                    = 37,                       // 冷
        hot                     = 38,                       // 热
        unknown                 = 99,                       // 未知
    };

    /// 当前天气
    struct now_t
    {
        weather_enum            code;
        std::string             text;
        float                   temperature;
        float                   feels_like;
        std::string             wind_direction;
        float                   wind_speed;
        int                     wind_scale;
        int                     humidity;
        float                   visibility;
        float                   pressure;
        int                     pressure_rising;
    };

    /// 空气质量
    struct quality_t
    {
        int                     aqi;
        float                   pm25;
        float                   pm10;
        float                   so2;
        float                   no2;
        float                   co;
        float                   o3;
        std::string             last_update;
    };

    // 当前空气质量
    struct air_quality_t
    {
        std::string                                 description;
        quality_t                                   average_quality;
        std::map<std::string, quality_t>            stations_quality;
    };

    // 生活建议
    struct suggestion_t
    {
        std::string             brief;
        std::string             details;
    };

    // 当日概况
    struct today_t
    {
        std::string                                 sunrise;
        std::string                                 sunset;
        std::map<std::string, suggestion_t>         suggestions;
    };

    // 预报天气
    struct future_t
    {
        std::string             data;
        std::string             day;
        int                     day_code;
        std::string             day_text;
        int                     night_code;
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
        air_quality_t           air;
        today_t                 today;
        future_t                future;
    };

protected:
    std::map<weather_enum, std::string>         icons;              // 天气图标
};

NS_CW_END;

#endif // __CHINESE_WEATHER__WEATHER_H_