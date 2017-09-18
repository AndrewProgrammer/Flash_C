#include "Foo.h"

Foo obj1(1);
Foo obj2(2);

void Function()
{
    Foo obj3(3);
    static Foo obj4(4);
}

int main()
{
    Foo* obj5 = new Foo(5);

    Foo obj6(6);
    Foo obj7(7);

    Function();

    delete obj5;

    return 0;
}