#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo() : m_floatingValue(1.3), m_integerValue(0)
{
}

double Foo::GetMutableValue() const
{
    ++m_floatingValue;

    return m_floatingValue;
}

int Foo::GetValue() const
{
    return m_integerValue;
}

void Foo::SetValue(const int value)
{
    m_integerValue = value;
}

void Foo::Show() const
{
    cout << "m_integerValue = " << m_integerValue << endl;
}