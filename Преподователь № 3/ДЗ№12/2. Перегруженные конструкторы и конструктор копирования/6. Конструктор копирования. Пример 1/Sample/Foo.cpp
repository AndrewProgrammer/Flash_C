#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo(const int value) : m_value(value)
{
    cout << "Constructor" << endl;
}

Foo::~Foo()
{
    cout << "Destructor" << endl;
}

int Foo::GetValue()
{
    return m_value;
}