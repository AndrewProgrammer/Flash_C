#include "Sum.h"

int Sum::operator()(const int first, const int second)
{
    m_first = first;
    m_second = second;

    return m_first + m_second;
}

int Sum::GetFirst() const
{
    return m_first;
}

int Sum::GetSecond() const
{
    return m_second;
}