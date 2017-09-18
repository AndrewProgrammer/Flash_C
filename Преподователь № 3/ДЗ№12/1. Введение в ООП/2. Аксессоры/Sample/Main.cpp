#include <iostream>

#include "Date.h"

using namespace std;

int main()
{
    Date date;
    date.Initialize(2005U, 11U, 30U);
    date.Show();

    unsigned int day = date.GetDay();
    unsigned int year = date.GetYear();

    cout << "Day: " << day << endl;
    cout << "Year: " << year << endl;

    date.SetYear(2006U);
    date.SetMonth(8U);
    date.Show();

    return 0;
}