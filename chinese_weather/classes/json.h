#ifndef __CHINESE_WEATHER__JSON_H_
#define __CHINESE_WEATHER__JSON_H_

#include "define.h"
#include <string>
#include <vector>
namespace Json { class Value; }

NS_CW_BEGIN;

class json
{
public:
	/// 节点类型
	enum value_type_enum
	{
		null_value = 0,
		int_value,
		uint_value,
		real_value,
		string_value,
		boolean_value,
		array_value,
		object_value,
	};

public:
	json(value_type_enum value_type = null_value);
	~json();

public:
	value_type_enum get_value_type() const;
	std::string get_string(std::string default_value = std::string()) const;
	bool get_bool(bool default_value = false) const;
	int32_t get_int32(int32_t default_value = 0) const;
	uint32_t get_uint32(uint32_t default_value = 0) const;
	int64_t get_int64(int64_t default_value = 0) const;
	uint64_t get_uint64(uint64_t default_value = 0) const;
	float get_float(float default_value = 0) const;
	double get_double(double default_value = 0) const;
	timestamp_t get_timestamp(timestamp_t default_value = 0) const;
	void get_children(std::vector<json>& children) const;

public:
	bool assign_json(const std::string& json_content);
	json operator[] (const std::string& key);

public:
	bool empty() const;
	void clear();

private:
	Json::Value* m_impl;
};

NS_CW_END;

#endif // __CHINESE_WEATHER__SINGLETON_H_