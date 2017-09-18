#include "Base.h"

#include <iostream>

using namespace std;

void Base::SetBase(const int valueBase)
{
    m_fieldBase = valueBase;
}

void Base::Show() const
{
    cout << m_fieldBase << endl;
}