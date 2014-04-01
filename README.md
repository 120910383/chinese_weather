chinese_weather
===============

C++编写的中国城市天气获取工具，使用http web api方式请求数据，数据源为心知天气，网址 http://thinkpage.cn/weather/api/

该api提供商不提供公众帐号，我已申请一个免费试用15天，api请求次数10000次的key供测试使用，请勿滥用，用完后我会更新测试key，当然，你也可以自行申请免费key进行测试，详细情况见源码或后续补充说明


2014-04-01 17:00 更新

已有功能
* 查询指定城市当前天气

正在做的功能
* 格式化天气数据显示，使其更加美观
* 查询指定城市未来7天天气预报
* 查询指定城市PM2.5
* 查询指定城市天气建议指数

打算做的功能(未定)
* 缓存已查询的天气(5分钟)，减少网络请求次数
* 适配其他天气源：中国天气网 http://smart.weather.com.cn/wzfw/smart/weatherapi.shtml
* 雅虎天气 http://developer.yahoo.com/weather/
* 使用cocos2d-x绘制界面，创建ios,android天气应用