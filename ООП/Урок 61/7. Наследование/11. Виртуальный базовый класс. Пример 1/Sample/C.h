#pragma once

#include "A.h"

class C : public virtual A
{
private:
    int m_fieldC;

public:
    C();
    C(const int valueA, const int valueC);

    ~C();
};