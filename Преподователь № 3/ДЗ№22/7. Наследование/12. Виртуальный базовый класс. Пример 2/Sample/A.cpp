#include "A.h"

#include <iostream>

using namespace std;

A::A() : m_fieldA(0)
{
    cout << "Default constructor A" << endl;
}

A::A(const int valueA, const int valueC) : C(valueC), m_fieldA(valueA)
{
    cout << "Constructor A" << endl;
}

A::~A()
{
    cout << "Destructor A" << endl;
}