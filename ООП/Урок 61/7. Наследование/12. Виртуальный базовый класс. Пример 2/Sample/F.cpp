#include "F.h"

#include <iostream>

using namespace std;

F::F() : m_fieldF(0)
{
    cout << "Default constructor F" << endl;
}

F::F(const int valueB, const int valueC, const int valueF) : B(valueB, valueC), m_fieldF(valueF)
{
    cout << "Constructor F" << endl;
}

F::~F()
{
    cout << "Destructor F" << endl;
}