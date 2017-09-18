#include <iostream>

#include "Bar.h"
#include "Foo.h"
#include "FooBar.h"

using namespace std;

int main()
{
    Foo obj1(5);
    obj1.Show();
    cout << endl;

    Bar obj2(10, 20);
    obj2.Show();
    cout << endl;

    FooBar obj3(12, 22.456, 's');
    obj3.Show();
    cout << endl;

    return 0;
}