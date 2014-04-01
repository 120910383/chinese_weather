#ifndef __CHINESE_WEATHER__PLACE_H_
#define __CHINESE_WEATHER__PLACE_H_

#include "weather.h"
#include "define.h"
#include "singleton.h"

#include <string>
#include <map>

NS_CW_BEGIN;

/// 城市模块
class place : public singleton<place>
{
public:
    place() {}
    ~place() {}

public:
    /// 区域类型
    enum place_enum
    {
        continents          = 0,                // 世界五大洲
        country             = 1,                // 国家
        municipality        = 0,                // 直辖市
        sar                 = 1,                // 特别行政区
        taiwan              = 2,                // 台湾
        province            = 3,                // 省份
        city                = 4,                // 城市
        county              = 5,                // 县镇
        area                = 7,                // 市区
    };

    /// 区域标识
    struct place_t
    {
        place_enum                          type;               // 区域类型
        std::string                         id;                 // 区域id
        std::string                         name;               // 区域名称
        std::string                         en;                 // 区域英文名称
        weather::weather_t                  weather_info;       // 天气信息
        std::map<std::string, place_t>      areas;              // 子区域列表
    };

protected:
    place_t         china;              // 国内
    place_t         global;             // 全球(无中国)
};

NS_CW_END;

#endif // __CHINESE_WEATHER__PLACE_H_