#include "Derived.h"

#include <iostream>

using namespace std;

void Derived::SetDerived(const int privateValue)
{
    m_privateDerived = privateValue;
}

void Derived::ShowDerived() const
{
    cout << m_privateBase << endl;
    cout << m_protectedBase << endl;
    cout << m_publicBase << endl;
    cout << m_privateDerived << endl;
}