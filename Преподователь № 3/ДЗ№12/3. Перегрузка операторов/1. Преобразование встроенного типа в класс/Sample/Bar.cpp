#include "Bar.h"

#include <iostream>

using namespace std;

Bar::Bar(const int data) : m_data(data)
{
}

void Bar::Show() const
{
    cout << "m_data = " << m_data << endl;
}