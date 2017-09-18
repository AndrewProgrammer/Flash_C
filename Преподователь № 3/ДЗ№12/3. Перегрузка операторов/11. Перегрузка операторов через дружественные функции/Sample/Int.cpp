#include "Int.h"

#include <iostream>

using namespace std;

Int::Int() : m_data(0)
{
}

Int::Int(const int data) : m_data(data)
{
}

void Int::Show()
{
    cout << m_data << endl;
}

Int operator+(const Int& left, const Int& right)
{
    return left.m_data + right.m_data;
}

Int operator-(const Int& left, const Int& right)
{
    return left.m_data - right.m_data;
}