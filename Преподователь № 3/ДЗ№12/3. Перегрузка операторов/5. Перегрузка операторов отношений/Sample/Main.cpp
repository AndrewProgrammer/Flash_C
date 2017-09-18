#include <iostream>

#include "Integer.h"

using namespace std;

int main()
{
    Integer a(40);
    Integer b(20);
    Integer c(10);
    Integer d(20);

    if (b == d)
    {
        cout << "B == D" << endl;
    }

    if (a != b)
    {
        cout << "A != B" << endl;
    }

    if (a >= d)
    {
        cout << "A >= D" << endl;
    }

    if (c < b)
    {
        cout << "C < B" << endl;
    }

    if (d <= b)
    {
        cout << "D <= B" << endl;
    }

    if (a > b)
    {
        cout << "A > B" << endl;
    }

    return 0;
}