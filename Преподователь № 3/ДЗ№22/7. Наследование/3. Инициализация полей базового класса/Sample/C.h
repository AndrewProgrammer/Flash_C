#pragma once

#include "B.h"

class C : public B
{
private:
    int m_fieldC;

public:
    C();
    C(const int valueA, const int valueB, const int valueC);
};