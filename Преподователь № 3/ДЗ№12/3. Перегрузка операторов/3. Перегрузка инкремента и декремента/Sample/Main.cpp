#include "Int.h"

int main()
{
    Int a = 3;
    Int b = 5;

    Int c = a + b++;
    c.Show();
    b.Show();

    c = ++a + b;
    c.Show();
    a.Show();

    c = a + b--;
    c.Show();
    b.Show();

    c = --a + b;
    c.Show();
    a.Show();

    return 0;
}