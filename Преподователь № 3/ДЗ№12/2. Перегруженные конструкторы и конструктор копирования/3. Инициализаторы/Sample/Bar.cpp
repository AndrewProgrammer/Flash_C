#include "Bar.h"

#include <iostream>

using namespace std;

Bar::Bar(const int value, const int fooData) : m_obj(fooData), m_value(value)
{
}

void Bar::Show()
{
    cout << "Bar::m_value = " << m_value << endl;

    m_obj.Show();
}