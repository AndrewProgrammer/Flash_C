#include "Base.h"

#include <iostream>

using namespace std;

Base::Base() : m_privateBase(0), m_publicBase(0)
{
}

void Base::SetBase(const int privateValue, const int publicValue)
{
    m_privateBase = privateValue;
    m_publicBase = publicValue;
}

void Base::ShowBase() const
{
    cout << m_privateBase << endl;
    cout << m_publicBase << endl;
}