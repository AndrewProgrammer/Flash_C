#include <ctime>
#include <iostream>

#include "Foo.h"

using namespace std;

int main()
{
    srand((unsigned int)time(nullptr));

    const int size1 = 5;
    Foo ar1[size1];

    cout << "Array1:" << endl;

    for (int i = 0; i < size1; ++i)
    {
        ar1[i].SetValue(rand() % 50);

        cout << ar1[i].GetValue() << '\t';
    }

    const int size2 = 5;
    Foo ar2[size2] = { 1, 2, 3, 4, 5 };

    cout << endl << endl << "Array2:" << endl;

    for (int i = 0; i < size2; ++i)
    {
        cout << ar2[i].GetValue() << '\t';
    }

    const int size3 = 3;
    Foo ar3[size3] = { Foo(1, 2), Foo(3, 4), Foo(5, 6) };

    cout << endl << endl << "Array3:" << endl;

    for (int i = 0; i < size3; ++i)
    {
        cout << ar3[i].GetValue() << '\t';
    }
    cout << endl;

    Foo obj(10);
    Foo* objPointer = &obj;
    cout << endl << objPointer->GetValue();

    Foo* pointer1 = new Foo;
    cout << endl << pointer1->GetValue();

    pointer1->SetValue(200);
    cout << endl << pointer1->GetValue();

    delete pointer1;

    cout << endl << endl << "Dynamic array:" << endl;

    int size4 = 5;
    Foo* pointer2 = new Foo[size4];

    for (int i = 0; i < size4; ++i)
    {
        pointer2[i].SetValue(rand() % 50);

        cout << pointer2[i].GetValue() << '\t';
    }
    cout << endl;

    delete[] pointer2;

    return 0;
}