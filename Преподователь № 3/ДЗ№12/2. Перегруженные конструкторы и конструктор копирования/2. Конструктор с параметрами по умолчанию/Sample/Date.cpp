#include "Date.h"

#include <iostream>

using namespace std;

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