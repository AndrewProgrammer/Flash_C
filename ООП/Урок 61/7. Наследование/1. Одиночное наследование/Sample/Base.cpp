#include "Base.h"

#include <iostream>

using namespace std;

void Base::SetBase(const int privateValue, const int protectedValue, const int publicValue)
{
    m_privateBase = privateValue;
    m_protectedBase = protectedValue;
    m_publicBase = publicValue;
}

void Base::ShowBase() const
{
    cout << m_privateBase << endl;
    cout << m_protectedBase << endl;
    cout << m_publicBase << endl;
}