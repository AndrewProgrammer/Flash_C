#pragma once

#include "C.h"

class A : public virtual C
{
private:
    int m_fieldA;

public:
    A();
    A(const int valueA, const int valueC);

    ~A();
};