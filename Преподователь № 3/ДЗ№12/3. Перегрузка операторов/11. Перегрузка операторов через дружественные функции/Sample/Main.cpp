#include "Int.h"

int main()
{
    Int obj1 = 2;
    Int obj2 = 4;
    Int obj3;

    obj3 = obj1 + obj2;
    //obj3 = obj1.operator+(obj2);

    obj3.Show();

    obj3 = 100 + obj2;
    //obj3 = operator+(100, obj2);

    obj3.Show();

    obj3 = obj2 - 10;

    obj3.Show();

    return 0;
}