#include "Integer.h"

Integer::Integer() : m_number(0)
{
}

Integer::Integer(const int number) : m_number(number)
{
}

bool Integer::operator==(const Integer& right) const
{
    return m_number == right.m_number;
}

bool Integer::operator!=(const Integer& right) const
{
    return m_number != right.m_number;
}

bool Integer::operator>(const Integer& right) const
{
    return m_number > right.m_number;
}

bool Integer::operator<(const Integer& right) const
{
    return m_number < right.m_number;
}

bool Integer::operator>=(const Integer& right) const
{
    return m_number >= right.m_number;
}

bool Integer::operator<=(const Integer& right) const
{
    return m_number <= right.m_number;
}

int Integer::GetValue() const
{
    return m_number;
}

void Integer::SetValue(const int number)
{
    m_number = number;
}