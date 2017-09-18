#include "B.h"

#include <iostream>

using namespace std;

B::B(const int valueB) : m_field(valueB)
{
}

void B::Show() const
{
    cout << m_field << endl;
    cout << endl;
}