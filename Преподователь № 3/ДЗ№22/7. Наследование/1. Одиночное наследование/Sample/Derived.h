#pragma once

#include "Base.h"

class Derived : protected Base
{
private:
    int m_privateDerived;

public:
    void SetDerived(const int privateValue);
    void ShowDerived() const;
};