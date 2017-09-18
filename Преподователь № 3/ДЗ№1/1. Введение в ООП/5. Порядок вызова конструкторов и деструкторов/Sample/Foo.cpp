#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo(const int value)
{
    m_value = value;

    cout << "Constructor " << m_value << endl;
}

Foo::~Foo()
{
    cout << "Destructor " << m_value << endl;
}

int Foo::GetValue()
{
    return m_value;
}