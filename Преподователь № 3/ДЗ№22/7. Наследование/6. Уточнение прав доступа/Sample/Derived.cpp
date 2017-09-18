#include "Derived.h"

#include <iostream>

using namespace std;

void Derived::SetDerived(const int privateDerived)
{
    m_privateDerived = privateDerived;
}

void Derived::ShowDerived() const
{
    cout << m_privateDerived << endl;
}