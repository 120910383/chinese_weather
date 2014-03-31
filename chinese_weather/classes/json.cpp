#include "json.h"

#include "json/json.h"
using namespace std;

NS_CW_BEGIN;

json::json(value_type_enum value_type)
{
	m_impl = new Json::Value;
}

json::~json()
{
	if (NULL != m_impl)
	{
		delete m_impl;
	}
}

json::value_type_enum json::get_value_type() const
{
	return (value_type_enum)(m_impl->type());
}

std::string json::get_string(std::string default_value) const
{
	return m_impl->asString();
}

bool json::get_bool(bool default_value) const
{
	return m_impl->asBool();
}

int32_t json::get_int32(int32_t default_value) const
{
	return m_impl->asInt();
}

uint32_t json::get_uint32(uint32_t default_value) const
{
	return m_impl->asUInt();
}

int64_t json::get_int64(int64_t default_value) const
{
	return m_impl->asInt();
}

uint64_t json::get_uint64(uint64_t default_value) const
{
	return m_impl->asUInt();
}

float json::get_float(float default_value) const
{
	return m_impl->asDouble();
}

double json::get_double(double default_value) const
{
	return m_impl->asDouble();
}

timestamp_t json::get_timestamp(timestamp_t default_value) const
{
	return m_impl->asInt();
}

void json::get_children(std::vector<json>& children) const
{

}

bool json::assign_json(const std::string& json_content)
{
	Json::Reader reader;
	return reader.parse(json_content, *m_impl, false);
}

json json::operator[] (const std::string& key)
{
	return json();
}

bool json::empty() const
{
	return m_impl->empty();
}

void json::clear()
{
	m_impl->clear();
}

NS_CW_END;