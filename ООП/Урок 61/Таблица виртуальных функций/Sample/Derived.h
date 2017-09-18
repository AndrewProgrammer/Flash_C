#pragma once

#include "Base1.h"
#include "Base2.h"
#include "Base3.h"

class Derived : public Base1, public Base2, public Base3
{
public:
    int m_fieldB;

    virtual void DerivedMethod1() const;
    virtual void DerivedMethod2() const;
};