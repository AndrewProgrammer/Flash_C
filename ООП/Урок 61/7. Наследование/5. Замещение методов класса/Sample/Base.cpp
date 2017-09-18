#include "Base.h"

#include <iostream>

using namespace std;

void Base::Set()
{
    m_fieldBase = 10;
}

void Base::Show() const
{
    cout << m_fieldBase << endl;
}