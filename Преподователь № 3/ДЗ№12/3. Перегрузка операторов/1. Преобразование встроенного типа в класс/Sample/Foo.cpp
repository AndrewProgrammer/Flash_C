#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo(const int data) : m_data(data)
{
}

void Foo::Show() const
{
    cout << "m_data = " << m_data << endl;
}