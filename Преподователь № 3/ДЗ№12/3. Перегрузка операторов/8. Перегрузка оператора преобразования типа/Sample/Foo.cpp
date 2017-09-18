#include "Foo.h"

Foo::Foo(const int data) : m_data(data)
{
}

Foo::operator int() const
{
    return m_data;
}