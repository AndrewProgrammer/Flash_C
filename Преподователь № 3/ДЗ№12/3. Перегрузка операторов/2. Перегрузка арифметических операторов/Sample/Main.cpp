#include "Int.h"

int main()
{
    Int a = 5;
    Int b = 3;
    Int c = 10;

    Int d = a + b + c - b - c - a + b;
    Int e = a * b / b;

    d.Show();
    e.Show();

    return 0;
}