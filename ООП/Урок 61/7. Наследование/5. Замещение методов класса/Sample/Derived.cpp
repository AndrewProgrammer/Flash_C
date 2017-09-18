#include "Derived.h"

#include <iostream>

using namespace std;

void Derived::Set(const int valueDerived)
{
    m_fieldDerived = valueDerived;
}

void Derived::Show() const
{
    cout << m_fieldDerived << endl;
}