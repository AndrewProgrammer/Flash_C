#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo(const int data) : m_data(data)
{
}

void FriendFunction(Foo& obj)
{
    cout << obj.m_data << endl;

    obj.m_data += 10;

    cout << obj.m_data << endl;
}