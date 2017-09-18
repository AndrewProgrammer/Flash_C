#include "Date.h"

#include <iostream>

using namespace std;

unsigned int Date::GetDay()
{
    return m_day;
}

unsigned int Date::GetYear()
{
    return m_year;
}

void Date::Initialize(const unsigned int year, const unsigned int month, const unsigned int day)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

void Date::SetMonth(const unsigned int month)
{
    m_month = month;
}

void Date::SetYear(const unsigned int year)
{
    m_year = year;
}

void Date::Show()
{
    cout << m_year << "." << m_month << "." << m_day << endl;
}