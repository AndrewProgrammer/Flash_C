#include "C.h"

#include <iostream>

using namespace std;

C::C(const int valueA, const int valueB, const int valueC) : A(valueA), B(valueB), m_field(valueC)
{
}

void C::Show() const
{
    cout << A::m_field << endl;
    cout << B::m_field << endl;
    cout << m_field << endl;
    cout << endl;
}