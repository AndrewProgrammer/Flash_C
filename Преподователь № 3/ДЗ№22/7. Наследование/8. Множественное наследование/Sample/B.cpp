#include "B.h"

#include <iostream>

using namespace std;

B::B(const int valueB) : m_fieldB(valueB)
{
    cout << "Constructor B" << endl;
}

B::~B()
{
    cout << "Destructor B" << endl;
}

void B::ShowB() const
{
    cout << m_fieldB << endl;
}