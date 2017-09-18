#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo(const int data) : m_data(data)
{
}

/*Foo Foo::operator+(Foo obj) const
{
    return m_data + obj.GetData();
}*/

int Foo::GetData() const
{
    return m_data;
}

void Foo::Show()
{
    cout << m_data << endl;
}

Foo operator+(const Foo obj1, const Foo obj2)
{
    return obj1.GetData() + obj2.GetData();
}