#include "Base.h"
#include "Derived.h"

int main()
{
    Derived<int, double> obj1(10, 5.2);
    obj1.ShowBase();
    obj1.ShowDerived();

    Derived<char, char*> obj2('I', "Inheritance");
    obj2.ShowBase();
    obj2.ShowDerived();

    return 0;
}