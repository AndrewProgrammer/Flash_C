#include "C.h"

#include <iostream>

using namespace std;

C::C() : m_fieldC(0)
{
}

C::C(const int valueA, const int valueB, const int valueC) : B(valueA, valueB), m_fieldC(valueC)
{
}