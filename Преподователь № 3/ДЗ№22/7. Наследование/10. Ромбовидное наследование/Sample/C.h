#pragma once

#include "A.h"

class C : public A
{
private:
    int m_fieldC;

public:
    C();
    C(const int valueA, const int valueC);

    ~C();
};