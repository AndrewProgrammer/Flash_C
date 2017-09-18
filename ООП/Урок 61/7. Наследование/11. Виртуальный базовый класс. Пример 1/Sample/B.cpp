#include "B.h"

#include <iostream>

using namespace std;

B::B() : m_fieldB(0)
{
    cout << "Default constructor B" << endl;
}

B::B(const int valueA, const int valueB) : A(valueA), m_fieldB(valueB)
{
    cout << "Constructor B" << endl;
}

B::~B()
{
    cout << "Destructor B" << endl;
}