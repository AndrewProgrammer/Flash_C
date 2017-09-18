#include "Base.h"
#include "Derived.h"

int main()
{
    Derived obj1("Hello ", "world");

    Derived obj2 = obj1;
    Derived obj3 = obj2;

    obj1.Show();
    obj2.Show();
    obj3.Show();

    Base* ptr = new Derived("Virtual ", "destructor");
    ptr->Show();

    delete ptr;

    return 0;
}