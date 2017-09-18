#include "Date.h"

int main()
{
    Date date1;
    date1.Show();

    Date date2(2000U, 11U, 19U);
    date2.Show();

    Date date3(1998U, 10U);
    date3.Show();

    Date date4(1999U);
    date4.Show();

    return 0;
}