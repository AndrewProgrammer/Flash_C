#pragma once

template <typename TData>
class DefaultDeleter
{
public:
    void operator()(TData* const pointer)
    {
        delete pointer;
    }
};

template <typename TData>
class DefaultDeleter<TData[]>
{
public:
    void operator()(TData* const pointer)
    {
        delete[] pointer;
    }
};

template <typename TComData>
class ComDeleter
{
public:
    void operator()(TComData* const pointer)
    {
        pointer->Release();
    }
};