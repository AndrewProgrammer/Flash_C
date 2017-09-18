#pragma once

#include "D.h"
#include "F.h"

class E : public D, public F
{
private:
    int m_fieldE;

public:
    E();
    E(const int valueA, const int valueCD, const int valueD, const int valueB, const int valueCF, const int valueE, const int valueF);

    ~E();
};