#include "Derived.h"

#include <iostream>

using namespace std;

void Derived::DerivedMethod1() const
{
    cout << "Derived::DerivedMethod1" << endl;
}

void Derived::DerivedMethod2() const
{
    cout << "Derived::DerivedMethod2" << endl;
}