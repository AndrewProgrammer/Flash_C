#pragma once

#include "Base.h"

class Derived : private Base
{
private:
    int m_privateDerived;

public:
    using Base::m_publicBase;
    using Base::ShowBase;

    void SetDerived(const int privateDerived);
    void ShowDerived() const;
};