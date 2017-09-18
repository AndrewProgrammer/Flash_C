#pragma once

#include "A.h"

class D : public virtual A
{
private:
    int m_fieldD;

public:
    D();
    D(const int valueA, const int valueC, const int valueD);

    ~D();
};