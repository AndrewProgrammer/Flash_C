#include "C.h"

#include <iostream>

using namespace std;

C::C() : m_fieldC(0)
{
    cout << "Default constructor C" << endl;
}

C::C(const int valueC) : m_fieldC(valueC)
{
    cout << "Constructor C" << endl;
}

C::~C()
{
    cout << "Destructor C" << endl;
}