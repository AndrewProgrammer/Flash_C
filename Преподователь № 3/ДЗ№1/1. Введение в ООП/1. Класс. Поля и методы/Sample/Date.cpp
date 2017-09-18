#include "Date.h"

#include <iostream>

using namespace std;

void Date::Initialize()
{
    cout << "Enter year: ";
    cin >> m_year;

    cout << "Enter month: ";
    cin >> m_month;

    cout << "Enter day: ";
    cin >> m_day;
}

void Date::Show()
{
    cout << m_year << "." << m_month << "." << m_day << endl;
}