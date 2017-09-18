#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo() : m_data(0)
{
}

Foo::Foo(const int data) : m_data(data)
{
}

void* Foo::operator new(const size_t size)
{
    cout << "Foo::operator new" << endl;

    return malloc(size);
}

void Foo::operator delete(void* data)
{
    cout << "Foo::operator delete" << endl;

    free(data);
}

void* Foo::operator new[](const size_t size)
{
    cout << "Foo::operator new[]" << endl;

    return malloc(size);
}

void Foo::operator delete[](void* data)
{
    cout << "Foo::operator delete[]" << endl;

    free(data);
}

void Foo::Show()
{
    cout << m_data << endl;
}