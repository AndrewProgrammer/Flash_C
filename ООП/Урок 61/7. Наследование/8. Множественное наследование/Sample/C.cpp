#include "C.h"

#include <iostream>

using namespace std;

C::C(const int valueA, const int valueB, const int valueC) : A(valueA), B(valueB), m_fieldC(valueC)
{
    cout << "Constructor C" << endl;
}

C::~C()
{
    cout << "Destructor C" << endl;
}

void C::ShowC() const
{
    cout << m_fieldC << endl;
}