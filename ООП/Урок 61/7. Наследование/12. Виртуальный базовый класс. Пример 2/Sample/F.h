#pragma once

#include "B.h"

class F : public virtual B
{
private:
    int m_fieldF;

public:
    F();
    F(const int valueB, const int valueC, const int valueF);

    ~F();
};