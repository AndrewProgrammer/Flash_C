#include <iostream>

#include "Foo.h"
#include "Vector.h"

using namespace std;

unsigned int Foo<int, double>::s_count = 0U;
unsigned int Foo<char, char*>::s_count = 0U;

int main()
{
    Foo<int, double> obj1(10, 2.5);
    Foo<char, char*> obj2('T', "Template");

    obj1.Show();
    obj2.Show();

    cout << Foo<int, double>::s_count << endl;
    cout << Foo<char, char*>::s_count << endl;

    Vector<int> vector1(5U);

    vector1.Fill();
    vector1.Show();

    Vector<double> vector2(5U);

    vector2.Fill();
    vector2.Show();

    Vector<int> vector3;
    Vector<double> vector4 = vector2;

    //vector3 = vector1;

    vector3.Show();
    vector4.Show();
}