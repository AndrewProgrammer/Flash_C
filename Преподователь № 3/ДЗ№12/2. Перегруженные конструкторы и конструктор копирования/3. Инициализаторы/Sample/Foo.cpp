#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo(const int data) : m_data(data), m_const(100.0), m_reference(m_data)
{
}

void Foo::Show()
{
    cout << "Foo::m_data = " << m_data << endl;
    cout << "Foo::m_const = " << m_const << endl;
    cout << "Foo::m_reference = " << m_reference << endl;
}