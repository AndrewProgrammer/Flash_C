#include <iostream>

#include "Base1.h"
#include "Base2.h"
#include "Base3.h"
#include "Derived.h"

using namespace std;

typedef void(*Method)();//Псевдоним void(*[Название указателя на функции])()

int main()
{
    Derived obj;

    Method method = nullptr;

    // Size contains the _vptr of all it's base classes and Base class data and it's own Data. 3 vptr и 2 метода типа данных int( 3 vptr = 12 (Так как указатель имеет 4 байта), и int = 4 байта)
    cout << "Size of obj = " << sizeof(obj) << endl;

    // Calling 1st virtual function of Base1.
    method = (Method)*((int*)*((int*)&obj + 0) + 0);
    method();

    // Calling 2nd virtual function of Base1.
    method = (Method)*((int*)*((int*)&obj + 0) + 1);
    method();

    // Next location contains the Base1's data, lets change it and check the output.
    int* pointer = (int*)&obj + 1;
    *pointer = 30;

    cout << "Base1 class fields: m_fieldA = " << obj.m_fieldA << endl;

    // Calling 1st virtual function of Derived.
    method = (Method)*((int*)*((int*)&obj + 0) + 2);
    method();

    // Calling 2nd virtual function of Derived.
    method = (Method)*((int*)*((int*)&obj + 0) + 3);
    method();

    // Calling 1st virtual function of Base2.
    method = (Method)*((int*)*((int*)&obj + 2) + 0);
    method();

    // Calling 2nd virtual function of Base2.
    method = (Method)*((int*)*((int*)&obj + 2) + 1);
    method();

    // Calling 1st virtual function of Base3.
    method = (Method)*((int*)*((int*)&obj + 3) + 0);
    method();

    // Calling 2nd virtual function of Base3.
    method = (Method)*((int*)*((int*)&obj + 3) + 1);
    method();

    // At the end, it contains it's own data i.e. Derived classes data, lets change it and check the output.
    pointer = (int*)&obj + 4;
    *pointer = 100;

    cout << "Derived class fields: m_fieldB = " << obj.m_fieldB << endl;

    return 0;
}