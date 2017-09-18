#include "Int.h"

#include <iostream>

using namespace std;

Int::Int() : m_number(0)
{
}

Int::Int(const int number) : m_number(number)
{
}

Int Int::operator*(const Int& number) const
{
    return m_number * number.m_number;
}

Int Int::operator/(const Int& number) const
{
    return m_number / number.m_number;
}

Int Int::operator+(const Int& number) const
{
    return m_number + number.m_number;
}

Int Int::operator-(const Int& number) const
{
    return m_number - number.m_number;
}

void Int::Show() const
{
    cout << m_number << endl;
}