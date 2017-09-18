#include "Int.h"

#include <iostream>

using namespace std;

Int::Int() : m_number(0)
{
}

Int::Int(const int number) : m_number(number)
{
}

Int& Int::operator++()
{
    ++m_number;

    return *this;
}

Int& Int::operator--()
{
    --m_number;

    return *this;
}

Int Int::operator+(const Int& number) const
{
    return m_number + number.m_number;
}

Int Int::operator++(int)
{
    // Если не реализован постфиксный инкремент то, тогда оператор++() отрабатывает как префиксный для обеих форм записи.
    Int temp = *this;

    ++m_number;

    return temp;
}

Int Int::operator--(int)
{
    // Если не реализован постфиксный декремент то, тогда оператор--() отрабатывает как префиксный для обеих форм записи.
    Int temp = *this;

    --m_number;

    return temp;
}

void Int::Show() const
{
    cout << m_number << endl;
}