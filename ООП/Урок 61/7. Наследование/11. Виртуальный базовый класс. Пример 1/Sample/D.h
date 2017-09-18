#pragma once

#include "B.h"
#include "C.h"

class D : public B, public C
{
private:
    int m_fieldD;

public:
    D();
    D(const int valueAB, const int valueB, const int valueAC, const int valueC, const int valueD);

    ~D();
};