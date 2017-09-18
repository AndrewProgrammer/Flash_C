#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo() : m_value(0)
{
}

int Foo::GetValue() const
{
    return m_value;
}

void Foo::SetValue(const int value)
{
    m_value = value;
}

void Foo::Show() const
{
    cout << "m_value = " << m_value << endl;
}