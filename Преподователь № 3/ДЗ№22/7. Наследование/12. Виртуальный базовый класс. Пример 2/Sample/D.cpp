#include "D.h"

#include <iostream>

using namespace std;

D::D() : m_fieldD(0)
{
    cout << "Default constructor D" << endl;
}

D::D(const int valueA, const int valueC, const int valueD) : A(valueA, valueC), m_fieldD(valueD)
{
    cout << "Constructor D" << endl;
}

D::~D()
{
    cout << "Destructor D" << endl;
}