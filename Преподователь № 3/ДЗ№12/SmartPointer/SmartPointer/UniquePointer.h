#pragma once

#include <type_traits>

#include "DefaultDeleter.h"

template <typename TData, typename TDeleter = DefaultDeleter<TData>>
class UniquePointer
{
private:
    TDeleter m_deleter;
    std::remove_all_extents_t<TData>* m_pointer = nullptr;
public:
    UniquePointer() = default;

    UniquePointer(std::remove_all_extents_t<TData>* const pointer) : m_pointer(pointer)
    {
    }

    ~UniquePointer()
    {
        m_deleter(m_pointer);
    }

    std::remove_all_extents_t<TData>* operator->() const
    {
        return m_pointer;
    }

    TData& operator*() const
    {
        return *m_pointer;
    }
};