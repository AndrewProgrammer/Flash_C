#include "Date.h"

#include <iostream>

using namespace std;

Date::Date()
{
    m_day = 31U;
    m_month = 12U;
    m_year = 2010U;
}

Date::Date(const unsigned int year)
{
    m_day = 31U;
    m_month = 12U;
    m_year = year;
}

Date::Date(const unsigned int year, const unsigned int month)
{
    m_day = 31U;
    m_month = month;
    m_year = year;
}

Date::Date(const unsigned int year, const unsigned int month, const unsigned int day)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

void Date::Show()
{
    cout << m_year << "." << m_month << "." << m_day << endl;
}