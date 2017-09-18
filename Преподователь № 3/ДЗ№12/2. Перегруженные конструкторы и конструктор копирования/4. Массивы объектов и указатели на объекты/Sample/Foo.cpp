#include "Foo.h"

Foo::Foo() : m_value(0)
{
}

Foo::Foo(const int value) : m_value(value)
{
}

Foo::Foo(const int value1, const int value2) : m_value(value1 + value2)
{
}

int Foo::GetValue()
{
    return m_value;
}

void Foo::SetValue(const int value)
{
    m_value = value;
}