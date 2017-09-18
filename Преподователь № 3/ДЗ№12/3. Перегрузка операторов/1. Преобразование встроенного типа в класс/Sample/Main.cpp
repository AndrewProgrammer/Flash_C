#include <iostream>

#include "Bar.h"
#include "Foo.h"

using namespace std;

int main()
{
    Foo obj1(10);
    obj1.Show();

    Foo obj2 = 100;
    obj2.Show();

    Foo obj3 = (Foo)1000;
    obj3.Show();

    cout << endl;

    Bar obj4(10);
    obj4.Show();

    // Ошибка на этапе компиляции, потому что конструктор класс объявлен как explicit.
    //Bar obj5 = 100;
    //obj5.Show();

    Bar obj6 = (Bar)1000;
    obj6.Show();

    return 0;
}