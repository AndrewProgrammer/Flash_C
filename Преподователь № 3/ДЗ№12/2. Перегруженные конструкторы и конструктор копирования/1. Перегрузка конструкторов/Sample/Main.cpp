#include "Date.h"

int main()
{
    // Вызов конструктора Date(const unsigned int year).
    Date date1(1999U);
    date1.Show();

    // Вызов конструктора Date(const unsigned int year, const unsigned int month).
    Date date2(2004U, 8U);
    date2.Show();

    // Вызов конструктора Date(const unsigned int year, const unsigned int month, const unsigned int day).
    Date date3(2008U, 11U, 20U);
    date3.Show();

    // Вызов конструктора по умолчанию.
    Date date4;
    date4.Show();

    return 0;
}