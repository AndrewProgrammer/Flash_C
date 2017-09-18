#include "A.h"

#include <iostream>

using namespace std;

A::A(const int valueA) : m_field(valueA)
{
}

void A::Show() const
{
    cout << m_field << endl;
    cout << endl;
}