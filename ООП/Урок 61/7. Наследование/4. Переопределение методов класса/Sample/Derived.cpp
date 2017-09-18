#include "Derived.h"

#include <iostream>

using namespace std;

void Derived::SetDerived(const int valueDerived)
{
    m_fieldDerived = valueDerived;
}

void Derived::Show() const
{
    Base::Show();
    cout << m_fieldDerived << endl;
}