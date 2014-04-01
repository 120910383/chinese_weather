#include "json.h"

#include "util.h"
#include "json/json.h"
using namespace std;

NS_CW_BEGIN;

json::json(value_type_enum value_type)
    : m_impl_delete(true)
{
    Json::ValueType vt = static_cast<Json::ValueType>(value_type);
    m_impl = new Json::Value(vt);
}

json::json(const json& val)
    : m_impl(val.m_impl)
    , m_impl_delete(false)
{
}

json::json(Json::Value* val)
    : m_impl(val)
    , m_impl_delete(false)
{
}

json::~json()
{
    if (m_impl_delete)
    {
        CW_SAFE_DELETE(m_impl);
    }
}

json::value_type_enum json::get_value_type() const
{
    return static_cast<value_type_enum>(m_impl->type());
}

std::string json::get_string(std::string default_value) const
{
    Json::ValueType vt = m_impl->type();
    if (Json::nullValue == vt || Json::stringValue == vt || Json::booleanValue == vt)
        return m_impl->asString();
    else if (Json::intValue == vt || Json::uintValue == vt || Json::realValue == vt)
        return util::convert_to_string(get_double());

    cwassert(false);
    return "";
}

bool json::get_bool(bool default_value) const
{
    return m_impl->asBool();
}

int32_t json::get_int32(int32_t default_value) const
{
    return static_cast<int32_t>(get_double(default_value));
}

uint32_t json::get_uint32(uint32_t default_value) const
{
    return static_cast<uint32_t>(get_double(default_value));
}

int64_t json::get_int64(int64_t default_value) const
{
    return static_cast<int64_t>(get_double(static_cast<double>(default_value)));
}

uint64_t json::get_uint64(uint64_t default_value) const
{
    return static_cast<uint64_t>(get_double(static_cast<double>(default_value)));
}

float json::get_float(float default_value) const
{
    return static_cast<float>(get_double(default_value));
}

double json::get_double(double default_value) const
{
    Json::ValueType vt = m_impl->type();
    if (Json::nullValue == vt || Json::intValue == vt || Json::uintValue == vt || Json::realValue == vt || Json::booleanValue == vt)
        return m_impl->asDouble();
    else if (Json::stringValue == vt)
        return util::convert_to_number<double>(get_string());

    cwassert(false);
    return 0.0;
}

timestamp_t json::get_timestamp(timestamp_t default_value) const
{
    return static_cast<timestamp_t>(get_double(static_cast<double>(default_value)));
}

void json::get_children(std::vector<json>& children) const
{
    children.clear();
    if (Json::arrayValue == m_impl->type())
    {
        for (auto& element : *m_impl)
        {
            json child_node(&element);
            children.push_back(child_node);
        }
    }
}

bool json::assign_json(const std::string& json_content)
{
    Json::Reader reader;
    return reader.parse(json_content, *m_impl, false);
}

json json::operator[] (const std::string& key) const
{
    return json(&(*m_impl)[key]);
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