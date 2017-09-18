#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo(const int value) : m_pointer(new int(value))
{
    cout << "Constructor" << endl;
}

Foo::Foo(const Foo& source) : m_pointer(new int())
{
    cout << "Copy constructor" << endl;

    *m_pointer = *source.m_pointer;
}

Foo::~Foo()
{
    cout << "Destructor" << endl;

    delete m_pointer;
}

int Foo::GetValue()
{
    return *m_pointer;
}