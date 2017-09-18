#include <iostream>

#include "Foo.h"

using namespace std;

int main()
{
    Foo obj1 = 5;
    Foo obj2 = 3;
    Foo obj3 = obj1 + obj2;

    obj3.Show();

    obj3 = obj1 + 10;

    obj3.Show();

    obj3 = 20 + obj1;

    obj3.Show();

    return 0;
}