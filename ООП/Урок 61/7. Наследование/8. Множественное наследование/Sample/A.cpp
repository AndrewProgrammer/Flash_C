#include "A.h"

#include <iostream>

using namespace std;

A::A(const int valueA) : m_fieldA(valueA)
{
    cout << "Constructor A" << endl;
}

A::~A()
{
    cout << "Destructor A" << endl;
}

void A::ShowA() const
{
    cout << m_fieldA << endl;
}