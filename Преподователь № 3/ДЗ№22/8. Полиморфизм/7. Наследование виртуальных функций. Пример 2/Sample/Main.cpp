#include <iostream>

#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"

int main()
{
    Base* ptr = nullptr;

    Base obj1;
    Derived1 obj2;
    Derived2 obj3;

    ptr = &obj1;
    ptr->WhoIsThis();

    ptr = &obj2;
    ptr->WhoIsThis();

    ptr = &obj3;
    ptr->WhoIsThis();

    return 0;
}