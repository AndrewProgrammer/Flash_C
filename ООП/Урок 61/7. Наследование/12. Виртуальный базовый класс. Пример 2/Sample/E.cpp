#include "E.h"

#include <iostream>

using namespace std;

E::E() : m_fieldE(0)
{
    cout << "Default constructor E" << endl;
}

E::E(const int valueA, const int valueCD, const int valueD, const int valueB, const int valueCF, const int valueE, const int valueF) : D(valueA, valueCD, valueD), F(valueB, valueCF, valueF), m_fieldE(valueE)
{
    cout << "Constructor E" << endl;
}

E::~E()
{
    cout << "Destructor E" << endl;
}