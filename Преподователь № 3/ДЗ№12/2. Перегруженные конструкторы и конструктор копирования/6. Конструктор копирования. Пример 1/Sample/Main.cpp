#include <iostream>

#include "Foo.h"

using namespace std;

void Function1(Foo obj)
{
    cout << obj.GetValue() << endl;
}

Foo Function2()
{
    Foo obj(3);

    return obj;
}

int main()
{
    Foo obj1(1);
    Foo obj2(2);
    Foo obj3 = obj1;

    cout << obj3.GetValue() << endl;

    Function1(obj2);

    cout << Function2().GetValue() << endl;

    return 0;
}