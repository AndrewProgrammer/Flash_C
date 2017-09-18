#pragma once

#include <iostream>

template <typename TBase, typename TDerived>
class Derived : public Base < TBase >
{
private:
    TDerived m_fieldDerived;

public:
    Derived(const TBase valueBase, const TDerived valueDerived) : Base<TBase>(valueBase), m_fieldDerived(valueDerived)
    {
    }

    void ShowDerived() const
    {
        std::cout << m_fieldDerived << std::endl;
    }
};