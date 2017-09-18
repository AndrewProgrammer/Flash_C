#pragma once

#include "A.h"
#include "B.h"

class C : public B, public A
{
protected:
    int m_field;

public:
    C(const int valueA, const int valueB, const int valueC);

    void Show() const;
};