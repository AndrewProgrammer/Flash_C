#pragma once

#include "Base.h"

class Derived : public Base
{
private:
    int m_fieldDerived;

public:
    void SetDerived(const int valueDerived);
    void Show() const;
};