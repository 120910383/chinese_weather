﻿#ifndef __CHINESE_WEATHER__SINGLETON_H_
#define __CHINESE_WEATHER__SINGLETON_H_

#include <cassert>

/// 单体类模版
template<typename T>
class singleton
{
public:
    singleton()
    {
        assert(nullptr == m_obj);
        m_obj = static_cast<T*>(this);
    }

    ~singleton()
    {
        assert(nullptr != m_obj);
        m_obj = nullptr;
    }

    /// 查询
    static bool HasInstance()
    {
        return nullptr != m_obj;
    }

    /// 获取
    static T* GetInstance()
    {
        if(nullptr == m_obj)
            m_obj = new T();
        return m_obj;
    }

    /// 删除
    static void DeleteInstance()
    {
        if (nullptr != m_obj)
            delete m_obj;
        m_obj = nullptr;
    }

protected:
    static T* m_obj;
};

template<typename T>
T* singleton<T>::m_obj = nullptr;

#endif // __CHINESE_WEATHER__SINGLETON_H_