#pragma once

#include <iostream>

template <typename TBase>
class Base
{
private:
    TBase m_fieldBase;

public:
    Base(const TBase valueBase) : m_fieldBase(valueBase)
    {
    }

    void ShowBase() const
    {
        std::cout << m_fieldBase << std::endl;
    }
};