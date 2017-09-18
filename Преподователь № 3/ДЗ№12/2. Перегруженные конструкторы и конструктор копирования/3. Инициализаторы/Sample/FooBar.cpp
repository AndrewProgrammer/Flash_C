#include "FooBar.h"

#include <iostream>

using namespace std;

FooBar::FooBar(const int integerValue, const double floatingValue, const char characterValue) : m_characterValue(characterValue), m_floatingValue(floatingValue), m_integerValue(integerValue)
{
}

void FooBar::Show()
{
    cout << "FooBar::m_characterValue = " << m_characterValue << endl;
    cout << "FooBar::m_floatingValue = " << m_floatingValue << endl;
    cout << "FooBar::m_integerValue = " << m_integerValue << endl;
}