#pragma once

#include "A.h"
#include "B.h"

class C : public B, public A
{
private:
    int m_fieldC;

public:
    C(const int valueA, const int valueB, const int valueC);

    ~C();

    void ShowC() const;
};