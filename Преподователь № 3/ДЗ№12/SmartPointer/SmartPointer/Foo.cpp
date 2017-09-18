#include "Foo.h"

#include <iostream>

using namespace std;

Foo::Foo()
{
    cout << "Constructor" << endl;
}

Foo::~Foo()
{
    cout << "Destructor" << endl;
}