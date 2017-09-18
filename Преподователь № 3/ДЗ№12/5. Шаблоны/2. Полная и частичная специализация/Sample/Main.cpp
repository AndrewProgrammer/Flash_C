#include <iostream>

#include "Foo.h"
#include "Maximum.h"

using namespace std;

int main()
{
    Foo<int> obj1(10);
    obj1.Show();

    Foo<char> obj2('A');
    obj2.Show();

    Foo<double> obj3(2.6);
    obj3.Show();

    Maximum<int, int> obj4(10, 20);
    cout << obj4.MaxValue() << endl << endl;

    Maximum<int, char> obj5(10, 'A');
    cout << obj5.MaxValue() << endl << endl;

    Maximum<char, int> obj6('A', 10);
    cout << obj6.MaxValue() << endl << endl;

    Maximum<double, int> obj7(5.7, 2);
    cout << obj7.MaxValue() << endl << endl;

    Maximum<char*, char*> obj8("typename", "class");
    cout << obj8.MaxValue() << endl << endl;

    return 0;
}