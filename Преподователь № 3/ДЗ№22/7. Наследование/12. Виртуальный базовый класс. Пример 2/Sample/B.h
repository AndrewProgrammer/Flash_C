#pragma once

#include "C.h"

class B : public virtual C
{
private:
    int m_fieldB;

public:
    B();
    B(const int valueB, const int valueC);

    ~B();
};