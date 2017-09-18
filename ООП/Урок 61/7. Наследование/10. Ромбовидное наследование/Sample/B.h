#pragma once

#include "A.h"

class B : public A
{
private:
    int m_fieldB;

public:
    B();
    B(const int valueA, const int valueB);

    ~B();
};