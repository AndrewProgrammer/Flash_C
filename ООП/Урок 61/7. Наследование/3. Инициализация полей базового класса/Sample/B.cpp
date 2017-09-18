#include "B.h"

#include <iostream>

using namespace std;

B::B() : m_fieldB(0)
{
}

B::B(const int valueA, const int valueB) : A(valueA), m_fieldB(valueB)
{
}